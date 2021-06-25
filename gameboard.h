#pragma once

#include "./player.h"
#include "./move.h"

namespace TicTacToe{
    class gameboard {
        private:
            TicTacToe::player* players;
            int amountOfPlayers;
            int** board;
            int sizeOfField;
            bool gameOver;
        public:
            gameboard(int sizeOfField, int amountOfPlayers);
            ~gameboard();
            void play();
            int checkStateOfGame();
            bool askUserForTurn(int playerOnDuty);
            void drawGameboard();
            void checkWinCondition();
    };
}