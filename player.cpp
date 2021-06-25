#include "player.h"

using namespace TicTacToe;
using namespace std;

player::player() {
    this->surrendered = false;
}

player::~player() {}

void player::setNumber(int number) {
    this->number = number;
}

bool player::getSurrendered() {
    return this->surrendered;
}

int player::getNumber() {
    return this->number;
}

//A function which is getting the choice from the player and checking if the choice is numeric
TicTacToe::move player::makeAMove() {
    bool noCorrectChoice = true;
    while(noCorrectChoice){
        std::cout << "Choose one of the following :" << std::endl;
        std::cout << "1. Place" << std::endl;
        std::cout << "2. Surrender" << std::endl;

        std::string userResponseString;
        cin >> userResponseString;
        int userResponse;
        userResponse = -1;
        if(isNumber(userResponseString))
            userResponse = std::stoi(userResponseString);
        switch (userResponse)
        {
        case 1:
            return this->placeAStone();
        case 2:
            this->surrender();
            return move(-1, -1);
        default:
            std::cout << "Error, unknown command." << std::endl;
            break;
        }
    }
    return move(-1, -1);
}

//A function getting the actual move from the player consitant out of two numbers one for a row, the other one for a column
TicTacToe::move player::placeAStone() {
    while(true){
        std::cout << "Please enter a row:" << std::endl;
        std::string userResponseX;
        std::cin >> userResponseX;
        if(isNumber(userResponseX)){
                while(true){
                    std::cout << "Please enter a column:" << std::endl;
                    std::string userResponseY;
                    std::cin >> userResponseY;
                    if(isNumber(userResponseY)){
                        return TicTacToe::move(std::stoi(userResponseX) - 1, std::stoi(userResponseY) - 1);
                    }
                }
        }
    }
}

//A surrender function which is setting surrendered to true
void player::surrender() {
    this->surrendered = true;
}

