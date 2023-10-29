#include "pch.h"
#include "gamemode.h"

TEST(GameModeTest, CheckSOSRightValid) {
    GameMode gameMode;
    const int boardSize = 3;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S" },
        { "S", "O", "S" },
        { "S", "O", "S" }
    };

    // Test valid SOS pattern in right direction
    EXPECT_TRUE(gameMode.checkSOSRight(0, 0, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSRight(1, 0, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSRight(2, 0, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSRightInvalid) {
    GameMode gameMode;
    const int boardSize = 3;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S" },
        { "S", "O", "S" },
        { "S", "O", "S" }
    };

    EXPECT_FALSE(gameMode.checkSOSRight(0, 1, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSRight(1, 1, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSRight(2, 2, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSLeftValid) {
    GameMode gameMode;
    const int boardSize = 3;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S" },
        { "S", "O", "S" },
        { "S", "O", "S" }
    };

    // Test valid SOS pattern in left direction
    EXPECT_TRUE(gameMode.checkSOSLeft(0, 2, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSLeft(1, 2, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSLeft(2, 2, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSLeftInvalid) {
    GameMode gameMode;
    const int boardSize = 3;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S" },
        { "S", "O", "S" },
        { "S", "O", "S" }
    };

    EXPECT_FALSE(gameMode.checkSOSLeft(0, 0, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSLeft(1, 1, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSLeft(2, 1, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSDownValid) {
    GameMode gameMode;
    const int boardSize = 3;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S" },
        { "O", "S", "O" },
        { "S", "O", "S" }
    };

    // Test valid SOS patterns in the down direction
    EXPECT_TRUE(gameMode.checkSOSDown(0, 0, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSDown(0, 2, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSUpValid) {
    GameMode gameMode;
    const int boardSize = 3;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S" },
        { "O", "O", "O" },
        { "S", "O", "S" }
    };

    // Test valid SOS patterns in the up direction
    EXPECT_TRUE(gameMode.checkSOSUp(2, 0, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSUp(2, 2, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSDownInvalid) {
    GameMode gameMode;
    const int boardSize = 3;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S" },
        { "S", "O", "S" },
        { "S", "O", "S" }
    };

    // Test invalid SOS patterns in the down direction
    EXPECT_FALSE(gameMode.checkSOSDown(0, 0, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSDown(1, 0, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSUpInvalid) {
    GameMode gameMode;
    const int boardSize = 3;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S" },
        { "S", "O", "S" },
        { "S", "O", "S" }
    };

    // Test invalid SOS patterns in the up direction
    EXPECT_FALSE(gameMode.checkSOSUp(0, 0, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSUp(0, 1, gameBoard, boardSize));
}


TEST(GameModeTest, CheckSOSUpRightValid) {
    GameMode gameMode;
    const int boardSize = 4;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    // Initialize gameBoard with valid SOS patterns in the up-right direction
    gameBoard = {
        { "S", "O", "S", "S"},
        { "O", "O", "S", "O"},
        { "S", "O", "S", "S"},
        { "S", "O", "S", "S"}
    };

    // Test valid SOS patterns in the up-right direction
    EXPECT_TRUE(gameMode.checkSOSUpRight(2, 0, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSUpRight(3, 0, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSUpRightInvalid) {
    GameMode gameMode;
    const int boardSize = 3;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S" },
        { "O", "S", "S" },
        { "S", "O", "S" }
    };

    // Test invalid SOS patterns in the up-right direction
    EXPECT_FALSE(gameMode.checkSOSUpRight(0, 0, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSUpRight(1, 1, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSUpLeftValid) {
    GameMode gameMode;
    const int boardSize = 4;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S", "S"},
        { "S", "O", "S", "O"},
        { "S", "O", "S", "S"},
        { "S", "O", "S", "S"}
    };

    // Test valid SOS patterns in the up-left direction
    EXPECT_TRUE(gameMode.checkSOSUpLeft(3, 2, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSUpLeft(3, 2, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSUpLeftInvalid) {
    GameMode gameMode;
    const int boardSize = 3; // Adjust as needed
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S" },
        { "S", "O", "S" },
        { "O", "S", "O" }
    };

    // Test invalid SOS patterns in the up-left direction
    EXPECT_FALSE(gameMode.checkSOSUpLeft(0, 2, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSUpLeft(2, 1, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSDownRightValid) {
    GameMode gameMode;
    const int boardSize = 4;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S", "S"},
        { "S", "O", "S", "O"},
        { "S", "O", "S", "S"},
        { "S", "O", "S", "S"}
    };

    // Test valid SOS patterns in the down-right direction
    EXPECT_TRUE(gameMode.checkSOSDownRight(0, 0, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSDownRight(1, 0, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSDownRightInvalid) {
    GameMode gameMode;
    const int boardSize = 3;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S" },
        { "S", "S", "O" },
        { "O", "S", "O" }
    };

    // Test invalid SOS patterns in the down-right direction
    EXPECT_FALSE(gameMode.checkSOSDownRight(1, 0, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSDownRight(0, 2, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSDownLeftValid) {
    GameMode gameMode;
    const int boardSize = 4;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S", "S"},
        { "S", "O", "S", "O"},
        { "S", "O", "S", "S"},
        { "S", "O", "S", "S"}
    };

    // Test valid SOS patterns in the down-left direction
    EXPECT_TRUE(gameMode.checkSOSDownLeft(0, 2, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSDownLeft(1, 2, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSDownLeftInvalid) {
    GameMode gameMode;
    const int boardSize = 3;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "O" },
        { "S", "S", "O" },
        { "O", "S", "S" }
    };

    // Test invalid SOS patterns in the down-left direction
    EXPECT_FALSE(gameMode.checkSOSDownLeft(0, 2, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSDownLeft(1, 0, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSWithOInCenterValid) {
    GameMode gameMode;
    const int boardSize = 3; // Adjust as needed
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    // Initialize gameBoard with valid SOS patterns with 'O' in the center
    gameBoard = {
        { "S", "O", "S" },
        { "O", "O", "O" },
        { "S", "O", "S" }
    };

    // Test valid SOS patterns with 'O' in the center
    EXPECT_TRUE(gameMode.checkSOSWithOInCenter(1, 1, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSWithOInCenter(0, 1, gameBoard, boardSize));
}

TEST(GameModeTest, CheckSOSWithOInCenterInvalid) {
    GameMode gameMode;
    const int boardSize = 3;
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    gameBoard = {
        { "S", "O", "S" },
        { "O", "S", "O" },
        { "S", "O", "S" }
    };

    // Test invalid SOS patterns with 'O' not in the center
    EXPECT_FALSE(gameMode.checkSOSWithOInCenter(0, 0, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSWithOInCenter(2, 2, gameBoard, boardSize));
}

TEST(GameModeTest, CheckGameCompletionFullBoard) {
    GameMode gameMode;
    const int boardSize = 3; // Adjust as needed
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize, "S"));

    // The board is full with only 'S'
    EXPECT_TRUE(gameMode.checkGameCompletion(gameBoard));
}

TEST(GameModeTest, CheckGameCompletionNotFullBoard) {
    GameMode gameMode;
    const int boardSize = 3; // Adjust as needed
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    // The board is not full as some buttons contain neither 'S' nor 'O'
    EXPECT_FALSE(gameMode.checkGameCompletion(gameBoard));

    // Set a button to 'S' in the middle of the board
    gameBoard[1][1] = "S";
    // The board is still not full as not all buttons contain 'S' or 'O'
    EXPECT_FALSE(gameMode.checkGameCompletion(gameBoard));
}

TEST(GameModeTest, CheckGameCompletionMixedBoard) {
    GameMode gameMode;
    const int boardSize = 3; // Adjust as needed
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize, "O"));

    // The board is full with only 'O'
    EXPECT_TRUE(gameMode.checkGameCompletion(gameBoard));

    // Set a button to 'X' in the middle of the board
    gameBoard[1][1] = "X";
    EXPECT_FALSE(gameMode.checkGameCompletion(gameBoard));
}

TEST(GeneralGameTest, CheckForSOSValid) {
    GeneralGame generalGame;
    const int boardSize = 3; // Adjust as needed
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize, " "));

    // Set up a valid SOS pattern horizontally
    gameBoard[1][0] = "S";
    gameBoard[1][1] = "O";
    gameBoard[1][2] = "S";

    // The board contains a valid SOS pattern
    EXPECT_TRUE(generalGame.checkForSOS(1, 0, gameBoard, boardSize));
}

TEST(GeneralGameTest, CheckForSOSInvalid) {
    GeneralGame generalGame;
    const int boardSize = 3; // Adjust as needed
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize, " "));

    // No SOS pattern on the board
    EXPECT_FALSE(generalGame.checkForSOS(0, 0, gameBoard, boardSize));

    // Invalid pattern
    gameBoard[0][0] = "S";
    gameBoard[0][1] = "O";
    gameBoard[0][2] = "O";

    // The board contains an invalid pattern
    EXPECT_FALSE(generalGame.checkForSOS(0, 0, gameBoard, boardSize));
}

TEST(GeneralGameTest, AddTotalCreatedSOSCount) {
    GeneralGame generalGame;
    const int boardSize = 3; // Adjust as needed
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize, " "));

    // Initialize player score
    int playerScore = 0;

    // Set up a valid SOS pattern horizontally
    gameBoard[1][0] = "S";
    gameBoard[1][1] = "O";
    gameBoard[1][2] = "S";

    // Add the SOS count to the player's score
    generalGame.addTotalCreatedSOSCount(playerScore, 1, 1, gameBoard, boardSize);

    // The player score should increase by 1
    EXPECT_EQ(playerScore, 1);

    // Clear the board
    gameBoard = std::vector<std::vector<std::string>>(boardSize, std::vector<std::string>(boardSize, " "));

    // Set up a valid SOS pattern diagonally
    gameBoard[0][0] = "S";
    gameBoard[1][1] = "O";
    gameBoard[2][2] = "S";

    // Add the SOS count to the player's score
    generalGame.addTotalCreatedSOSCount(playerScore, 1, 1, gameBoard, boardSize);

    // The player score should increase by 2
    EXPECT_EQ(playerScore, 2);
}