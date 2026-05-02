#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "player.h"
using namespace std;
class Board{
    char board [3][3];
    public:
        Board();
        Board(int, int);
        Board(const Board&);


        void updateBoard();
        bool boardFull();
        int won();
        void gameOver();
};
#endif