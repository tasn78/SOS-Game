#ifndef GAMEDEFAULTS_H
#define GAMEDEFAULTS_H
#include <cstddef>

//  Gamedefaults was used from https://github.com/aosama16/Qt-Tic-Tac-Toe

class QPushButton;
namespace defaults
{
constexpr short INVALID_CELL = -1;
constexpr size_t DEFAULT_BOARD_SIZE = 3;
constexpr unsigned short DEFAULT_MINIMAX_DEPTH = 3;
constexpr unsigned short GUI_CELL_ROW_SPAN = 1;
constexpr unsigned short GUI_CELL_COLUMN_SPAN = 1;
constexpr char DEFAULT_COLOR[] = "#FFF";
}


// Struct cell represents each square within a 3x3-10x10 game board
struct Cell
{
    QPushButton *cellBtn = nullptr;
    int row = defaults::INVALID_CELL;
    int col = defaults::INVALID_CELL;
    Cell(QPushButton *cellBtn, int row, int col)
        : cellBtn(cellBtn), row(row), col(col) {}
};


// Creates base boardsize of 3 and min depth
struct SOSOptions
{
    size_t boardSize = defaults::DEFAULT_BOARD_SIZE;
    unsigned short miniMaxDepth = defaults::DEFAULT_MINIMAX_DEPTH;
};


//  The different moves a player can make S or O, as well as an unplayed cell - Empty
enum class BoardMarks { Empty, S, O };


//  Possible outcomes of a game
enum class BoardState { Draw, Player1Wins, Player2Wins, Tie };

#endif // GAMEDEFAULTS_H
