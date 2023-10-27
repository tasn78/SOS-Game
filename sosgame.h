#pragma once

#ifndef SOSGAME_H
#define SOSGAME_H

#include "ui_sosgame.h"
#include "player.h"
#include "gamemode.h"
#include "simplegame.h"
#include "generalgame.h"

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


class SOSGame : public QMainWindow
{
    Q_OBJECT

public:

    SOSGame(QWidget *parent = nullptr);
    ~SOSGame();

    //std::vector<Cell> buildCellButtons(int boardSize);
    void createGameBoard(int boardSize);


    void setGameState(int boardSize, std::vector<std::vector<QPushButton*>>&);
    std::vector<std::vector<QPushButton*>> getGameState();

    void setGameType(char);
    char getGameType();

    bool isSimpleGameOver(int row, int column, std::vector<std::vector<QPushButton*>> gameBoard, int boardSize);
    bool isGeneralGameOver(int row, int column, std::vector<std::vector<QPushButton*>> gameBoard, int boardSize);

    void printVectorBoard(const std::vector<std::vector<QPushButton*>>& vectorBoard);


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
    std::vector<std::vector<QPushButton*>> vectorBoard;
    int boardSize = 3;
    char GameType;
    bool GameOver;
    Players GamePlayers;
    int player1Score;
    int player2Score;
};




#endif // SOSGAME_H
