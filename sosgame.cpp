#include "sosgame.h"

// Constructor for UI
SOSGame::SOSGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SOSGame)
{
    ui->setupUi(this);

    // Timer delay for computer players
    computerMoveTimer = new QTimer(this);
    connect(computerMoveTimer, SIGNAL(timeout()), this, SLOT(simulateComputerTurn()));

}

// Deconstructor for UI
SOSGame::~SOSGame()
{
    delete ui;
}


// Slider allows player to choose between 3x3-10x10 board size
void SOSGame::on_BoardSizeSlider_valueChanged(int value)
{
    ui->BoardSizeOutput->setText(QString::number(value));
    boardSize = value;
}


// Starts game and creates board if gametype has been chosen, else message appears to choose one
void SOSGame::on_StartButton_clicked()
{
    if (GameType != 'S' && GameType != 'G'){
        QMessageBox::critical(this, "Unable to start the game", "You must choose a Simple or General game mode");
    }

    if ((GamePlayers.getPlayer1Human() != 0 && GamePlayers.getPlayer1Human() != 1) ||
        (GamePlayers.getPlayer2Human() != 0 && GamePlayers.getPlayer2Human() != 1))
    {
        QMessageBox::critical(this, "Unable to start the game", "You must choose an option for Player 1 and Player 2 as a computer or player");
    }

    else{
        resetGame();
        int size = ui->BoardSizeSlider->value();
        createGameBoard(size);
    }
}

// Creates game board UI and vector based on board size slider
void SOSGame::createGameBoard(int boardSize) {
    GamePlayers.setPlayerTurn(1);
    ui->SOSGameBoard->clearContents();
    ui->SOSGameBoard->setRowCount(boardSize);
    ui->SOSGameBoard->setColumnCount(boardSize);

    std::vector<std::vector<QPushButton*>> vectorBoard(boardSize, std::vector<QPushButton*>(boardSize, nullptr));

    // Calculate the size for each button
    int buttonSize = 490 / boardSize;

    // Iterate to create the game board based on board size chosen
    for (int i = 0; i < boardSize; i++) { // row
        for (int j = 0; j < boardSize; j++) { // column
            QPushButton* button = new QPushButton();
            button->setText("");
            button->setFixedSize(buttonSize, buttonSize);
            ui->SOSGameBoard->setCellWidget(i, j, button);
            vectorBoard[i][j] = button;

            connect(button, SIGNAL(clicked()), this, SLOT(gameBoardButtonClick()));
        }
    }

    // Set size policies and stretch properties of gameboard
    ui->SOSGameBoard->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->SOSGameBoard->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->SOSGameBoard->horizontalHeader()->setMinimumSectionSize(buttonSize);
    ui->SOSGameBoard->verticalHeader()->setMinimumSectionSize(buttonSize);

    setGameState(boardSize, vectorBoard);

    ui->SOSGameBoard->resizeColumnsToContents();
    ui->SOSGameBoard->resizeRowsToContents();

    ui->currentTurnLabel->setText("Current turn: Player " + QString::number(GamePlayers.getPlayerTurn()));

    if (GamePlayers.getPlayer1Human() == 0 && GamePlayers.getPlayer2Human() == 0){
        startComputerVsComputer();
    }

    else if (GamePlayers.getPlayer1Human() == 0){
        makeComputerMove(GamePlayers.getPlayerTurn());
        GamePlayers.setPlayerTurn(2);
        ui->currentTurnLabel->setText("Current turn: Player " + QString::number(GamePlayers.getPlayerTurn()));
    }
}


// Resizes vector and sets gameboard to vector of vectors of pushbuttons
void SOSGame::setGameState(int boardSize, std::vector<std::vector<QPushButton*>>& board){
    vectorBoard.resize(boardSize, std::vector<QPushButton*> (boardSize, nullptr));
    vectorBoard = board;
}


// Gets the vector gameboard state
std::vector<std::vector<QPushButton*>> SOSGame::getGameState(){
    return vectorBoard;
}


//  Sets game type to simple on button click and start
void SOSGame::on_SimpleGameButton_clicked()
{
    setGameType('S');
}


//  Sets game type to general on button click and start
void SOSGame::on_GeneralGameButton_clicked()
{
    setGameType('G');
}


//  Sets game type to simple or general
void SOSGame::setGameType(char gameType)
{
    GameType = gameType;
}


//  Gets game type
char SOSGame::getGameType()
{
    return GameType;
}


// Sets player move on button click, player move on board checked based on game type for SOS, draw and game end
void SOSGame::gameBoardButtonClick(){
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender()); // Used from ChatGPT

    if (!clickedButton) {  // Handles the case where user does not click a QPushbutton
        return;
    }

    QModelIndex buttonIndex = ui->SOSGameBoard->indexAt(clickedButton->pos());
    int row = buttonIndex.row(); // Get the row of the clicked button
    int column = buttonIndex.column(); // Get the column of the clicked button

    int playerTurn = GamePlayers.getPlayerTurn();

    char GameMode = getGameType();

    if (GameMode == 'S'){
        //  Sets player 1 move to S or O as blue text
        if (playerTurn == 1){
            if (clickedButton->text()== ""){
            clickedButton->setText(GamePlayers.getPlayer1Move());
            clickedButton->setStyleSheet("color: blue;");
                if (clickedButton->text() != ""){
                    isSimpleGameOver(row, column, vectorBoard, boardSize);
                    GamePlayers.switchPlayerTurn();
                    ui->currentTurnLabel->setText("Current turn: Player " + QString::number(GamePlayers.getPlayerTurn()));
                    ;
                    if (GamePlayers.getPlayer2Human() == 0){
                        makeComputerMove(GamePlayers.getPlayerTurn());
                        GamePlayers.switchPlayerTurn();
                    }
                }               
            }
        }

        //  Sets player 2 move to S or O as red text
        else if (playerTurn == 2){
            if (clickedButton->text()== ""){
            clickedButton->setText(GamePlayers.getPlayer2Move());
            clickedButton->setStyleSheet("color: red;");
                if (clickedButton->text() != ""){
                    isSimpleGameOver(row, column, vectorBoard, boardSize);
                    GamePlayers.switchPlayerTurn();
                    ui->currentTurnLabel->setText("Current turn: Player " + QString::number(GamePlayers.getPlayerTurn()));
                    if (GamePlayers.getPlayer1Human() == 0){
                        makeComputerMove(GamePlayers.getPlayerTurn());
                        GamePlayers.switchPlayerTurn();
                    }
                }
            }
        }
        else{
            QMessageBox::critical(this, "You must choose an S or O", "");
        }
    }

    else if (GameMode == 'G'){
        //  Sets player 1 move to S or O as blue text
        if (playerTurn == 1){
            if (clickedButton->text()== ""){
            clickedButton->setText(GamePlayers.getPlayer1Move());
            clickedButton->setStyleSheet("color: blue;");
                if (clickedButton->text() != ""){
                    isGeneralGameOver(row, column, vectorBoard, boardSize);
                    ui->currentTurnLabel->setText("Current turn: Player " + QString::number(GamePlayers.getPlayerTurn()));
                    if (GamePlayers.getPlayer2Human() && GamePlayers.getPlayerTurn() == 2){
                        while (GamePlayers.getPlayerTurn() == 2){
                            makeComputerMove(GamePlayers.getPlayerTurn());
                        }
                    }
                }
            }
        }

        //  Sets player 2 move to S or O as red text
        else if (playerTurn == 2){
            if (clickedButton->text()== ""){
            clickedButton->setText(GamePlayers.getPlayer2Move());
            clickedButton->setStyleSheet("color: red;");
                if (clickedButton->text() != ""){
                    isGeneralGameOver(row, column, vectorBoard, boardSize);
                    ui->currentTurnLabel->setText("Current turn: Player " + QString::number(GamePlayers.getPlayerTurn()));
                    if (GamePlayers.getPlayer1Human() == 0 && GamePlayers.getPlayerTurn() == 1){
                        while (GamePlayers.getPlayerTurn() == 1){
                            makeComputerMove(GamePlayers.getPlayerTurn());
                        }
                    }
                }
            }
        }
        else{
            QMessageBox::critical(this, "You must choose an S or O", "");
        }
    }
}

//  Checks board to see if simple game is over by the board being completely filled or an SOS has been created
bool SOSGame::isSimpleGameOver(int row, int column, std::vector<std::vector<QPushButton*>> gameBoard, int boardSize) {
    // Check for SOS
    SimpleGame game;

    if (game.checkGameCompletion(gameBoard)){
        QMessageBox::information(this, "Game Over", "Game ends in a draw!");
    }
    if (game.checkForSOS(row, column, gameBoard, boardSize)) {
        // Determine the winner based on the current player turn
        int playerTurn = GamePlayers.getPlayerTurn();
        QString winner;
        if (playerTurn == 1) {
            winner = "Player 1";
            ui->player1Score->setText("1");
        } else if (playerTurn == 2) {
            winner = "Player 2";
            ui->player1Score->setText("1");
        }

        // Show a QMessageBox declaring the winner
        QMessageBox::information(this, "Game Over", winner + " wins!");

        gameOverOptions();

        GameOver = true;

        return true; // The game is over
    }

    GameOver = false;
    return false; // The game is not over
}

// Checks board to see if general game is over be board being completely full, player score increased for SOS's created
bool SOSGame::isGeneralGameOver(int row, int column, std::vector<std::vector<QPushButton*>> gameBoard, int boardSize) {
    // Check for SOS
    GeneralGame game;
    int playerTurn = GamePlayers.getPlayerTurn();

    if (game.checkForSOS(row, column, gameBoard, boardSize)) {
        // Determine the winner based on the current player turn
        if (playerTurn == 1){
            game.addTotalCreatedSOSCount(player1Score, row, column, gameBoard, boardSize);
            ui->player1Score->setText(QString::number(player1Score));
        }
        else if (playerTurn == 2){
            game.addTotalCreatedSOSCount(player2Score, row, column, gameBoard, boardSize);
            ui->player2Score->setText(QString::number(player2Score));
        }
    }
    else{
        GamePlayers.switchPlayerTurn();
        ui->currentTurnLabel->setText("Current turn: Player " + QString::number(GamePlayers.getPlayerTurn()));
    }

    if (game.checkGameCompletion(gameBoard)){
        QString winner;
        if (player1Score > player2Score) {
            winner = "Player 1 wins!";
        }
        else if (player1Score < player2Score) {
            winner = "Player 2 wins!";
        }
        else{
            winner = "Game ends in a draw!";
        }

        // Show a QMessageBox declaring the winner
        QMessageBox::information(this, "Game Over", winner);

        gameOverOptions();

        GameOver = true;

        return true; // The game is over
    }

    GameOver = false;
    return false; // The game is not over
}


// Makes move for computer player 1 or 2
void SOSGame::makeComputerMove(int player) {
    // Randomly choose an empty cell
    int row, column;
    bool found = false;

    srand(time(0)); // Random number generator

    while (!found) {
        row = rand() % boardSize; // Random row
        column = rand() % boardSize; // Random column
        computerMoveRow = row;
        computerMoveColumn = column;
        QPushButton* button = vectorBoard[row][column]; // Random button

        if (button && button->text().isEmpty()) {
            found = true;
            QString computerChoice = (rand() % 2 == 0) ? "S" : "O"; // ChatGPT algorithm to randomly get 'S' or 'O'
            // Makes the move
            if (player == 1){
                button->setText(computerChoice); // Set to 'S' or 'O' based on computer's choice
                button->setStyleSheet("color: blue;"); // Example style
            }
            else if (player == 2){
                button->setText(computerChoice); // Set to 'S' or 'O' based on computer's choice
                button->setStyleSheet("color: red;"); // Example style
            }

            // Check for game over conditions
            if (getGameType() == 'S') {
                isSimpleGameOver(row, column, vectorBoard, boardSize);
            } else if (getGameType() == 'G') {
                isGeneralGameOver(row, column, vectorBoard, boardSize);
            }
        }
    }
}


// Simulates a game where both players are computer players
void SOSGame::simulateComputerTurn() {
    // Make a computer move
    makeComputerMove(GamePlayers.getPlayerTurn());

    // Check if the game is over based on the game type
    bool gameEnded;
    if (getGameType() == 'S') {
        gameEnded = isSimpleGameOver(computerMoveRow, computerMoveColumn, vectorBoard, boardSize);
    } else if (getGameType() == 'G') {
        gameEnded = isGeneralGameOver(computerMoveRow, computerMoveColumn, vectorBoard, boardSize);
    } else {
        // Handle unexpected game type, if necessary
        gameEnded = false;
    }

    if (gameEnded) {
        computerMoveTimer->stop(); // Stop the timer if the game is over
    } else {
        GamePlayers.switchPlayerTurn(); // Switch turns for the next move
        ui->currentTurnLabel->setText("Current turn: Player " + QString::number(GamePlayers.getPlayerTurn()));
    }
}


// Starts game of computer vs computer setting computer move delay
void SOSGame::startComputerVsComputer() {
    computerMoveTimer->start(1000);
}


// Options when the game is over
void SOSGame::gameOverOptions() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Game Over");
    msgBox.setText("Would you like to restart or continue?");
    QPushButton *restartButton = msgBox.addButton("Restart", QMessageBox::ActionRole);
    QPushButton *continueButton = msgBox.addButton("Continue", QMessageBox::ActionRole);

    msgBox.exec();

    if (msgBox.clickedButton() == restartButton) {
        resetGame();
        ui->StartButton->click();
    } else if (msgBox.clickedButton() == continueButton) {
        // Message box will close and game will continue
    }
}

// Updates player 1 move to 'S'
void SOSGame::on_player1_S_clicked()
{
    GamePlayers.setPlayer1Move("S");
}

// Updates player 2 move to 'O'
void SOSGame::on_player1_O_clicked()
{
    GamePlayers.setPlayer1Move("O");
}

// Updates player 2 move to 'S'
void SOSGame::on_player2_S_clicked()
{
    GamePlayers.setPlayer2Move("S");
}

// Updates player 2 move to 'O'
void SOSGame::on_player2_O_clicked()
{
    GamePlayers.setPlayer2Move("O");
}

// Exit button
void SOSGame::on_pushButton_clicked()
{
    exit(1);
}

// Resets game and scores
void SOSGame::resetGame(){
    ui->player1Score->setText("0");
    ui->player2Score->setText("0");
    player1Score = 0;
    player2Score = 0;
    GamePlayers.setPlayerTurn(1);
}

// Sets player 1 to human or computer
void SOSGame::on_player1Human_clicked(){
    GamePlayers.setPlayer1Human(1);
}

void SOSGame::on_player1Computer_clicked(){
    GamePlayers.setPlayer1Human(0);
}

// Sets player 2 to human or computer
void SOSGame::on_player2Human_clicked(){
    GamePlayers.setPlayer2Human(1);
}

void SOSGame::on_player2Computer_clicked(){
    GamePlayers.setPlayer2Human(0);
}

// Prints vector in console for testing and visual look of board
void SOSGame::printVectorBoard(const std::vector<std::vector<QPushButton*>>& vectorBoard) {
    for (const auto& row : vectorBoard) {
        QString rowText;
        for (const auto& button : row) {
            if (button) {
                rowText += button->text() + "";
            } else {
                rowText += "nullptr "; // Handle empty buttons
            }
        }
    }
}
