#ifndef SIMPLEGAME_H
#define SIMPLEGAME_H

#include "gamemode.h"

class SimpleGame : public GameMode
{
public:
    SimpleGame(){}
    ~SimpleGame(){}

    // Unused checkForWin, possible use for sudden death
    bool checkForWin(std::vector<std::vector<QPushButton*>> gameBoard) override;

    // Main function that checks SOS in all directions
    bool checkForSOS(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) override;
};

#endif // SIMPLEGAME_H
