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
#include <QFile>
#include <QTextStream>


// Used for recording
struct GameMove {
    int player;
    int row;
    int column;
    char symbol;
};

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

    //  Computer makes move when 1 player and 1 computer
    void makeComputerMove(int player);

    // Simulates a game of computer vs computer
    void simulateComputerTurn();

    // Starts game of computer vs computer setting computer move delay
    void startComputerVsComputer();

    // Message box to start new game or continue on game end
    void gameOverOptions();

    //  Restarts on continuing at end of game
    void handleRestart();

    // Resumes game after a win/loss/draw if user selects continue at the end of game
    void resumeGame();

    // Sets whether user wants to record or not
    void on_RecordGameBox_stateChanged(int arg1);

    // Records individul move to stream
    void recordMove(const GameMove &move);

    // Starts recording game
    void startRecording();

    // Stops recordin game
    void stopRecording();

    // Function for ReplayGameButton ui button
    void on_ReplayGameButton_clicked();

    // Loads a recorded game from txt file
    void loadRecordedGame();

    // Applies move to game board
    void applyMove(const GameMove& move);

    // Performs single stemp of replay
    void performReplayStep();

    // Creates game board for replay
    void initializeBoardForReplay(int boardSize);


private:
    Ui::SOSGame *ui;
    std::vector<std::vector<QPushButton*>> vectorBoard;
    int boardSize = 3;
    char GameType;
    bool GameOver;
    Players GamePlayers;
    int player1Score = 0;
    int player2Score = 0;
    QTimer* computerMoveTimer;
    int computerMoveRow;
    int computerMoveColumn;
    bool gameOverExecuted = false;
    QTextStream outputStream;
    QFile file;
    QList<GameMove> recordedMoves;
    int currentMoveIndex = 0;
    QTimer* replayTimer;
};




#endif // SOSGAME_H
