#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <QPainter>


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
    checkGameCompletion();

private:

protected:
    // Highlights the 3 pushbuttons that form SOS
    QPen highlightPen;


};

#endif // GAMEMODE_H
