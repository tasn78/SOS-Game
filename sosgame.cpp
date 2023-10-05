#include "sosgame.h"
#include "ui_sosgame.h"
#include "player.h"


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
    GameMode = getGameMode();
    if (GameMode != 'S' && GameMode != 'G'){
        QMessageBox::critical(this, "You must choose a Simple or General game mode", "");
    }
    else{
        int size = ui->BoardSizeSlider->value();
        createGameBoard(size);
    }


    //std::vector<Cell> GameState = buildCellButtons(size); // Creates game board using QGridTable

}


void SOSGame::createGameBoard(int boardSize) {
    ui->SOSGameBoard->clearContents();
    ui->SOSGameBoard->setFrameStyle((QFrame::NoFrame));
    ui->SOSGameBoard->setRowCount(boardSize);
    ui->SOSGameBoard->setColumnCount(boardSize);

    for (int i = 0; i < boardSize; i++){
        for (int j= 0; j < boardSize; j++){
            ui->SOSGameBoard->setItem(i,j, new QTableWidgetItem());
            QPushButton* button = new QPushButton();
            button->setText("");
            ui->SOSGameBoard->setCellWidget(i,j,(QWidget*)button);
            button->sizeHint();
            button->setSizeIncrement(20, 20);
            connect(button, SIGNAL(clicked()), this, SLOT(gameBoardButtonClick()));
        }
    }
    ui->SOSGameBoard->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
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
    setGameMode('S');
}



void SOSGame::on_GeneralGameButton_clicked()
{
    setGameMode('G');
}



void SOSGame::setGameMode(char gameType)
{
    GameMode = gameType;
}



char SOSGame::getGameMode()
{
    return GameMode;
}



void SOSGame::gameBoardButtonClick(){
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender()); // Used from ChatGPT

    if (!clickedButton) {  // Handles the case where user does not click a QPushbutton
        return;
    }

    int playerTurn = GamePlayers.getPlayerTurn();

    if (playerTurn == 1){
        if (clickedButton->text()== ""){
        clickedButton->setText(GamePlayers.getPlayer1Move());
            if (clickedButton->text() != ""){
                GamePlayers.switchPlayerTurn();
            }
        }
    }
    else if (playerTurn == 2){
        if (clickedButton->text()== ""){
        clickedButton->setText(GamePlayers.getPlayer2Move());
            if (clickedButton->text() != ""){
            GamePlayers.switchPlayerTurn();
            }
        }
    }
    else{
        QMessageBox::critical(this, "You must choose an S or O", "");
    }


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

