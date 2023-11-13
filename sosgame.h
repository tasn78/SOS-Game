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

    // Creates the UI game board based on board size slider, creates vector for comparisons
    void createGameBoard(int boardSize);

    // Getter/Setter for the game board
    void setGameState(int boardSize, std::vector<std::vector<QPushButton*>>&);
    std::vector<std::vector<QPushButton*>> getGameState();

    // Getter/Setter for GameType (Simple or General)
    void setGameType(char);
    char getGameType();

    //  Checks board to see if simple game is over by the board being completely filled or an SOS has been created
    bool isSimpleGameOver(int row, int column, std::vector<std::vector<QPushButton*>> gameBoard, int boardSize);
    bool isGeneralGameOver(int row, int column, std::vector<std::vector<QPushButton*>> gameBoard, int boardSize);

    // Prints vector for testing/visual purposes
    void printVectorBoard(const std::vector<std::vector<QPushButton*>>& vectorBoard);


private slots:

    // Slider to choose board size
    void on_BoardSizeSlider_valueChanged(int value);

    // Start button
    void on_StartButton_clicked();

    // Simple game radio button
    void on_SimpleGameButton_clicked();

    // General game radio button
    void on_GeneralGameButton_clicked();

    // Button on board click action
    void gameBoardButtonClick();

    // Player 1 'S' radio button
    void on_player1_S_clicked();

    // Player 1 'O' radio button
    void on_player1_O_clicked();

    // Player 2 'S' radio button
    void on_player2_S_clicked();

    // Player 2 'O' radio button
    void on_player2_O_clicked();

    // Exit button
    void on_pushButton_clicked();

    // Resets scores
    void resetGame();

    // Sets player 1 to human or computer
    void on_player1Human_clicked();
    void on_player1Computer_clicked();

    // Sets player 2 to human or computer
    void on_player2Human_clicked();
    void on_player2Computer_clicked();


private:
    Ui::SOSGame *ui;
    std::vector<std::vector<QPushButton*>> vectorBoard;
    int boardSize = 3;
    char GameType;
    bool GameOver;
    Players GamePlayers;
    int player1Score = 0;
    int player2Score = 0;

};




#endif // SOSGAME_H
