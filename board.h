#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "player.h"
using namespace std;
class Board{
    string board [3][3];
    int maxRow,maxColumn;
    public:
        Board();
        Board(int, int);
        Board(const Board&);

        int getMaxRow();
        int getMaxColumn();

        void setMaxRow(int);
        void setMaxColumn(int);


        void updateBoardInfo();
        void displayBoard();
        bool boardFull();
        int won();
        void gameOver();
};
#endif