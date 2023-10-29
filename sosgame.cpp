#include "sosgame.h"

SOSGame::SOSGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SOSGame)
{
    ui->setupUi(this);


}

SOSGame::~SOSGame()
{
    delete ui;
}



void SOSGame::on_BoardSizeSlider_valueChanged(int value)
{
    ui->BoardSizeOutput->setText(QString::number(value));
    boardSize = value;
}



void SOSGame::on_StartButton_clicked()
{
    //Check and set game mode based on Simple or General game mode radio buttons
    SimpleGame SGame;
    if (GameType != 'S' && GameType != 'G'){
        QMessageBox::critical(this, "You must choose a Simple or General game mode", "");
    }
    else{
        int size = ui->BoardSizeSlider->value();
        createGameBoard(size);
    }


    //std::vector<Cell> GameState = buildCellButtons(size); // Creates game board using QGridTable

}


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


// Sets player move on button click
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
                }
            }
        }
        else{
            QMessageBox::critical(this, "You must choose an S or O", "");
        }
    }
}


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
        } else if (playerTurn == 2) {
            winner = "Player 2";
        }

        // Show a QMessageBox declaring the winner
        QMessageBox::information(this, "Game Over", winner + " wins!");

        return true; // The game is over
    }

    return false; // The game is not over
}


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
            winner = "Game is a draw!";
        }

        // Show a QMessageBox declaring the winner
        QMessageBox::information(this, "Game Over", winner);

        return true; // The game is over
    }

    return false; // The game is not over
}

void SOSGame::on_player1_S_clicked()
{
    GamePlayers.setPlayer1Move("S");
}



void SOSGame::on_player1_O_clicked()
{
    GamePlayers.setPlayer1Move("O");
}



void SOSGame::on_player2_S_clicked()
{
    GamePlayers.setPlayer2Move("S");
}




void SOSGame::on_player2_O_clicked()
{
    GamePlayers.setPlayer2Move("O");
}


void SOSGame::on_pushButton_clicked()
{
    exit(1);
}

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
        qDebug() << rowText;
    }
}
