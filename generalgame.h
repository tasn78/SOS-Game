#ifndef GENERALGAME_H
#define GENERALGAME_H

#include "gamemode.h"

class GeneralGame : public GameMode
{
public:
    GeneralGame();
    ~GeneralGame();

    // Checks for win
    //bool checkForWin(QTableWidget* gameBoard) override;

    // Checks if GameBoard is full, resulting in game win or draw
    //bool checkGameCompletion(QTableWidget* gameBoard) override;
};

#endif // GENERALGAME_H
