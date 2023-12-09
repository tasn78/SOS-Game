#include "gamemode.h"
#include <QMessageBox>
#include <QDebug>


GameMode::GameMode(){

}

GameMode::~GameMode(){

}

// Checks for SOS in the right direction of player move
bool GameMode::checkSOSRight(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {
    if (!isColumnValid(column + 2, boardSize)) {
        return false;
    }

    QString pattern = "";
    for (int i = column; i <= column + 2; ++i) {
        if (gameBoard[row][i]) {
            pattern += gameBoard[row][i]->text();
        }
    }

    return pattern == "SOS";
}

// Checks for SOS in the left direction of player move
bool GameMode::checkSOSLeft(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {
    if (!isColumnValid(column - 2, boardSize)) {
        return false;
    }

    QString pattern = "";
    for (int i = column; i >= column - 2; --i) {
        if (gameBoard[row][i]) {
            pattern += gameBoard[row][i]->text();
        }
    }

    return pattern == "SOS";
}

// Checks for SOS in the down direction of player move
bool GameMode::checkSOSDown(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {
    if (!isRowValid(row + 2, boardSize)) {
        return false;
    }

    QString pattern = "";
    for (int i = row; i <= row + 2; ++i) {
        if (gameBoard[i][column]) {
            pattern += gameBoard[i][column]->text();
        }
    }

    return pattern == "SOS";
}

// Checks for SOS in the up direction
bool GameMode::checkSOSUp(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {
    if (!isRowValid(row - 2, boardSize)) {
        return false;
    }

    QString pattern = "";
    for (int i = row; i >= row - 2; --i) {
        if (gameBoard[i][column]) {
            pattern += gameBoard[i][column]->text();
        }
    }

    return pattern == "SOS";
}

// Checks for SOS in the up-right direction
bool GameMode::checkSOSUpRight(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {
    if (!isRowValid(row - 2, boardSize) || !isColumnValid(column + 2, boardSize)) {
        return false;
    }

    QString pattern = "";
    for (int i = 0; i < 3; ++i) {
        if (gameBoard[row - i][column + i]) {
            pattern += gameBoard[row - i][column + i]->text();
        }
    }

    return pattern == "SOS";
}

//  Checks for SOS up-left direction
bool GameMode::checkSOSUpLeft(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {
    if (!isRowValid(row - 2, boardSize) || !isColumnValid(column - 2, boardSize)) {
        return false;
    }

    QString pattern = "";
    for (int i = 0; i < 3; ++i) {
        if (gameBoard[row - i][column - i]) {
            pattern += gameBoard[row - i][column - i]->text();
        }
    }

    return pattern == "SOS";
}

// Checks for SOS in the down-right direction
bool GameMode::checkSOSDownRight(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {
    if (!isRowValid(row + 2, boardSize) || !isColumnValid(column + 2, boardSize)) {
        return false;
    }

    QString pattern = "";
    for (int i = 0; i < 3; ++i) {
        if (gameBoard[row + i][column + i]) {
            pattern += gameBoard[row + i][column + i]->text();
        }
    }

    return pattern == "SOS";
}

// Check for SOS in the down-left direction
bool GameMode::checkSOSDownLeft(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {
    if (!isRowValid(row + 2, boardSize) || !isColumnValid(column - 2, boardSize)) {
        return false;
    }

    QString pattern = "";
    for (int i = 0; i < 3; ++i) {
        if (gameBoard[row + i][column - i]) {
            pattern += gameBoard[row + i][column - i]->text();
        }
    }

    return pattern == "SOS";
}

// Check for when 'O' is placed in the center of a 3x3 square to form "SOS" - used chatGPT for looping algorithms
bool GameMode::checkSOSWithOInCenter(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {
    QString sosPattern = "SOS";

    // Check in all eight directions
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            QString pattern = "";

            for (int i = -1; i <= 1; ++i) {
                int r = row + dr * i;
                int c = column + dc * i;

                if (isRowValid(r, boardSize) && isColumnValid(c, boardSize) && gameBoard[r][c]) {
                    pattern += gameBoard[r][c]->text();
                }
            }

            if (pattern == sosPattern) {
                return true;
            }
        }
    }

    return false;
}



// Checks for draw / full gameboard
bool GameMode::checkGameCompletion(std::vector<std::vector<QPushButton*>>& gameBoard) {
    for (const auto& row : gameBoard) {
        for (QPushButton* button : row) {
            if (button && button->text().isEmpty()) {
                return false; // If a button is still empty, game is not complete
            }
        }
    }
    return true; // No empty buttons, the game board is full
}

// Checks if row is valid for iterating through the SOSGameBoard checking for SOS
bool GameMode::isRowValid(int row, int boardSize) {
    return (row >= 0 && row < boardSize);
}

// Checks if column is valid for iterating through the SOSGameBoard checking for SOS
bool GameMode::isColumnValid(int column, int boardSize) {
    return (column >= 0 && column < boardSize);
}

// Draw line through the SOS created
void GameMode::drawLineThroughSOS(int row, int column, int direction, int playerTurn, int boardSize, QTableWidget* SOSGameBoard) {
    // Create a painter for the game board
    QPainter painter(SOSGameBoard);

    // Set the line color and thickness
    if (playerTurn == 1){
        painter.setPen(QPen(Qt::blue, 2));
    }
    else if (playerTurn == 2){
        painter.setPen(QPen(Qt::red, 2));
    }

    // Define the starting and ending points of the line
    int startX = column * (500 / boardSize) / 2;
    int startY = row * (500 / boardSize) / 2;
    int endX;
    int endY;

    // Calculate the ending point based on the direction
    if (direction == 0) { // Horizontal
        endX = (column + 2) * (500 / boardSize) / 2;
        endY = row * (500 / boardSize) / 2;
    }
    else if (direction == 1) { // Vertical
        endX = column * (500 / boardSize) / 2;
        endY = (row + 2) * (500 / boardSize) / 2;
    }
    else if (direction == 2) { // Diagonal down-right
        endX = (column + 2) * (500 / boardSize) / 2;
        endY = (row + 2) * (500 / boardSize) / 2;
    }
    else if (direction == 3) { // Diagonal down-left
        endX = (column - 2) * (500 / boardSize) / 2;
        endY = (row + 2) * (500 / boardSize) / 2;
    }

    // Draw the line
    painter.drawLine(startX, startY, endX, endY);
}

