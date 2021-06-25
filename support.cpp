#include "support.h"

using namespace TicTacToe;
using namespace std;

//A function checking if the inputstring is numeric
bool TicTacToe::isNumber(const std::string& str){
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}