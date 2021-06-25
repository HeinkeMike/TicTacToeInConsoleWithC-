#pragma once

#include "./move.h"
#include "./support.h"
#include <iostream>

using namespace std;

namespace TicTacToe {
    class player {
        private:
            bool surrendered;
            int number;
            void surrender();
        public:
            player();
            ~player();
            TicTacToe::move makeAMove();
            TicTacToe::move placeAStone();
            void setNumber(int number);
            int getNumber();
            bool getSurrendered();
    };
}