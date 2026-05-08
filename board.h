#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include "validInput.h"
using namespace std;

class Board{
    char board [3][3];
    int maxRow,maxColumn;
    public:
        Board();
        Board(int, int, char);
        Board(const Board&);

        int getMaxRow();
        int getMaxColumn();
        char getSpot(int,int);

        void setMaxRow(int);
        void setMaxColumn(int);


        void updateBoardInfo(int,int,char);
        void displayBoard();
        bool boardFull();
        bool won();
};
#endif