/********************************************************************************
** Form generated from reading UI file 'sosgame.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOSGAME_H
#define UI_SOSGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SOSGame
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *player2ScoreLabel;
    QLabel *player2Score;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
    QRadioButton *player2_S;
    QRadioButton *player2_O;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *player1ScoreLabel;
    QLabel *player1Score;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QRadioButton *player1_S;
    QRadioButton *player1_O;
    QGridLayout *GameBoard;
    QTableWidget *SOSGameBoard;
    QHBoxLayout *horizontalLayout;
    QRadioButton *SimpleGameButton;
    QRadioButton *GeneralGameButton;
    QLabel *BoardSizeLabel;
    QSlider *BoardSizeSlider;
    QLabel *BoardSizeOutput;
    QPushButton *StartButton;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QStatusBar *statusbar;
    QButtonGroup *GameTypeButtonGroup;
    QButtonGroup *Player2MoveButtonGroup;
    QButtonGroup *Player1MoveButtonGroup;

    void setupUi(QMainWindow *SOSGame)
    {
        if (SOSGame->objectName().isEmpty())
            SOSGame->setObjectName("SOSGame");
        SOSGame->resize(675, 472);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SOSGame->sizePolicy().hasHeightForWidth());
        SOSGame->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(SOSGame);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setMinimumSize(QSize(675, 450));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        player2ScoreLabel = new QLabel(centralwidget);
        player2ScoreLabel->setObjectName("player2ScoreLabel");

        verticalLayout_2->addWidget(player2ScoreLabel);

        player2Score = new QLabel(centralwidget);
        player2Score->setObjectName("player2Score");
        player2Score->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(player2Score);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_4);

        player2_S = new QRadioButton(centralwidget);
        Player2MoveButtonGroup = new QButtonGroup(SOSGame);
        Player2MoveButtonGroup->setObjectName("Player2MoveButtonGroup");
        Player2MoveButtonGroup->addButton(player2_S);
        player2_S->setObjectName("player2_S");

        verticalLayout_2->addWidget(player2_S);

        player2_O = new QRadioButton(centralwidget);
        Player2MoveButtonGroup->addButton(player2_O);
        player2_O->setObjectName("player2_O");

        verticalLayout_2->addWidget(player2_O);


        gridLayout->addLayout(verticalLayout_2, 2, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        player1ScoreLabel = new QLabel(centralwidget);
        player1ScoreLabel->setObjectName("player1ScoreLabel");

        verticalLayout->addWidget(player1ScoreLabel);

        player1Score = new QLabel(centralwidget);
        player1Score->setObjectName("player1Score");
        player1Score->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(player1Score);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(label_3);

        player1_S = new QRadioButton(centralwidget);
        Player1MoveButtonGroup = new QButtonGroup(SOSGame);
        Player1MoveButtonGroup->setObjectName("Player1MoveButtonGroup");
        Player1MoveButtonGroup->addButton(player1_S);
        player1_S->setObjectName("player1_S");

        verticalLayout->addWidget(player1_S);

        player1_O = new QRadioButton(centralwidget);
        Player1MoveButtonGroup->addButton(player1_O);
        player1_O->setObjectName("player1_O");

        verticalLayout->addWidget(player1_O);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        GameBoard = new QGridLayout();
        GameBoard->setSpacing(0);
        GameBoard->setObjectName("GameBoard");
        GameBoard->setSizeConstraint(QLayout::SetNoConstraint);
        GameBoard->setContentsMargins(-1, -1, 0, -1);
        SOSGameBoard = new QTableWidget(centralwidget);
        SOSGameBoard->setObjectName("SOSGameBoard");
        sizePolicy.setHeightForWidth(SOSGameBoard->sizePolicy().hasHeightForWidth());
        SOSGameBoard->setSizePolicy(sizePolicy);
        SOSGameBoard->setMinimumSize(QSize(500, 500));
        SOSGameBoard->setSizeIncrement(QSize(0, 0));
        SOSGameBoard->setBaseSize(QSize(500, 500));
        SOSGameBoard->setLayoutDirection(Qt::LeftToRight);
        SOSGameBoard->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        SOSGameBoard->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        SOSGameBoard->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        SOSGameBoard->horizontalHeader()->setVisible(false);
        SOSGameBoard->horizontalHeader()->setCascadingSectionResizes(false);
        SOSGameBoard->verticalHeader()->setVisible(false);
        SOSGameBoard->verticalHeader()->setCascadingSectionResizes(false);

        GameBoard->addWidget(SOSGameBoard, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        gridLayout->addLayout(GameBoard, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        SimpleGameButton = new QRadioButton(centralwidget);
        GameTypeButtonGroup = new QButtonGroup(SOSGame);
        GameTypeButtonGroup->setObjectName("GameTypeButtonGroup");
        GameTypeButtonGroup->addButton(SimpleGameButton);
        SimpleGameButton->setObjectName("SimpleGameButton");

        horizontalLayout->addWidget(SimpleGameButton);

        GeneralGameButton = new QRadioButton(centralwidget);
        GameTypeButtonGroup->addButton(GeneralGameButton);
        GeneralGameButton->setObjectName("GeneralGameButton");

        horizontalLayout->addWidget(GeneralGameButton);

        BoardSizeLabel = new QLabel(centralwidget);
        BoardSizeLabel->setObjectName("BoardSizeLabel");

        horizontalLayout->addWidget(BoardSizeLabel);

        BoardSizeSlider = new QSlider(centralwidget);
        BoardSizeSlider->setObjectName("BoardSizeSlider");
        BoardSizeSlider->setMinimumSize(QSize(106, 15));
        BoardSizeSlider->setMinimum(3);
        BoardSizeSlider->setMaximum(10);
        BoardSizeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(BoardSizeSlider);

        BoardSizeOutput = new QLabel(centralwidget);
        BoardSizeOutput->setObjectName("BoardSizeOutput");

        horizontalLayout->addWidget(BoardSizeOutput);

        StartButton = new QPushButton(centralwidget);
        StartButton->setObjectName("StartButton");
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(StartButton->sizePolicy().hasHeightForWidth());
        StartButton->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(StartButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        SOSGame->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SOSGame);
        statusbar->setObjectName("statusbar");
        SOSGame->setStatusBar(statusbar);

        retranslateUi(SOSGame);

        QMetaObject::connectSlotsByName(SOSGame);
    } // setupUi

    void retranslateUi(QMainWindow *SOSGame)
    {
        SOSGame->setWindowTitle(QCoreApplication::translate("SOSGame", "SOSGame", nullptr));
        player2ScoreLabel->setText(QCoreApplication::translate("SOSGame", "Player 2 Score", nullptr));
        player2Score->setText(QCoreApplication::translate("SOSGame", "0", nullptr));
        label_4->setText(QCoreApplication::translate("SOSGame", "Player 2", nullptr));
        player2_S->setText(QCoreApplication::translate("SOSGame", "S", nullptr));
        player2_O->setText(QCoreApplication::translate("SOSGame", "O", nullptr));
        player1ScoreLabel->setText(QCoreApplication::translate("SOSGame", "Player1 Score", nullptr));
        player1Score->setText(QCoreApplication::translate("SOSGame", "0", nullptr));
        label_3->setText(QCoreApplication::translate("SOSGame", "Player 1", nullptr));
        player1_S->setText(QCoreApplication::translate("SOSGame", "S", nullptr));
        player1_O->setText(QCoreApplication::translate("SOSGame", "O", nullptr));
        SimpleGameButton->setText(QCoreApplication::translate("SOSGame", "Simple Game", nullptr));
        GeneralGameButton->setText(QCoreApplication::translate("SOSGame", "General Game", nullptr));
        BoardSizeLabel->setText(QCoreApplication::translate("SOSGame", "Board Size", nullptr));
        BoardSizeOutput->setText(QCoreApplication::translate("SOSGame", "3", nullptr));
        StartButton->setText(QCoreApplication::translate("SOSGame", "Start Game", nullptr));
        pushButton->setText(QCoreApplication::translate("SOSGame", "Quit Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SOSGame: public Ui_SOSGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOSGAME_H
