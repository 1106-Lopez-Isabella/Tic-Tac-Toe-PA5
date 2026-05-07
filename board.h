#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include "validInput.h"
using namespace std;

class Board{
    string board [3][3];
    int maxRow,maxColumn;
    public:
        Board();
        Board(int, int, string);
        Board(const Board&);

        int getMaxRow();
        int getMaxColumn();

        void setMaxRow(int);
        void setMaxColumn(int);


        void updateBoardInfo(int,int,string);
        void displayBoard();
        bool boardFull();
        bool won();
};
#endif