#ifndef SIMPLEGAME_H
#define SIMPLEGAME_H

#include "gamemode.h"

class SimpleGame : public GameMode
{
public:
    SimpleGame(){}

    bool checkForWin(std::vector<std::vector<QPushButton*>>& gameBoard);

    bool checkGameCompletion(std::vector<std::vector<QPushButton*>>& gameBoard);
};

#endif // SIMPLEGAME_H
