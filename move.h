#pragma once

namespace TicTacToe{
    class move{
        private:
            int x;
            int y;

        public:
            move(int x, int y);
            int getX();
            int getY();
        
    };
}