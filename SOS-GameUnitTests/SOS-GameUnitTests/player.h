#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "pch.h"

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

#endif // PLAYER_H
