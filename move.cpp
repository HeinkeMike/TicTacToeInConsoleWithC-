#include "move.h"

using namespace TicTacToe;

move::move(int x, int y) {
    this->x = x;
    this->y = y;
}

int move::getX(){
    return this->x;
}

int move::getY(){
    return this->y;
}