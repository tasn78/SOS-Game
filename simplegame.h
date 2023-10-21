#ifndef SIMPLEGAME_H
#define SIMPLEGAME_H

#include "gamemode.h"

class SimpleGame : public GameMode
{
public:
    SimpleGame();
    ~SimpleGame();

    bool checkForWin(QTableWidget* gameBoard) override;

    bool checkGameCompletion(QTableWidget* gameBoard) override;
};

#endif // SIMPLEGAME_H
