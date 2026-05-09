#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include "validInput.h"
using namespace std;

class Board{
    //char board [3][3];
    char** board;
    int row;
    //int maxRow,maxColumn;
    public:
        Board();
        //Board(int, int, char);
        Board(int);
        Board(const Board&);
        
        int getRow();
        /*int getMaxRow();
        int getMaxColumn();*/
        char getSpot(int,int);

        /*void setMaxRow(int);
        void setMaxColumn(int);*/
        void setRow(int);


        void updateBoardInfo(int,int,char);
        void clearBoard();
        void displayBoard();
        bool boardFull();
        bool won();

        Board& operator=(const Board&);
        ~Board();
};
#endif