#include "pch.h"
#include "player.h"


// Tests the setPlayerTurn function
TEST(PlayersTest, SetPlayerTurn) {
    Players player;

    // Tests setting player turn to 1
    player.setPlayerTurn(1);
    EXPECT_EQ(player.getPlayerTurn(), 1);

    // Tests setting player turn to 2
    player.setPlayerTurn(2);
    EXPECT_EQ(player.getPlayerTurn(), 2);
}


// Tests the switchPlayerTurn function
TEST(PlayersTest, SwitchPlayerTurn) {
    Players player;

    // Initial player turn should be 1
    EXPECT_EQ(player.getPlayerTurn(), 1);

    // After switching, player turn should be 2
    player.switchPlayerTurn();
    EXPECT_EQ(player.getPlayerTurn(), 2);

    // After switching again, player turn should be back to 1
    player.switchPlayerTurn();
    EXPECT_EQ(player.getPlayerTurn(), 1);
}


// Tests the Setters and Getters for Player1Move (S or O)
TEST(PlayersTest, SetAndGetPlayer1Move) {
    Players player;

    //  Sets player move to S and tests
    player.setPlayer1Move("S");
    EXPECT_EQ(player.getPlayer1Move(), "S");


    //  Sets player move to O and tests
    player.setPlayer1Move("O");
    EXPECT_EQ(player.getPlayer1Move(), "O");
}


// Tests the Setters and Getters for Player2Move (S or O)
TEST(PlayersTest, SetAndGetPlayer2Move) {
    Players player;

    //  Sets player move to S and tests
    player.setPlayer2Move("S");
    EXPECT_EQ(player.getPlayer2Move(), "S");

    //  Sets player move to O and tests
    player.setPlayer2Move("O");
    EXPECT_EQ(player.getPlayer2Move(), "O");
}