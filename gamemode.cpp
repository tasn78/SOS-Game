#include "gamemode.h"
#include <QMessageBox>
#include <QDebug>
#include "sosgame.h"
#include "ui_sosgame.h"

GameMode::GameMode(){
}

GameMode::~GameMode(){

}

//  Checks all directions for SOS from button click on game board
bool GameMode::checkForSOS(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {
    // Check if the row and column are within the valid range
    if (!isRowValid(row, boardSize) || !isColumnValid(column, boardSize)) {
        // Handle out-of-range error if needed
        return false;
    }

    QString sosPattern = "SOS";

    // Used ChatGPT to reduce my lines of code to a lambda function to check for SOS in a specific direction
    auto checkDirection = [&](int dr, int dc) -> bool {
        QString pattern = "";
        for (int i = 0; i < 3; ++i) {
            int r = row + dr * i;
            int c = column + dc * i;

            if (isRowValid(r, boardSize) && isColumnValid(c, boardSize) && gameBoard[r][c]) {
                pattern += gameBoard[r][c]->text();
            }
        }
        return pattern == sosPattern || (pattern == "SOS" && gameBoard[row + dr][column + dc]->text() == "S");
    };

    // Check all eight possible directions for SOS
    if (checkDirection(0, 1) || checkDirection(0, -1) || checkDirection(1, 0) || checkDirection(-1, 0) ||
        checkDirection(-1, 1) || checkDirection(-1, -1) || checkDirection(1, 1) || checkDirection(1, -1)) {
        return true;
    }

    return false;
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
