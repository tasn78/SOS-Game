#include "player.h"
#include "ui_sosgame.h"



// Constructor


void Players::setPlayerTurn(int nextPlayer){
    playerTurn = nextPlayer;
}


int Players::getPlayerTurn(){
    return playerTurn;
}

/*
void Player::makeMove(){
    if (playerTurn == 1){
        if (radio);
    }
}
*/


void Players::setPlayer1Move(QString S_or_O){
    player1Move = S_or_O;
}


QString Players::getPlayer1Move(){
    return player1Move;
}


void Players::setPlayer2Move(QString S_or_O){
    player2Move = S_or_O;
}


QString Players::getPlayer2Move(){
    return player2Move;
}
