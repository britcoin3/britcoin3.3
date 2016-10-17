/********************************************************************************
** Form generated from reading UI file 'statisticspage.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSPAGE_H
#define UI_STATISTICSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsPage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *gridFrame_2;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *minBox;
    QLabel *maxBox;
    QLabel *label_15;
    QLabel *label_14;
    QLabel *heightBox;
    QLabel *label1_2;
    QLabel *connectionBox;
    QLabel *label_9;
    QLabel *diffBox2;
    QLabel *label_11;
    QLabel *localBox;
    QLabel *cBox;
    QLabel *volumeBox;
    QLabel *label3_2;
    QPushButton *startButton;

    void setupUi(QWidget *StatisticsPage)
    {
        if (StatisticsPage->objectName().isEmpty())
            StatisticsPage->setObjectName(QStringLiteral("StatisticsPage"));
        StatisticsPage->resize(953, 488);
        verticalLayout = new QVBoxLayout(StatisticsPage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridFrame_2 = new QFrame(StatisticsPage);
        gridFrame_2->setObjectName(QStringLiteral("gridFrame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gridFrame_2->sizePolicy().hasHeightForWidth());
        gridFrame_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Sans Serif"));
        gridFrame_2->setFont(font);
        gridFrame_2->setAutoFillBackground(false);
        gridFrame_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        gridFrame_2->setFrameShape(QFrame::StyledPanel);
        gridFrame_2->setLineWidth(1);
        gridLayout = new QGridLayout(gridFrame_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, -1, -1);
        label_8 = new QLabel(gridFrame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);
        label_8->setMargin(1);

        gridLayout->addWidget(label_8, 4, 0, 1, 1, Qt::AlignLeft);

        label_10 = new QLabel(gridFrame_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setMargin(1);

        gridLayout->addWidget(label_10, 5, 0, 1, 1, Qt::AlignLeft);

        minBox = new QLabel(gridFrame_2);
        minBox->setObjectName(QStringLiteral("minBox"));

        gridLayout->addWidget(minBox, 5, 1, 1, 1);

        maxBox = new QLabel(gridFrame_2);
        maxBox->setObjectName(QStringLiteral("maxBox"));

        gridLayout->addWidget(maxBox, 6, 1, 1, 1);

        label_15 = new QLabel(gridFrame_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_15->setMargin(1);

        gridLayout->addWidget(label_15, 7, 0, 1, 1, Qt::AlignLeft);

        label_14 = new QLabel(gridFrame_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setMargin(1);

        gridLayout->addWidget(label_14, 0, 0, 1, 1, Qt::AlignLeft);

        heightBox = new QLabel(gridFrame_2);
        heightBox->setObjectName(QStringLiteral("heightBox"));

        gridLayout->addWidget(heightBox, 0, 1, 1, 1);

        label1_2 = new QLabel(gridFrame_2);
        label1_2->setObjectName(QStringLiteral("label1_2"));
        label1_2->setAlignment(Qt::AlignCenter);
        label1_2->setMargin(1);

        gridLayout->addWidget(label1_2, 3, 0, 1, 1, Qt::AlignLeft);

        connectionBox = new QLabel(gridFrame_2);
        connectionBox->setObjectName(QStringLiteral("connectionBox"));

        gridLayout->addWidget(connectionBox, 3, 1, 1, 1);

        label_9 = new QLabel(gridFrame_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);
        label_9->setMargin(1);

        gridLayout->addWidget(label_9, 1, 0, 1, 1, Qt::AlignLeft);

        diffBox2 = new QLabel(gridFrame_2);
        diffBox2->setObjectName(QStringLiteral("diffBox2"));

        gridLayout->addWidget(diffBox2, 1, 1, 1, 1);

        label_11 = new QLabel(gridFrame_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setMargin(1);

        gridLayout->addWidget(label_11, 6, 0, 1, 1, Qt::AlignLeft);

        localBox = new QLabel(gridFrame_2);
        localBox->setObjectName(QStringLiteral("localBox"));

        gridLayout->addWidget(localBox, 2, 1, 1, 1);

        cBox = new QLabel(gridFrame_2);
        cBox->setObjectName(QStringLiteral("cBox"));

        gridLayout->addWidget(cBox, 7, 1, 1, 1);

        volumeBox = new QLabel(gridFrame_2);
        volumeBox->setObjectName(QStringLiteral("volumeBox"));

        gridLayout->addWidget(volumeBox, 4, 1, 1, 1);

        label3_2 = new QLabel(gridFrame_2);
        label3_2->setObjectName(QStringLiteral("label3_2"));
        label3_2->setAlignment(Qt::AlignCenter);
        label3_2->setMargin(1);

        gridLayout->addWidget(label3_2, 2, 0, 1, 1, Qt::AlignLeft);


        verticalLayout->addWidget(gridFrame_2);

        startButton = new QPushButton(StatisticsPage);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setMinimumSize(QSize(210, 30));
        startButton->setMaximumSize(QSize(210, 30));
        startButton->setDefault(true);
        startButton->setFlat(false);

        verticalLayout->addWidget(startButton, 0, Qt::AlignLeft);


        retranslateUi(StatisticsPage);

        QMetaObject::connectSlotsByName(StatisticsPage);
    } // setupUi

    void retranslateUi(QWidget *StatisticsPage)
    {
        StatisticsPage->setWindowTitle(QApplication::translate("StatisticsPage", "Address Book", 0));
        label_8->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p>Total Coin Volume</p></body></html>", 0));
        label_10->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p>Total stake weight</p></body></html>", 0));
        minBox->setText(QApplication::translate("StatisticsPage", "0", 0));
        maxBox->setText(QApplication::translate("StatisticsPage", "0", 0));
        label_15->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p>Mining Phase</p></body></html>", 0));
        label_14->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p>Block Height</p></body></html>", 0));
        heightBox->setText(QApplication::translate("StatisticsPage", "00000", 0));
        label1_2->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p>Connections</p></body></html>", 0));
        connectionBox->setText(QApplication::translate("StatisticsPage", "0", 0));
        label_9->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p>PoS difficulty</p></body></html>", 0));
        diffBox2->setText(QApplication::translate("StatisticsPage", "0.0002", 0));
        label_11->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p>Network stake weight</p></body></html>", 0));
        localBox->setText(QApplication::translate("StatisticsPage", "0 KH/s", 0));
        cBox->setText(QApplication::translate("StatisticsPage", "POW", 0));
        volumeBox->setText(QApplication::translate("StatisticsPage", "250", 0));
        label3_2->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p>Last block time</p></body></html>", 0));
        startButton->setText(QApplication::translate("StatisticsPage", "Update Statistics", 0));
    } // retranslateUi

};

namespace Ui {
    class StatisticsPage: public Ui_StatisticsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSPAGE_H
