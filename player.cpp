#include "player.h"
#include "ui_sosgame.h"


// Setter for player turn
void Players::setPlayerTurn(int nextPlayer){
    playerTurn = nextPlayer;
}

// Getter for player turn
int Players::getPlayerTurn(){
    return playerTurn;
}

// Switches player from 1 to 2, or 2 to 1
void Players::switchPlayerTurn(){
    if (this->getPlayerTurn() == 1){
        this->setPlayerTurn(2);
    }
    else if (this->getPlayerTurn() == 2){
        this->setPlayerTurn(1);
    }
}

// Sets player 1 move to 'S' or 'O'
void Players::setPlayer1Move(QString S_or_O){
    player1Move = S_or_O;
}

// Gets player 1 move
QString Players::getPlayer1Move(){
    return player1Move;
}

// Sets player 2 move to 'S' or 'O'
void Players::setPlayer2Move(QString S_or_O){
    player2Move = S_or_O;
}

// Gets player 2 move
QString Players::getPlayer2Move(){
    return player2Move;
}

// Setter for player 1, human (1) or computer (0)
void Players::setPlayer1Human(int humanOrComputer){
    player1Human = humanOrComputer;
}

// Getter for player 1, human (1) or computer (0)
int Players::getPlayer1Human(){
    return player1Human;
}

// Setter for player 2, human (1) or computer (0)
void Players::setPlayer2Human(int humanOrComputer){
    player2Human = humanOrComputer;
}

// Getter for player 2, human (1) or computer (0)
int Players::getPlayer2Human(){
    return player2Human;
}
