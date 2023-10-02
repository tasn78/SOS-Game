#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Players {
public:
    Players(){}
    ~Players(){}

    //void makeMove();

    void setPlayerTurn(int);
    int getPlayerTurn();
    //void setPlayer1Score();
    //int getPlayer1Score();
    void setPlayer1Move(QString);
    QString getPlayer1Move();
    void setPlayer2Move(QString);
    QString getPlayer2Move();


private:
    int player1Score = 0;
    int player2Score = 0;
    int playerTurn = 1;
    QString player1Move;
    QString player2Move;
};

#endif // PLAYER_H
