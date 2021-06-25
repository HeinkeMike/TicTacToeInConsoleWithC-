#include "./gameboard.h"
#include "./support.h"
#include <new>
#include <string>

using namespace TicTacToe;

int main () {
    bool wantToPlay = true;
    while(wantToPlay){
        std::cout << "Please enter the amount of rows and columns:" << std::endl;
        std::string userResponseSize;
        std::cin >> userResponseSize;
        if(isNumber(userResponseSize)){
            std::cout << "Please enter the amount of players:" << std::endl;
            std::string userResponsePlayers;
            std::cin >> userResponsePlayers;
            if(isNumber(userResponsePlayers)){
                TicTacToe::gameboard *gb = new TicTacToe::gameboard(std::stoi(userResponseSize), stoi(userResponsePlayers));
                gb->play();
                delete gb;
            }
        }
        
        bool noCorrectChoice = true;
        while(noCorrectChoice){
            std::cout << "Do you want to keep playing? :" << std::endl;
            std::cout << "1. Yes" << std::endl;
            std::cout << "2. No" << std::endl;

            std::string userResponseString;
            cin >> userResponseString;
            int userResponse;
            userResponse = -1;
            if(isNumber(userResponseString))
                userResponse = std::stoi(userResponseString);
            switch (userResponse)
            {
            case 1:
                noCorrectChoice = false;
                break;
            case 2:
                noCorrectChoice = false;
                wantToPlay = false;
                break;
            default:
                std::cout << "Error, unknown command." << std::endl;
                break;
            }
        }
    }
    
}