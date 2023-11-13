#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Players {
public:
    Players(){}
    ~Players(){}

    //void makeMove();

    // Sets player turn
    void setPlayerTurn(int);

    // Gets current player's turn
    int getPlayerTurn();

    //  Switches player from 1 to 2 or 2 to 1
    void switchPlayerTurn();

    //void setPlayer1Score();
    //int getPlayer1Score();

    // Sets player 1's move as S or O from radio buttons
    void setPlayer1Move(QString);

    // Gets player 1's current move from S or O radio buttons
    QString getPlayer1Move();

    // Sets player 2's move as S or O from radio buttons
    void setPlayer2Move(QString);

    // Gets player 2's current move from S or O radio buttons
    QString getPlayer2Move();

    // Setter and getter for player 1, human (1) or computer (0)
    void setPlayer1Human(int);
    int getPlayer1Human();

    // Setter and getter for player 2, human (1) or computer (0)
    void setPlayer2Human(int);
    int getPlayer2Human();

private:
    int player1Score = 0;
    int player2Score = 0;
    int playerTurn = 1;
    QString player1Move;
    QString player2Move;
    int player1Human;
    int player2Human;
};

#endif // PLAYER_H
