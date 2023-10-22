#ifndef SIMPLEGAME_H
#define SIMPLEGAME_H

#include "gamemode.h"

class SimpleGame : public GameMode
{
public:
    SimpleGame(){}

    bool checkForWin(QTableWidget* gameBoard);

    bool checkGameCompletion(QTableWidget* gameBoard);
};

#endif // SIMPLEGAME_H
