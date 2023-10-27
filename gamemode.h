#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <QPainter>
#include <QTableWidget>

#include "ui_sosgame.h"


class GameMode
{
public:
    // Default constructor
    GameMode();
    // Destructor
    ~GameMode();


    bool checkSOSRight(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize);

    // Checks for SOS in the left direction
    bool checkSOSLeft(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize);

    // Checks for SOS in the down direction
    bool checkSOSDown(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize);

    // Checks for SOS in the up direction
    bool checkSOSUp(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize);

    // Checks for SOS in the up-right direction
    bool checkSOSUpRight(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize);

    // Checks for SOS in up-left direction
    bool checkSOSUpLeft(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize);

    // Checks for SOS in the down-right direction
    bool checkSOSDownRight(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize);

    // Checks for SOS in the down-left direction
    bool checkSOSDownLeft(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize);

    // Checks for 'O' placement in center
    bool checkSOSWithOInCenter(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize);

    // Checks for SOS on GameBoard using the various direction checks
    virtual bool checkForSOS(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) = 0;

    // Checks for a win or draw
    virtual bool checkForWin(std::vector<std::vector<QPushButton*>> gameBoard) = 0;

    // Checks if GameBoard is full
    bool checkGameCompletion(std::vector<std::vector<QPushButton*>>& gameBoard);

    // Checks if rows and columns are valid when checking for SOS
    bool isRowValid(int row, int boardSize);
    bool isColumnValid(int column, int boardSize);

    // Draws a line through the SOS
    void drawLineThroughSOS(int row, int column, int direction, int playerTurn, int boardSize, QTableWidget* SOSGameBoard);

private:
    char gameType;

protected:
    // Highlights the 3 pushbuttons that form SOS
    QPen highlightPen;

};

#endif // GAMEMODE_H
