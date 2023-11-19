#include "pch.h"
#include "gamemode.h"

// Player 1 getter and setter tests
TEST(PlayersTest, SetAndGetPlayer1Type) {
    Players players;

    players.setPlayer1Human(1); // Set player 1 as human
    EXPECT_EQ(players.getPlayer1Human(), 1);

    players.setPlayer1Human(0); // Set player 1 as computer
    EXPECT_EQ(players.getPlayer1Human(), 0);
}

// Player 2 getter and setter tests
TEST(PlayersTest, SetAndGetPlayer2Type) {
    Players players;

    players.setPlayer2Human(1); // Set player 2 as human
    EXPECT_EQ(players.getPlayer2Human(), 1);

    players.setPlayer2Human(0); // Set player 2 as computer
    EXPECT_EQ(players.getPlayer2Human(), 0);
}

// Tests computer move is a valid move
TEST(SOSGameTest, MakeComputerMove_ValidMove) {
    SOSGame game;
    game.boardSize = 3;
    game.initializeBoard(); // Initialize the board

    Move move = game.makeComputerMove(1);

    // Check if a move was made on an empty cell
    EXPECT_GE(move.row, 0);
    EXPECT_GE(move.column, 0);
    EXPECT_TRUE(move.symbol == 'S' || move.symbol == 'O');
    EXPECT_FALSE(game.vectorBoard[move.row][move.column].empty());
}

//  Tests computer move is valid in partially filled board
TEST(SOSGameTest, MakeComputerMove_PartiallyFilledBoard) {
    SOSGame game;
    game.boardSize = 3;
    game.initializeBoard();

    // Pre-fill some cells
    game.vectorBoard[0][0] = "S";
    game.vectorBoard[0][1] = "O";

    Move move = game.makeComputerMove(1);

    // Ensure the move is not on a pre-filled cell
    EXPECT_FALSE(move.row == 0 && move.column == 0);
    EXPECT_FALSE(move.row == 0 && move.column == 1);
    EXPECT_TRUE(move.symbol == 'S' || move.symbol == 'O');
}

// Tests computer moves for multiple players
TEST(SOSGameTest, MakeComputerMove_DifferentPlayers) {
    SOSGame game;
    game.boardSize = 3;
    game.initializeBoard();

    Move movePlayer1 = game.makeComputerMove(1);
    Move movePlayer2 = game.makeComputerMove(2);

    // Check if moves are on the board and not overlapping
    EXPECT_TRUE(movePlayer1.row >= 0 && movePlayer1.row < 3);
    EXPECT_TRUE(movePlayer1.column >= 0 && movePlayer1.column < 3);
    EXPECT_TRUE(movePlayer2.row >= 0 && movePlayer2.row < 3);
    EXPECT_TRUE(movePlayer2.column >= 0 && movePlayer2.column < 3);
    EXPECT_FALSE(movePlayer1.row == movePlayer2.row && movePlayer1.column == movePlayer2.column);
}

// Tests that symbols placed by computer are S or O
TEST(SOSGameTest, MakeComputerMove_SymbolAssignment) {
    SOSGame game;
    game.boardSize = 3;
    game.initializeBoard();

    // Make a move for each player
    Move movePlayer1 = game.makeComputerMove(1);
    Move movePlayer2 = game.makeComputerMove(2);

    // Check if the correct symbol is placed
    EXPECT_TRUE(game.vectorBoard[movePlayer1.row][movePlayer1.column] == "S" ||
        game.vectorBoard[movePlayer1.row][movePlayer1.column] == "O");
    EXPECT_TRUE(game.vectorBoard[movePlayer2.row][movePlayer2.column] == "S" ||
        game.vectorBoard[movePlayer2.row][movePlayer2.column] == "O");
}