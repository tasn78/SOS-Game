#pragma once

#ifndef SOSGAME_H
#define SOSGAME_H

#include "ui_sosgame.h"
#include "player.h"
#include "gamemode.h"
#include "simplegame.h"

#include <QMainWindow>
#include <cstddef>
#include <QWidget>
#include <QPushButton>
#include <vector>
#include <QMessageBox>
#include <QGridLayout>
#include <QString>
#include <QApplication>
#include <QMessageBox>
#include <QtCore>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QtGui>


QT_BEGIN_NAMESPACE
namespace Ui { class SOSGame; }
QT_END_NAMESPACE


struct Cell
{
    QPushButton *cellBtn = nullptr;
    int row = -1;
    int col = -1;
    Cell(QPushButton *cellBtn, int row, int col)
        : cellBtn(cellBtn), row(row), col(col) {}
};


enum class BoardMoves { Empty, S, O };

enum class BoardState { Draw, Player1Win, Player2Win };



class SOSGame : public QMainWindow
{
    Q_OBJECT

public:

    SOSGame(QWidget *parent = nullptr);
    ~SOSGame();

    //std::vector<Cell> buildCellButtons(int boardSize);
    void createGameBoard(int boardSize);


    void setGameState(std::vector<Cell>);
    //std::vector<Cell> getGameState();

    void setGameType(char);
    char getGameType();

    bool isGameOver(int row, int column, QTableWidget* gameBoard, int boardSize);



private slots:

    void on_BoardSizeSlider_valueChanged(int value);

    void on_StartButton_clicked();

    void on_SimpleGameButton_clicked();

    void on_GeneralGameButton_clicked();

    void gameBoardButtonClick();

    void on_player1_S_clicked();

    void on_player1_O_clicked();

    void on_player2_S_clicked();

    void on_player2_O_clicked();

    void on_pushButton_clicked();


private:
    Ui::SOSGame *ui;
    int boardSize = 3;
    std::vector<Cell> GameState;
    char GameType;
    bool GameOver;
    Players GamePlayers;
};




#endif // SOSGAME_H
