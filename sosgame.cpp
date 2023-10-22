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
    SimpleGame game;
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



    // Iterate to create the game board based on board size chosen
    for (int i = 0; i < boardSize; i++){
        for (int j= 0; j < boardSize; j++){
            //ui->SOSGameBoard->setItem(i,j, new QTableWidgetItem());
            QPushButton* button = new QPushButton();
            button->setText("");
            button->setBaseSize(500 / boardSize, 500 / boardSize);
            //ui->SOSGameBoard->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->SOSGameBoard->setCellWidget(i,j,(QWidget*)button);
            //ui->SOSGameBoard->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            connect(button, SIGNAL(clicked()), this, SLOT(gameBoardButtonClick()));
            ui->SOSGameBoard->setColumnWidth(i, 340 / boardSize);
            ui->SOSGameBoard->setRowHeight(j, 338 / boardSize);

        }
    }

    //ui->SOSGameBoard->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    //ui->SOSGameBoard->setMaximumWidth(boardSize * 30);


}

//  Previously used code for the gameboard, not currently used
/*  Creates a gameboard using QGridTable
std::vector<Cell> SOSGame::buildCellButtons(int boardSize) {
        // Create a 2D vector to hold the Cell objects
        std::vector<Cell> gameBoard;
        gameBoard.reserve(boardSize * boardSize);

        // Clear the existing buttons from the layout (if any)
        QLayoutItem* item;
        while ((item = ui->GameBoard->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }

        // Initialize the 2D vector with empty Cell objects

        // Create buttons and populate the grid layout
        for (int row = 0; row < boardSize; ++row) {
            for (int col = 0; col < boardSize; ++col) {
                QPushButton* button = new QPushButton(this);
                button->setProperty("cell", true); // You can set text or properties here
                ui->GameBoard->addWidget(button, row, col);

                // Connection for click signal
                connect(button, &QPushButton::clicked, this, &Player::makeMove());

                // Create and store the Cell object
                gameBoard.emplace_back(button, row, col);
            }
        }

        return gameBoard;
}
*/



void SOSGame::on_SimpleGameButton_clicked()
{
    setGameType('S');
}



void SOSGame::on_GeneralGameButton_clicked()
{
    setGameType('G');
}



void SOSGame::setGameType(char gameType)
{
    GameType = gameType;
}



char SOSGame::getGameType()
{
    return GameType;
}



void SOSGame::gameBoardButtonClick(){
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender()); // Used from ChatGPT

    if (!clickedButton) {  // Handles the case where user does not click a QPushbutton
        return;
    }
    else{
        int row = ui->SOSGameBoard->row(clickedButton); // Get the row of the clicked button
        int column = ui->SOSGameBoard->column(clickedButton); // Get the column of the clicked button
    }

    int playerTurn = GamePlayers.getPlayerTurn();

    char GameMode = getGameType();

    QTableWidgetItem* item = ui->SOSGameBoard->item(row, column);


    if (GameMode == 'S'){
        //  Sets player 1 move to S or O as blue text
        if (playerTurn == 1){
            if (clickedButton->text()== ""){
            clickedButton->setText(GamePlayers.getPlayer1Move());
            item->setText(clickedButton->text());
            clickedButton->setStyleSheet("color: blue;");
                if (clickedButton->text() != ""){
                    isGameOver(row, column, ui->SOSGameBoard, boardSize);
                    GamePlayers.switchPlayerTurn();
                }
            }
        }

        //  Sets player 2 move to S or O as red text
        else if (playerTurn == 2){
            if (clickedButton->text()== ""){
            clickedButton->setText(GamePlayers.getPlayer2Move());
            item->setText(clickedButton->text());;
            clickedButton->setStyleSheet("color: red;");
                if (clickedButton->text() != ""){
                    isGameOver(row, column, ui->SOSGameBoard, boardSize);
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
            item->setText(clickedButton->text());
            clickedButton->setStyleSheet("color: blue;");
                if (clickedButton->text() != ""){
                    GamePlayers.switchPlayerTurn();
                }
            }
        }

        //  Sets player 2 move to S or O as red text
        else if (playerTurn == 2){
            if (clickedButton->text()== ""){
            clickedButton->setText(GamePlayers.getPlayer2Move());
            item->setText(clickedButton->text());
            clickedButton->setStyleSheet("color: red;");
                if (clickedButton->text() != ""){
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


bool SOSGame::isGameOver(int row, int column, QTableWidget* gameBoard, int boardSize) {
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

