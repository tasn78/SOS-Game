#include "sosgame.h"
#include <QTextStream>

// Constructor for UI
SOSGame::SOSGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SOSGame)
{
    ui->setupUi(this);

    // Timer delay for computer players
    computerMoveTimer = new QTimer(this);
    connect(computerMoveTimer, SIGNAL(timeout()), this, SLOT(simulateComputerTurn()));
    replayTimer = new QTimer(this);
    connect(replayTimer, &QTimer::timeout, this, &SOSGame::performReplayStep);
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
        if (ui->RecordGameBox->isChecked()) {
            startRecording();
        }
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
                if (ui->RecordGameBox->isChecked()) {
                        GameMove move;
                        move.player = GamePlayers.getPlayerTurn();
                        move.row = row;
                        move.column = column;
                        move.symbol = clickedButton->text().toStdString()[0];
                        recordMove(move);
                    }
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
                if (ui->RecordGameBox->isChecked()) {
                        GameMove move;
                        move.player = GamePlayers.getPlayerTurn();
                        move.row = row;
                        move.column = column;
                        move.symbol = clickedButton->text().toStdString()[0];
                        recordMove(move);
                    }
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
                if (ui->RecordGameBox->isChecked()) {
                        GameMove move;
                        move.player = GamePlayers.getPlayerTurn();
                        move.row = row;
                        move.column = column;
                        move.symbol = clickedButton->text().toStdString()[0];
                        recordMove(move);
                    }
                if (clickedButton->text() != ""){
                    isGeneralGameOver(row, column, vectorBoard, boardSize);
                    ui->currentTurnLabel->setText("Current turn: Player " + QString::number(GamePlayers.getPlayerTurn()));
                    if (GamePlayers.getPlayer2Human() == 0 && GamePlayers.getPlayerTurn() == 2){
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
                if (ui->RecordGameBox->isChecked()) {
                        GameMove move;
                        move.player = GamePlayers.getPlayerTurn();
                        move.row = row;
                        move.column = column;
                        move.symbol = clickedButton->text().toStdString()[0];
                        recordMove(move);
                    }
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
        if (!gameOverExecuted) {
            gameOverExecuted = true;
            QMessageBox::information(this, "Game Over", "Game ends in a draw!");
            gameOverOptions();
            GameOver = true;
        }
        return true; // The game is over
    }
    if (game.checkForSOS(row, column, gameBoard, boardSize)) {
        if (!gameOverExecuted) {
            gameOverExecuted = true;
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
            if (GameOver && ui->RecordGameBox->isChecked()) {
                    stopRecording();
                }
        }
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

    if (game.checkGameCompletion(gameBoard)){
        if (!gameOverExecuted) {
            gameOverExecuted = true;
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

            if (GameOver && ui->RecordGameBox->isChecked()) {
                    stopRecording();
                }
        }

        return true; // The game is over
    }


    else if (game.checkForSOS(row, column, gameBoard, boardSize)) {
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
            if (ui->RecordGameBox->isChecked()) {
                GameMove move;
                move.player = player;
                move.row = row;
                move.column = column;
                move.symbol = computerChoice.toStdString()[0];
                recordMove(move);
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
    bool gameEnded = false;
    if (GameOver) {
            computerMoveTimer->stop();
            return;
        }

    if (!GameOver){
        if (getGameType() == 'S') {
            gameEnded = isSimpleGameOver(computerMoveRow, computerMoveColumn, vectorBoard, boardSize);
        }
        else if (getGameType() == 'G') {
            gameEnded = isGeneralGameOver(computerMoveRow, computerMoveColumn, vectorBoard, boardSize);
        }
        else {
            gameEnded = false;
        }
    }

    if (gameEnded) {
        computerMoveTimer->stop(); // Stop the timer if the game is over
    }
    else {
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
    // Create a non-modal message box
    QMessageBox* msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("Game Over");
    msgBox->setText("Would you like to restart or continue?");
    QPushButton *restartButton = msgBox->addButton("Restart", QMessageBox::ActionRole);
    QPushButton *continueButton = msgBox->addButton("Continue", QMessageBox::ActionRole);
    QPushButton *closeButton = msgBox->addButton("Close Window", QMessageBox::RejectRole);

    connect(restartButton, &QPushButton::clicked, this, &SOSGame::handleRestart);
    // Continue lambda function via ChatGPT
    connect(continueButton, &QPushButton::clicked, [this, msgBox]() {
            resumeGame();
            msgBox->close();
        });
    connect(closeButton, &QPushButton::clicked, [msgBox]() {
            msgBox->close(); // Simply close the message box
        });
    msgBox->show(); // Show the message box without blocking
}

// Restarts handled for comp vs comp game
void SOSGame::handleRestart() {
    resetGame();
    ui->StartButton->click();
    gameOverExecuted = false;
}

// Resumes game after win/loss/draw
void SOSGame::resumeGame() {
    // Reset game-over flags
    GameOver = false;
    gameOverExecuted = false;

    // If computer vs computer game, restart the timer
    if (GamePlayers.getPlayer1Human() == 0 && GamePlayers.getPlayer2Human() == 0) {
        computerMoveTimer->start(1000);
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
    gameOverExecuted = false;
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

void SOSGame::on_RecordGameBox_stateChanged(int arg1){
    if (arg1 == Qt::Checked) {
        // Checkbox is checked - start recording
        startRecording();
    } else if (arg1 == Qt::Unchecked) {
        // Checkbox is unchecked - stop recording or do nothing
        stopRecording();  // Implement this function as per your requirements
    }
}


// Starts recording game
void SOSGame::startRecording() {
    file.setFileName("game_record.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        outputStream.setDevice(&file);
        char gameType = getGameType();
        outputStream << "Game Type: " << gameType << "\n";
        outputStream << "BoardSize:" << boardSize << "\n";
        outputStream << "Player,Row,Column,Symbol\n";
    } else {
        // Error handling if the file could not be opened
        QMessageBox::warning(this, "Recording Error", "Unable to open file for recording.");
        return;
    }
}

// Stops recording game
void SOSGame::stopRecording() {
    if (outputStream.device()) {
        outputStream.device()->close();
        outputStream.setDevice(nullptr);
    }
}

// Record a single move
void SOSGame::recordMove(const GameMove &move) {
    if (outputStream.device()) {
        outputStream << move.player << "," << move.row << "," << move.column << "," << move.symbol << "\n";
    }
}

// User clicks replay ability button
void SOSGame::on_ReplayGameButton_clicked(){
    loadRecordedGame(); // Load the game moves
    currentMoveIndex = 0; // Start from the first move
    replayTimer->start(1000);
}

// Loads game from txt file
void SOSGame::loadRecordedGame() {
    QFile file("game_record.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Replay Error", "Unable to open file for replay.");
        return;
    }

    QTextStream in(&file);
    QString line;
    char gameType;
    int readBoardSize;

    // Read game type and board size
    line = in.readLine(); // Read game type line
    gameType = line.split(":")[1].trimmed().toStdString()[0];

    line = in.readLine(); // Read board size line
    readBoardSize = line.split(":")[1].trimmed().toInt();

    // Set up the game for replay
    setGameType(gameType); // Adjust this function to set the game type
    initializeBoardForReplay(readBoardSize); // Implement this function to set up the board

    recordedMoves.clear(); // Clear previous moves if any
    while (!in.atEnd()) {
        line = in.readLine();
        if (line.contains("Player")) { // Skip header line
            continue;
        }
        QStringList parts = line.split(",");
        if (parts.size() == 4) {
            GameMove move;
            move.player = parts[0].toInt();
            move.row = parts[1].toInt();
            move.column = parts[2].toInt();
            move.symbol = parts[3].toStdString()[0];
            recordedMoves.append(move);
        }
    }
}

// Applies move to ui
void SOSGame::applyMove(const GameMove& move) {
    QPushButton *button = vectorBoard[move.row][move.column];
    if (button) {
        QString symbol = QString(move.symbol);
        button->setText(symbol);
        // Set appropriate styling based on the player
        if (move.player == 1) {
            button->setStyleSheet("color: blue;");
        } else if (move.player == 2) {
            button->setStyleSheet("color: red;");
        }
    }
}

// Performs one step of the replay process
void SOSGame::performReplayStep() {
    if (currentMoveIndex < recordedMoves.size()) {
        applyMove(recordedMoves[currentMoveIndex]);
        currentMoveIndex++;
    } else {
        replayTimer->stop(); // Stop the timer when all moves are replayed
    }
}

// Makes game board for replay
void SOSGame::initializeBoardForReplay(int boardSize) {
    ui->SOSGameBoard->clearContents();
    ui->SOSGameBoard->setRowCount(boardSize);
    ui->SOSGameBoard->setColumnCount(boardSize);

    vectorBoard.resize(boardSize, std::vector<QPushButton*>(boardSize, nullptr));

    int buttonSize = 490 / boardSize;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            QPushButton* button = new QPushButton();
            button->setText("");
            button->setFixedSize(buttonSize, buttonSize);
            ui->SOSGameBoard->setCellWidget(i, j, button);
            vectorBoard[i][j] = button;
        }
    }
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
