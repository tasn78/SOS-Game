#include "pch.h"
#include "gamemode.h"

TEST(GameModeTest, CheckSOSRightValid) {
    GameMode gameMode;
    const int boardSize = 3; // Adjust as needed
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    // Initialize your gameBoard with 'S', 'O', and empty strings as needed

    // Add test cases for valid SOS patterns
    EXPECT_TRUE(gameMode.checkSOSRight(0, 0, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSRight(1, 1, gameBoard, boardSize));
    // Add more test cases as needed
}

TEST(GameModeTest, CheckSOSRightInvalid) {
    GameMode gameMode;
    const int boardSize = 3; // Adjust as needed
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    // Initialize your gameBoard with 'S', 'O', and empty strings as needed

    // Add test cases for invalid SOS patterns (e.g., patterns that don't form "SOS")
    EXPECT_FALSE(gameMode.checkSOSRight(0, 0, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSRight(1, 1, gameBoard, boardSize));
    // Add more test cases as needed
}

TEST(GameModeTest, CheckSOSLeftValid) {
    GameMode gameMode;
    const int boardSize = 3; // Adjust as needed
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    // Initialize your gameBoard with 'S', 'O', and empty strings as needed

    // Add test cases for valid SOS patterns
    EXPECT_TRUE(gameMode.checkSOSLeft(0, 2, gameBoard, boardSize));
    EXPECT_TRUE(gameMode.checkSOSLeft(1, 1, gameBoard, boardSize));
    // Add more test cases as needed
}

TEST(GameModeTest, CheckSOSLeftInvalid) {
    GameMode gameMode;
    const int boardSize = 3; // Adjust as needed
    std::vector<std::vector<std::string>> gameBoard(boardSize, std::vector<std::string>(boardSize));

    // Initialize your gameBoard with 'S', 'O', and empty strings as needed

    // Add test cases for invalid SOS patterns (e.g., patterns that don't form "SOS")
    EXPECT_FALSE(gameMode.checkSOSLeft(0, 0, gameBoard, boardSize));
    EXPECT_FALSE(gameMode.checkSOSLeft(1, 1, gameBoard, boardSize));
    // Add more test cases as needed
}