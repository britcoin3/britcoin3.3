#ifndef IRCCLIENTPAGE_H
#define IRCCLIENTPAGE_H

#include "clientmodel.h"
#include "main.h"
#include "wallet.h"
#include "base58.h"

#include <QWidget>

#include <QDir>
#include <QFile>
#include <QProcess>
#include <QTime>
//#include <QTimer>
#include <QStringList>
#include <QMap>
#include <QSettings>
#include <QSlider>
#include <QSplitter>
#include <QHash>
#include <QNetworkProxy>

class IrcBuffer;
class IrcMessage;
class IrcUserModel;
class IrcCompleter;
class IrcConnection;
class IrcBufferModel;
class IrcCommandParser;

QT_FORWARD_DECLARE_CLASS(QLineEdit)
QT_FORWARD_DECLARE_CLASS(QListView)
QT_FORWARD_DECLARE_CLASS(QTextEdit)
QT_FORWARD_DECLARE_CLASS(QModelIndex)
QT_FORWARD_DECLARE_CLASS(QTextDocument)
QT_FORWARD_DECLARE_CLASS(QScrollBar)


namespace Ui {
class IrcClientPage;
}
class ClientModel;

class IrcClientPage : public QSplitter
{
    Q_OBJECT

public:
    explicit IrcClientPage(QWidget *parent = 0);
    ~IrcClientPage();
    
    void setModel(ClientModel *model);


public slots:
    void Bconnection();
    void dropConnection();

private slots:
    void onConnected();
    void onConnecting();
    void onDisconnected();

    void onTextEdited();
    void onTextEntered();

    void onCompletion();
    void onCompleted(const QString& text, int cursor);

    void onBufferAdded(IrcBuffer* buffer);
    void onBufferRemoved(IrcBuffer* buffer);

    void onBufferActivated(const QModelIndex& index);
    void onUserActivated(const QModelIndex& index);

    void receiveMessage(IrcMessage* message);


private:
    Ui::IrcClientPage *ui;
    ClientModel *model;

    void createLayout();
    void createCompleter();
    void createParser();
    void createUserList();
    void createBufferList();
    void createConnection();
    //void dropConnection();
    IrcCompleter* completer;
    IrcCommandParser* parser;
    IrcConnection* connection;
    IrcBufferModel* bufferModel;
    QHash<IrcBuffer*, IrcUserModel*> userModels;
    QHash<IrcBuffer*, QTextDocument*> documents;
    
};

#endif // IRCCLIENTPAGE_H
