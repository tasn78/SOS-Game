#include "simplegame.h"

//  Unused checkForWin, possible use in sudden death
bool SimpleGame::checkForWin(std::vector<std::vector<QPushButton*>> gameBoard){
    gameBoard;
    return true;
}

// Main function that checks SOS in all directions
bool SimpleGame::checkForSOS(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {

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
