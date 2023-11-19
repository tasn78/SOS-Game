#pragma once
#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <vector>
#include <iostream>
#include "pch.h"

struct Move {
    int row, column;
    char symbol; // 'S' or 'O'
};

class SOSGame
{


public:

    SOSGame() {};
    ~SOSGame() {};


    // Sets player 1 to human or computer
    void on_player1Human_clicked();
    void on_player1Computer_clicked();

    // Sets player 2 to human or computer
    void on_player2Human_clicked();
    void on_player2Computer_clicked();

    // Refactored function
    Move makeComputerMove(int player) {
        srand(time(0)); // Ideally, call this once in the constructor

        for (int attempt = 0; attempt < boardSize * boardSize; ++attempt) {
            int row = rand() % boardSize;
            int column = rand() % boardSize;

            if (vectorBoard[row][column].empty()) {
                std::string computerChoice = (rand() % 2 == 0) ? "S" : "O";
                vectorBoard[row][column] = computerChoice;
                return Move{ row, column, computerChoice[0] };
            }
        }

        return Move{ -1, -1, ' ' }; // Return an invalid move if no empty cell is found
    }


    void initializeBoard() {
        vectorBoard.clear();
        vectorBoard.resize(boardSize, std::vector<std::string>(boardSize, ""));
    }

    int boardSize;
    char GameType;
    bool GameOver;
    int player1Score = 0;
    int player2Score = 0;
    int computerMoveRow;
    int computerMoveColumn;
    std::vector<std::vector<std::string>> vectorBoard;
};


class Players {
public:
    Players() {}
    ~Players() {}

    // Sets player turn
    void setPlayerTurn(int nextPlayer) {
        playerTurn = nextPlayer;
    }

    // Gets current player's turn
    int getPlayerTurn() {
        return playerTurn;
    }

    // Switches player from 1 to 2 or 2 to 1
    void switchPlayerTurn() {
        if (playerTurn == 1) {
            playerTurn = 2;
        }
        else if (playerTurn == 2) {
            playerTurn = 1;
        }
    }

    // Sets player 1's move as S or O from radio buttons
    void setPlayer1Move(const std::string& S_or_O) {
        player1Move = S_or_O;
    }

    // Gets player 1's current move from S or O radio buttons
    std::string getPlayer1Move() {
        return player1Move;
    }

    // Sets player 2's move as S or O from radio buttons
    void setPlayer2Move(const std::string& S_or_O) {
        player2Move = S_or_O;
    }

    // Gets player 2's current move from S or O radio buttons
    std::string getPlayer2Move() {
        return player2Move;
    }

    // Setter for player 1, human (1) or computer (0)
    void setPlayer1Human(int humanOrComputer) {
        player1Human = humanOrComputer;
    }

    // Getter for player 1, human (1) or computer (0)
    int getPlayer1Human() {
        return player1Human;
    }

    // Setter for player 2, human (1) or computer (0)
    void setPlayer2Human(int humanOrComputer) {
        player2Human = humanOrComputer;
    }

    // Getter for player 2, human (1) or computer (0)
    int getPlayer2Human() {
        return player2Human;
    }


private:
    int player1Score = 0;
    int player2Score = 0;
    int playerTurn = 1;
    std::string player1Move;
    std::string player2Move;
    int player1Human;
    int player2Human;
};

class GameMode
{
public:
    // Default constructor
    GameMode() {};
    // Destructor
    ~GameMode() {};


    // Checks for SOS in the right direction
    bool GameMode::checkSOSRight(int row, int column, std::vector<std::vector<std::string>>& gameBoard, int boardSize) {
        if (!isColumnValid(column + 2, boardSize)) {
            return false;
        }

        std::string pattern = "";
        for (int i = column; i <= column + 2; ++i) {
            if (isColumnValid(i, boardSize)) {
                pattern += gameBoard[row][i];
            }
        }

        return pattern == "SOS";
    }

    // Checks for SOS in the left direction
    bool GameMode::checkSOSLeft(int row, int column, std::vector<std::vector<std::string>>& gameBoard, int boardSize) {
        if (!isColumnValid(column - 2, boardSize)) {
            return false;
        }

        std::string pattern = "";
        for (int i = column; i >= column - 2; --i) {
            if (isColumnValid(i, boardSize)) {
                pattern += gameBoard[row][i];
            }
        }

        return pattern == "SOS";
    }

    // Checks for SOS in the down direction
    bool GameMode::checkSOSDown(int row, int column, std::vector<std::vector<std::string>>& gameBoard, int boardSize) {
        if (!isRowValid(row + 2, boardSize)) {
            return false;
        }

        std::string pattern = "";
        for (int i = row; i <= row + 2; ++i) {
            if (isRowValid(i, boardSize) && isColumnValid(column, boardSize)) {
                pattern += gameBoard[i][column];
            }
        }

        return pattern == "SOS";
    }

    // Checks for SOS in the up direction
    bool GameMode::checkSOSUp(int row, int column, std::vector<std::vector<std::string>>& gameBoard, int boardSize) {
        if (!isRowValid(row - 2, boardSize)) {
            return false;
        }

        std::string pattern = "";
        for (int i = row; i >= row - 2; --i) {
            if (isRowValid(i, boardSize) && isColumnValid(column, boardSize)) {
                pattern += gameBoard[i][column];
            }
        }

        return pattern == "SOS";
    }

    // Checks for SOS in the up-right direction
    bool GameMode::checkSOSUpRight(int row, int column, std::vector<std::vector<std::string>>& gameBoard, int boardSize) {
        if (!isRowValid(row - 2, boardSize) || !isColumnValid(column + 2, boardSize)) {
            return false;
        }

        std::string pattern = "";
        for (int i = 0; i < 3; ++i) {
            if (isRowValid(row - i, boardSize) && isColumnValid(column + i, boardSize)) {
                pattern += gameBoard[row - i][column + i];
            }
        }

        return pattern == "SOS";
    }

    //  Checks for SOS up-left direction
    bool GameMode::checkSOSUpLeft(int row, int column, std::vector<std::vector<std::string>>& gameBoard, int boardSize) {
        if (!isRowValid(row - 2, boardSize) || !isColumnValid(column - 2, boardSize)) {
            return false;
        }

        std::string pattern = "";
        for (int i = 0; i < 3; ++i) {
            if (isRowValid(row - i, boardSize) && isColumnValid(column - i, boardSize)) {
                pattern += gameBoard[row - i][column - i];
            }
        }

        return pattern == "SOS";
    }

    // Checks for SOS in the down-right direction
    bool GameMode::checkSOSDownRight(int row, int column, std::vector<std::vector<std::string>>& gameBoard, int boardSize) {
        if (!isRowValid(row + 2, boardSize) || !isColumnValid(column + 2, boardSize)) {
            return false;
        }

        std::string pattern = "";
        for (int i = 0; i < 3; ++i) {
            if (isRowValid(row + i, boardSize) && isColumnValid(column + i, boardSize)) {
                pattern += gameBoard[row + i][column + i];
            }
        }

        return pattern == "SOS";
    }

    // Check for SOS in the down-left direction
    bool GameMode::checkSOSDownLeft(int row, int column, std::vector<std::vector<std::string>>& gameBoard, int boardSize) {
        if (!isRowValid(row + 2, boardSize) || !isColumnValid(column - 2, boardSize)) {
            return false;
        }

        std::string pattern = "";
        for (int i = 0; i < 3; ++i) {
            if (isRowValid(row + i, boardSize) && isColumnValid(column - i, boardSize)) {
                pattern += gameBoard[row + i][column - i];
            }
        }

        return pattern == "SOS";
    }

    // Check for when 'O' is placed in the center of a 3x3 square to form "SOS" - used chatGPT for looping algorithms
    bool GameMode::checkSOSWithOInCenter(int row, int column, std::vector<std::vector<std::string>>& gameBoard, int boardSize) {
        std::string sosPattern = "SOS";

        // Check in all eight directions
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                std::string pattern = "";

                for (int i = -1; i <= 1; ++i) {
                    int r = row + dr * i;
                    int c = column + dc * i;

                    if (isRowValid(r, boardSize) && isColumnValid(c, boardSize)) {
                        pattern += gameBoard[r][c];
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
    bool GameMode::checkGameCompletion(std::vector<std::vector<std::string>>& gameBoard) {
        for (const auto& row : gameBoard) {
            for (std::string button : row) {
                if (button != "S" && button != "O") {
                    return false; // A button contains neither 'S' nor 'O'
                }
            }
        }
        return true; // All buttons contain 'S' or 'O'
    }


    // Checks if row is valid for iterating through the SOSGameBoard checking for SOS
    bool GameMode::isRowValid(int row, int boardSize) {
        return (row >= 0 && row < boardSize);
    }

    // Checks if column is valid for iterating through the SOSGameBoard checking for SOS
    bool GameMode::isColumnValid(int column, int boardSize) {
        return (column >= 0 && column < boardSize);
    }

private:
    char gameType;

};



class SimpleGame : public GameMode
{
public:
    SimpleGame() {}
    ~SimpleGame() {}

    bool SimpleGame::checkForWin(std::vector<std::vector<std::string>> gameBoard) {
        gameBoard;
        return true;
    }

    // Main function that checks SOS in all directions
    bool SimpleGame::checkForSOS(int row, int column, std::vector<std::vector<std::string>>& gameBoard, int boardSize) {

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

};



class GeneralGame : public GameMode
{
public:
    GeneralGame() {}
    ~GeneralGame() {}

    // Checks for win
    bool GeneralGame::checkForWin(std::vector<std::vector<std::string>> gameBoard) {
        return true;
    }


    // Main function that checks SOS in all directions
    bool GeneralGame::checkForSOS(int row, int column, std::vector<std::vector<std::string>>& gameBoard, int boardSize) {
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
    void GeneralGame::addTotalCreatedSOSCount(int& playerScore, int row, int column, std::vector<std::vector<std::string>> gameBoard, int boardSize) {
        int SOSCount = 0;

        if (checkSOSRight(row, column, gameBoard, boardSize)) {
            SOSCount += 1;
        }

        if (checkSOSLeft(row, column, gameBoard, boardSize)) {
            SOSCount += 1;
        }

        if (checkSOSDown(row, column, gameBoard, boardSize)) {
            SOSCount += 1;
        }

        if (checkSOSUp(row, column, gameBoard, boardSize)) {
            SOSCount += 1;
        }

        if (checkSOSUpRight(row, column, gameBoard, boardSize)) {
            SOSCount += 1;
        }

        if (checkSOSUpLeft(row, column, gameBoard, boardSize)) {
            SOSCount += 1;
        }

        if (checkSOSDownRight(row, column, gameBoard, boardSize)) {
            SOSCount += 1;
        }

        if (checkSOSDownLeft(row, column, gameBoard, boardSize)) {
            SOSCount += 1;
        }

        if (checkSOSWithOInCenter(row, column, gameBoard, boardSize)) {
            SOSCount += 1;
        }
        playerScore += SOSCount;
    }

};

#endif // GAMEMODE_H
