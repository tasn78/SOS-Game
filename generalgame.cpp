#include "generalgame.h"

bool GeneralGame::checkForWin(std::vector<std::vector<QPushButton*>> gameBoard) {
    gameBoard;
    return true;
}


// Main function that checks SOS in all directions
bool GeneralGame::checkForSOS(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {
    return checkSOSRight(row, column, gameBoard, boardSize) ||
           checkSOSLeft(row, column, gameBoard, boardSize) ||
           checkSOSDown(row, column, gameBoard, boardSize) ||
           checkSOSUp(row, column, gameBoard, boardSize) ||
           checkSOSUpRight(row, column, gameBoard, boardSize) ||
           checkSOSUpLeft(row, column, gameBoard, boardSize) ||
           checkSOSDownRight(row, column, gameBoard, boardSize) ||
           checkSOSDownLeft(row, column, gameBoard, boardSize) ||
           checkSOSWithOInCenter(row, column, gameBoard, boardSize);
}

//  Checks all directions for SOS, for each SOS created, adds +1 to player score
void GeneralGame::addTotalCreatedSOSCount(int playerScore, int row, int column, std::vector<std::vector<QPushButton*>> gameBoard, int boardSize) {

    if (checkSOSRight(row, column, gameBoard, boardSize)){
        playerScore += 1;
    }

    if (checkSOSLeft(row, column, gameBoard, boardSize)){
        playerScore += 1;
    }

    if (checkSOSDown(row, column, gameBoard, boardSize)){
        playerScore += 1;
    }

    if (checkSOSUp(row, column, gameBoard, boardSize)){
        playerScore += 1;
    }

    if (checkSOSUpRight(row, column, gameBoard, boardSize)){
        playerScore += 1;
    }

    if (checkSOSUpLeft(row, column, gameBoard, boardSize)){
        playerScore += 1;
    }

    if (checkSOSDownRight(row, column, gameBoard, boardSize)){
        playerScore += 1;
    }

    if (checkSOSDownLeft(row, column, gameBoard, boardSize)){
        playerScore += 1;
    }

    if (checkSOSWithOInCenter(row, column, gameBoard, boardSize)){
        playerScore += 1;
    }

}
