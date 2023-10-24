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
    ui->SOSGameBoard->setBaseSize(500, 500);

    std::vector<std::vector<QPushButton*>> vectorBoard(boardSize, std::vector<QPushButton*>(boardSize, nullptr));

    // Iterate to create the game board based on board size chosen
    for (int i = 0; i < boardSize; i++){ // i = row
        for (int j= 0; j < boardSize; j++){ // j = column
            //ui->SOSGameBoard->setItem(i,j, new QTableWidgetItem());
            QPushButton* button = new QPushButton();
            //button->setFixedSize(size());
            //button->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
            button->setText("");
            //button->setBaseSize(500 / boardSize, 500 / boardSize);
            //ui->SOSGameBoard->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->SOSGameBoard->setCellWidget(i,j,(QWidget*)button);
            vectorBoard[i][j] = button;
            //ui->SOSGameBoard->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            connect(button, SIGNAL(clicked()), this, SLOT(gameBoardButtonClick()));
            ui->SOSGameBoard->setColumnWidth(i, 440 / boardSize);
            ui->SOSGameBoard->setRowHeight(j, 438 / boardSize);

        }
    }
    setGameState(boardSize, vectorBoard);

    for (int i = 0; i < boardSize; i++){ // i = row
        for (int j= 0; j < boardSize; j++){ // j = column
            ui->SOSGameBoard->cellWidget(i,j)->setFixedSize(size());
            ui->SOSGameBoard->cellWidget(i,j)->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);

        }
    }
}


// Resizes vector and sets gameboard to vector of vectors of pushbuttons
void SOSGame::setGameState(int boardSize, std::vector<std::vector<QPushButton*>> board){
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
    std::vector<std::vector<QPushButton*>> board;
    board.resize(boardSize, std::vector<QPushButton*> (boardSize, nullptr));
    board = getGameState();

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
            //item->setText(clickedButton->text());
            clickedButton->setStyleSheet("color: blue;");
                if (clickedButton->text() != ""){
                    isGameOver(row, column, board, boardSize);
                    GamePlayers.switchPlayerTurn();
                }
            }
        }

        //  Sets player 2 move to S or O as red text
        else if (playerTurn == 2){
            if (clickedButton->text()== ""){
            clickedButton->setText(GamePlayers.getPlayer2Move());
            //item->setText(clickedButton->text());;
            clickedButton->setStyleSheet("color: red;");
                if (clickedButton->text() != ""){
                    isGameOver(row, column, board, boardSize);
                    GamePlayers.switchPlayerTurn();
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
            //item->setText(clickedButton->text());
            clickedButton->setStyleSheet("color: blue;");
                if (clickedButton->text() != ""){
                    isGameOver(row, column, board, boardSize);
                    GamePlayers.switchPlayerTurn();
                }
            }
        }

        //  Sets player 2 move to S or O as red text
        else if (playerTurn == 2){
            if (clickedButton->text()== ""){
            clickedButton->setText(GamePlayers.getPlayer2Move());
            //item->setText(clickedButton->text());
            clickedButton->setStyleSheet("color: red;");
                if (clickedButton->text() != ""){
                    isGameOver(row, column, board, boardSize);
                    GamePlayers.switchPlayerTurn();
                }
            }
        }
        else{
            QMessageBox::critical(this, "You must choose an S or O", "");
        }
    }



    // Check if player 1 or 2 move created an SOS on click

}


bool SOSGame::isGameOver(int row, int column, std::vector<std::vector<QPushButton*>>& gameBoard, int boardSize) {
    // Check for SOS
    SimpleGame game;
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
