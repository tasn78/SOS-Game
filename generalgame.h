#ifndef GENERALGAME_H
#define GENERALGAME_H

#include "gamemode.h"

class GeneralGame : public GameMode
{
public:
    GeneralGame() {}
    ~GeneralGame() {}

    // Unused check for win, possible use for sudden death
    bool checkForWin(std::vector<std::vector<QPushButton*>> gameBoard) override;

    // Main function that checks SOS in all directions
    bool checkForSOS(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) override;

    // Adds all created SOS's created and returns new playerScore
    void addTotalCreatedSOSCount(int& playerScore, int row, int column, std::vector<std::vector<QPushButton*>> gameBoard, int boardSize);
};

#endif // GENERALGAME_H
