#include "player.h"

void Players::setPlayerTurn(int nextPlayer) {
    playerTurn = nextPlayer;
}

int Players::getPlayerTurn() {
    return playerTurn;
}

void Players::switchPlayerTurn() {
    if (playerTurn == 1) {
        playerTurn = 2;
    }
    else if (playerTurn == 2) {
        playerTurn = 1;
    }
}

void Players::setPlayer1Move(std::string S_or_O) {
    player1Move = S_or_O;
}

std::string Players::getPlayer1Move() {
    return player1Move;
}

void Players::setPlayer2Move(std::string S_or_O) {
    player2Move = S_or_O;
}

std::string Players::getPlayer2Move() {
    return player2Move;
}