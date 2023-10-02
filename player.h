#pragma once

#ifndef PLAYER_H
#define PLAYER_H

class Players {
public:
    Players(){}
    ~Players(){}

    //void makeMove();

    void setPlayerTurn(int);
    int getPlayerTurn();
    //void setPlayer1Score();
    //int getPlayer1Score();
    void setPlayer1Move(char);
    char getPlayer1Move();
    void setPlayer2Move(char);
    char getPlayer2Move();


private:
    int player1Score = 0;
    int player2Score = 0;
    int playerTurn = 1;
    char player1Move;
    char player2Move;
};

#endif // PLAYER_H
