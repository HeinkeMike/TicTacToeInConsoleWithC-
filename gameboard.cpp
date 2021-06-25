#include "gameboard.h"
#include <iostream>
#include <ostream>

using namespace TicTacToe;
using namespace std;


//Constructor with a dynamic size of the Field and a dynamic Amount of Players
gameboard::gameboard(int sizeOfField, int amountOfPlayers) {
    this->sizeOfField = sizeOfField;
    this->gameOver = false;

    this->board = new int*[this->sizeOfField];
    for(int i = 0; i < this->sizeOfField; i++)
    {
        this->board[i] = new int[this->sizeOfField];
        for(int j = 0; j < this->sizeOfField; j++){
            board[i][j] = 0;
        }
    }
        

    
    this->amountOfPlayers = amountOfPlayers;
    this->players = new TicTacToe::player[this->amountOfPlayers];
    for(int i = 0; i < this->amountOfPlayers; i++){
        this->players[i].setNumber(i + 1);
    }
}

//Destructor and cleanup
gameboard::~gameboard() {
    for(int i = 0; i < this->sizeOfField; i++)
        delete[] this->board[i];
    delete[] this->board;
}

//Draw function for the whole Board
void gameboard::drawGameboard() {
    for(int i = 0; i < this->sizeOfField; i++){
        for(int j = 0; j < this->sizeOfField * 2 + 1; j++){
            std::cout << "*";
        }
        std::cout << std::endl;

        for(int j = 0; j < this->sizeOfField; j++){
            std::cout << "*" << this->board[i][j];
        }
        std::cout << "*" << std::endl;
    }

    for(int j = 0; j < this->sizeOfField * 2 + 1; j++){
        std::cout << "*";
    }
    std::cout << std::endl;
}

//Just a simple play function looping the draw and askUserForTurn functions whilst the gamestate isn't in favor of one player or a tie
//Furthermore it is asking if the Player turn is done and correct
void gameboard::play() {
    int turn;
    int gamestate = 0;
    while(gamestate == 0) {
        int playerOnDuty;
        playerOnDuty = turn % this->amountOfPlayers;
        if(!this->players[playerOnDuty].getSurrendered()){
            this->drawGameboard();
            std::cout << "It is player " << (playerOnDuty + 1) << "s turn!" << std::endl;
            bool playerTurnDone;
            playerTurnDone = false;
            while (!playerTurnDone)
                playerTurnDone = askUserForTurn(playerOnDuty);
        }
        gamestate = this->checkStateOfGame();
        turn++;
    }
    
    if(gamestate > 0)
        std::cout << "Player " << gamestate << " won the game!" << std::endl;
    if(gamestate == -1) 
        std::cout << "It's a tie!" << std::endl;
}

int gameboard::checkStateOfGame() {
    int gamestate = 0;

    //Check if all players except of one have surrendered
    if(gamestate == 0){
        for(int i = 0; i < this->amountOfPlayers; i++){
            if(!this->players[i].getSurrendered()) {
                if(gamestate != 0){
                    gamestate = 0;
                    break;
                }
                gamestate = i + 1;
            }
        }
    }

    //Check if one player owns one row
    if(gamestate == 0){
        for(int i = 0; i < this->sizeOfField; i++){
            int savePlayerRow = 0;
            if(this->board[i][0] != 0){
                savePlayerRow = this->board[i][0];
                for(int j = 1; j < this->sizeOfField; j++){
                    if(savePlayerRow != this->board[i][j]){
                        savePlayerRow = gamestate;
                        break;
                    }
                }
                gamestate = savePlayerRow;
            }
        }
    }


    //Check if one player owns one column
    if(gamestate == 0){
        for(int i = 0; i < this->sizeOfField; i++){
            int savePlayerColumn = 0;
            if(this->board[0][i] != 0){
                savePlayerColumn = this->board[0][i];
                for(int j = 1; j < this->sizeOfField; j++){
                    if(savePlayerColumn != this->board[j][i]){
                        savePlayerColumn = gamestate;
                        break;
                    }
                }
                gamestate = savePlayerColumn;
            }
        }
    }

    //Check if one player owns one diagonal
    if(gamestate == 0){
        if(this->sizeOfField % 2 == 1){
            int savePlayerInDiagonalOne = this->board[0][0];
            int savePlayerInDiagonalTwo = this->board[this->sizeOfField - 1][0];
            for(int i = 1; i < this->sizeOfField; i++){
                if(savePlayerInDiagonalOne != 0 && savePlayerInDiagonalOne != this->board[i][i]){
                    savePlayerInDiagonalOne = 0;
                }
                if(savePlayerInDiagonalTwo != 0 && savePlayerInDiagonalTwo != this->board[this->sizeOfField - 1 - i][i]){
                    savePlayerInDiagonalTwo = 0;
                }
            }
            if(savePlayerInDiagonalOne != 0)
                gamestate = savePlayerInDiagonalOne;
            else
                gamestate = savePlayerInDiagonalTwo;
        }
    }

    //Check if it is a tie
    if(gamestate == 0) {
        bool emptyField = false;
        for(int i = 0; i < this->sizeOfField; i++){
            for(int j = 0; j < this->sizeOfField; j++){
                if(this->board[i][j] == 0)
                    emptyField = true;
            }
        }
        if(!emptyField)
            gamestate = -1;
    }

    return gamestate;
}

//A function getting a move from the player.
//The move could either be surrendering or a valid move within the bound of the field.
bool gameboard::askUserForTurn(int playerOnDuty){
    TicTacToe::move m = this->players[playerOnDuty].makeAMove();
    if(this->players[playerOnDuty].getSurrendered()){
        std::cout << "Player " << (playerOnDuty + 1) << " surrendered." << std::endl;
        return true;
    }
    else{
        if(m.getX() >= 0 && m.getX() < this->sizeOfField && m.getY() >= 0 && m.getY() < this->sizeOfField && this->board[m.getX()][m.getY()] == 0){
            this->board[m.getX()][m.getY()] = players[playerOnDuty].getNumber();
            return true;
        }
        else{
            std::cout << "The field is already filled up or doesn't exist!" << std::endl; 
        }   
    }
    return false;
}