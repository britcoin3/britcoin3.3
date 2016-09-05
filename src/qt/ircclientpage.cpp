#include "ircclientpage.h"
#include "ircmessageformatter.h"
#include "ui_ircclientpage.h"
#include "main.h"
#include "wallet.h"
#include "init.h"
#include "base58.h"
#include "clientmodel.h"
#include "bitcoinrpc.h"
#include <sstream>
#include <string>
#include <C:/deps/libcommuni-3.2.0/include/IrcCore/irc.h> // <--- Change this.
#include <IrcUser>
#include <IrcBuffer>
#include <IrcCommand>
#include <IrcMessage>
#include <IrcUserModel>
#include <IrcCompleter>
#include <IrcConnection>
#include <IrcBufferModel>
#include <IrcCommandParser>
#include <QScrollBar>

static const char* CHAN = "#britcoinUK";
static const char* SERVER = "irc.freenode.net";

using namespace json_spirit;


IrcClientPage::IrcClientPage(QWidget *parent) : QSplitter(parent),
    ui(new Ui::IrcClientPage)
{
    ui->setupUi(this);
    createLayout();

    ui->textEdit->append(IrcMessageFormatter::formatMessage(tr("! Available commands: JOIN, ME, NICK, PART")));

    }

    void IrcClientPage::onConnected()
    {
        ui->textEdit->append(IrcMessageFormatter::formatMessage("! Connected to %1.").arg(SERVER));
        ui->textEdit->append(IrcMessageFormatter::formatMessage("! Joining %1...").arg(CHAN));
    }

    void IrcClientPage::onConnecting()
    {
        ui->textEdit->append(IrcMessageFormatter::formatMessage("! Connecting %1...").arg(SERVER));
    }

    void IrcClientPage::onDisconnected()
    {
        ui->textEdit->append(IrcMessageFormatter::formatMessage("! Disconnected from %1.").arg(SERVER));
    }

    void IrcClientPage::onTextEdited()
    {
        // clear the possible error indication
        ui->lineEdit->setStyleSheet(QString());
    }

    void IrcClientPage::onTextEntered()
    {
        QString input = ui->lineEdit->text();
        IrcCommand* command = parser->parse(input);
        if (command) {
            connection->sendCommand(command);

            // echo own messages (servers do not send our own messages back)
            if (command->type() == IrcCommand::Message || command->type() == IrcCommand::CtcpAction) {
                IrcMessage* msg = command->toMessage(connection->nickName(), connection);
                receiveMessage(msg);
                delete msg;
            }

            ui->lineEdit->clear();

        } else if (input.length() > 1) {
            QString error;
            QString command = ui->lineEdit->text().mid(1).split(" ", QString::SkipEmptyParts).value(0).toUpper();
            if (parser->commands().contains(command))
                error = tr("[ERROR] Syntax: %1").arg(parser->syntax(command).replace("<", "&lt;").replace(">", "&gt;"));
            else
                error = tr("[ERROR] Unknown command: %1").arg(command);
            ui->textEdit->append(IrcMessageFormatter::formatMessage(error));
            ui->lineEdit->setStyleSheet("background: salmon");
        }
    }

    void IrcClientPage::onCompletion()
    {
        completer->complete(ui->lineEdit->text(), ui->lineEdit->cursorPosition());
    }

    void IrcClientPage::onCompleted(const QString& text, int cursor)
    {
        ui->lineEdit->setText(text);
        ui->lineEdit->setCursorPosition(cursor);
    }

    void IrcClientPage::onBufferAdded(IrcBuffer* buffer)
    {
        // joined a buffer - start listening to buffer specific messages
        connect(buffer, SIGNAL(messageReceived(IrcMessage*)), this, SLOT(receiveMessage(IrcMessage*)));

        // create a document for storing the buffer specific messages
        QTextDocument* document = new QTextDocument(buffer);
        documents.insert(buffer, document);

        // create a sorted model for buffer users
        IrcUserModel* userModel = new IrcUserModel(buffer);
        userModel->setSortMethod(Irc::SortByTitle);
        userModels.insert(buffer, userModel);

        // activate the new buffer
        int idx = bufferModel->buffers().indexOf(buffer);
        if (idx != -1)
            ui->bufferList->setCurrentIndex(bufferModel->index(idx));
    }

    void IrcClientPage::onBufferRemoved(IrcBuffer* buffer)
    {
        // the buffer specific models and documents are no longer needed
        delete userModels.take(buffer);
        delete documents.take(buffer);
    }

    void IrcClientPage::onBufferActivated(const QModelIndex& index)
    {
        IrcBuffer* buffer = index.data(Irc::BufferRole).value<IrcBuffer*>();

        // document, user list and nick completion for the current buffer
        ui->textEdit->setDocument(documents.value(buffer));
        ui->textEdit->verticalScrollBar()->triggerAction(QScrollBar::SliderToMaximum);
        ui->userList->setModel(userModels.value(buffer));
        completer->setBuffer(buffer);

        // keep the command parser aware of the context
        if (buffer)
            parser->setTarget(buffer->title());
    }

    void IrcClientPage::onUserActivated(const QModelIndex& index)
    {
        IrcUser* user = index.data(Irc::UserRole).value<IrcUser*>();

        if (user) {
            IrcBuffer* buffer = bufferModel->add(user->name());

            // activate the new query
            int idx = bufferModel->buffers().indexOf(buffer);
            if (idx != -1)
                ui->bufferList->setCurrentIndex(bufferModel->index(idx));
        }
    }

    static void appendHtml(QTextDocument* document, const QString& html)
    {
        QTextCursor cursor(document);
        cursor.beginEditBlock();
        cursor.movePosition(QTextCursor::End);
        if (!document->isEmpty())
            cursor.insertBlock();
        cursor.insertHtml(html);
        cursor.endEditBlock();
    }

    void IrcClientPage::receiveMessage(IrcMessage* message)
    {
        IrcBuffer* buffer = qobject_cast<IrcBuffer*>(sender());
        if (!buffer)
            buffer = ui->bufferList->currentIndex().data(Irc::BufferRole).value<IrcBuffer*>();

        QTextDocument* document = documents.value(buffer);
        if (document) {
            QString html = IrcMessageFormatter::formatMessage(message);
            if (!html.isEmpty())
               if (document == ui->textEdit->document())
                   ui->textEdit->append(html);
            else
                   appendHtml(document, html);
        }
    }

    void IrcClientPage::createLayout()
    {
            ui->textEdit->setReadOnly(true);
            ui->lineEdit->setAttribute(Qt::WA_MacShowFocusRect, false);
            ui->textEdit->setFocusProxy(ui->lineEdit);

            connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(onTextEntered()));
            connect(ui->lineEdit, SIGNAL(textEdited(QString)), this, SLOT(onTextEdited()));
            connect(ui->connectButton, SIGNAL(pressed()), this, SLOT(Bconnection()));
            connect(ui->dconnectButton, SIGNAL(pressed()), this, SLOT(dropConnection()));
    }

    void IrcClientPage::createCompleter()
    {
        // nick name completion
        completer = new IrcCompleter(this);
        completer->setParser(parser);
        connect(completer, SIGNAL(completed(QString,int)), this, SLOT(onCompleted(QString,int)));
    }

    void IrcClientPage::createParser()
    {
        // create a command parser and teach it some commands. notice also
        // that we must keep the command parser aware of the context in
        // createUi() and onBufferActivated()
        parser = new IrcCommandParser(this);
        parser->setTolerant(true);
        parser->setTriggers(QStringList("/"));
        parser->addCommand(IrcCommand::Join, "JOIN <#channel> (<key>)");
        parser->addCommand(IrcCommand::CtcpAction, "ME [target] <message...>");
        parser->addCommand(IrcCommand::Mode, "MODE (<channel/user>) (<mode>) (<arg>)");
        parser->addCommand(IrcCommand::Nick, "NICK <nick>");
        parser->addCommand(IrcCommand::Part, "PART (<#channel>) (<message...>)");
    }

    void IrcClientPage::createUserList()
    {
        ui->userList->setFocusPolicy(Qt::NoFocus);

        // open a private query when double clicking a user
        connect(ui->userList, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onUserActivated(QModelIndex)));
    }

    void IrcClientPage::createBufferList()
    {
        bufferModel = new IrcBufferModel(connection);
        connect(bufferModel, SIGNAL(added(IrcBuffer*)), this, SLOT(onBufferAdded(IrcBuffer*)));
        connect(bufferModel, SIGNAL(removed(IrcBuffer*)), this, SLOT(onBufferRemoved(IrcBuffer*)));

        ui->bufferList->setFocusPolicy(Qt::NoFocus);
        ui->bufferList->setModel(bufferModel);

        // keep the command parser aware of the context
        connect(bufferModel, SIGNAL(channelsChanged(QStringList)), parser, SLOT(setChannels(QStringList)));

        // keep track of the current buffer, see also onBufferActivated()
        connect(ui->bufferList->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(onBufferActivated(QModelIndex)));

        // create a server buffer for non-targeted messages...
        IrcBuffer* serverBuffer = bufferModel->add(connection->host());

        // ...and connect it to IrcBufferModel::messageIgnored()
        connect(bufferModel, SIGNAL(messageIgnored(IrcMessage*)), serverBuffer, SLOT(receiveMessage(IrcMessage*)));

    }

    void IrcClientPage::createConnection()
    {
        connection = new IrcConnection(this);
        connect(connection, SIGNAL(connected()), this, SLOT(onConnected()));
        connect(connection, SIGNAL(connecting()), this, SLOT(onConnecting()));
        connect(connection, SIGNAL(disconnected()), this, SLOT(onDisconnected()));

        qsrand(QTime::currentTime().msec());

        connection->setHost(SERVER);
        connection->setUserName("Britcoin");
        connection->setNickName(tr("Brit%1").arg(qrand() % 9999));
        connection->setRealName(tr("Britcoin IRC client"));
        connection->sendCommand(IrcCommand::createJoin(CHAN));
        connection->open();

    }

    void IrcClientPage::Bconnection()
    {
        createParser();
        createConnection();
        createCompleter();
        createUserList();
        createBufferList();
    }


    void IrcClientPage::dropConnection()
    {
        if (connection->isActive()) {
            connection->quit(connection->realName());
            connection->close();
        }
    }

    void IrcClientPage::setModel(ClientModel *model)
    {

    this->model = model;
    }

IrcClientPage::~IrcClientPage()
{

    if (connection->isActive()) {
        connection->quit(connection->realName());
        connection->close();
    }
}


