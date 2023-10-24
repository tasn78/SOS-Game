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

    // Checks for SOS on GameBoard
    bool checkForSOS(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize);

    // Checks for a win or draw
    virtual bool checkForWin(std::vector<std::vector<QPushButton*>>& gameBoard) = 0;

    // Checks if GameBoard is full
    virtual bool checkGameCompletion(std::vector<std::vector<QPushButton*>>& gameBoard) = 0;

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
