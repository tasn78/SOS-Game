#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <QPainter>
#include <QTableWidget>
#include <ui_sosgame.h>


class GameMode
{
public:
    // Default constructor
    GameMode();
    // Destructor
    ~GameMode();

    // Checks for SOS on GameBoard
    void checkForSOS();

    // Checks for a win or draw
    virtual bool checkForWin(QTableWidget* gameBoard) = 0;

    // Checks if GameBoard is full
    virtual bool checkGameCompletion(QTableWidget* gameBoard) = 0;

private:

protected:
    // Highlights the 3 pushbuttons that form SOS
    QPen highlightPen;


};

#endif // GAMEMODE_H
