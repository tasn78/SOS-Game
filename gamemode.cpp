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
bool GameMode::checkForSOS(int row, int column, QTableWidget* gameBoard, int boardSize) {
    // Check if the row and column are within the valid range
    if (!isRowValid(row, boardSize) || !isColumnValid(column, boardSize)) {
        // Handle out-of-range error if needed
        return false;
    }

    // String to compare from the buttons +2 and -2 from the button clicked
    QString sosPattern = "SOS";

    // Check for SOS in horizontal direction (right)
    if (isColumnValid(column + 2, boardSize)) {
        QString horizontalPattern = "";
        for (int i = column; i <= column + 2; ++i) {
            QTableWidgetItem* item = gameBoard->item(row, i);
            if (item) {
                horizontalPattern += item->text();
            }
        }
        if (horizontalPattern == sosPattern) {
            qDebug() << "sosPattern: " << sosPattern;
            qDebug() << "horizontalPattern: " << horizontalPattern;
            return true;
        }
    }

    // Check for SOS in vertical direction (down)
    if (isRowValid(row + 2, boardSize)) {
        QString verticalPattern = "";
        for (int i = row; i <= row + 2; ++i) {
            QTableWidgetItem* item = gameBoard->item(i, column);
            if (item) {
                verticalPattern += item->text();
                qDebug() << "horizontalPattern: " << verticalPattern;
            }
        }
        if (verticalPattern == sosPattern) {
            qDebug() << "sosPattern: " << sosPattern;
            qDebug() << "verticalPattern: " << verticalPattern;
            return true;
        }
    }

    // Check for SOS in diagonal direction (down-right)
    if (isRowValid(row + 2, boardSize) && isColumnValid(column + 2, boardSize)) {
        QString diagonalPattern = "";
        for (int i = 0; i < 3; ++i) {
            QTableWidgetItem* item = gameBoard->item(row + i, column + i);
            if (item) {
                diagonalPattern += item->text();
            }
        }
        if (diagonalPattern == sosPattern) {
            qDebug() << "sosPattern: " << sosPattern;
            qDebug() << "diagonalPattern: " << diagonalPattern;
            return true;
        }
    }

    // Check for SOS in diagonal direction (down-left)
    if (isRowValid(row + 2, boardSize) && isColumnValid(column - 2, boardSize)) {
        QString diagonalPattern = "";
        for (int i = 0; i < 3; ++i) {
            QTableWidgetItem* item = gameBoard->item(row + i, column - i);
            if (item) {
                diagonalPattern += item->text();
            }
        }
        if (diagonalPattern == sosPattern) {
            qDebug() << "sosPattern: " << sosPattern;
            qDebug() << "diagonalPattern: " << diagonalPattern;
            return true;
        }
    }

    // Check for SOS in diagonal direction (up-right)
    if (isRowValid(row - 2, boardSize) && isColumnValid(column + 2, boardSize)) {
        QString diagonalPattern = "";
        for (int i = 0; i < 3; ++i) {
            QTableWidgetItem* item = gameBoard->item(row - i, column + i);
            if (item) {
                diagonalPattern += item->text();
            }
        }
        if (diagonalPattern == sosPattern) {
            qDebug() << "sosPattern: " << sosPattern;
            qDebug() << "diagonalPattern: " << diagonalPattern;
            return true;
        }
    }

    // Check for SOS in diagonal direction (up-left)
    if (isRowValid(row - 2, boardSize) && isColumnValid(column - 2, boardSize)) {
        QString diagonalPattern = "";
        for (int i = 0; i < 3; ++i) {
            QTableWidgetItem* item = gameBoard->item(row - i, column - i);
            if (item) {
                diagonalPattern += item->text();
            }
        }
        if (diagonalPattern == sosPattern) {
            qDebug() << "sosPattern: " << sosPattern;
            qDebug() << "diagonalPattern: " << diagonalPattern;
            return true;
        }
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
