#ifndef USER_H
#define USER_H
#include <iostream>
#include <cstdlib>
#include "board.h"
using namespace std;

class User{
    protected:
        string name, symbol;
        int row,column;
        int win,lose; 
    public:
        User();
        User(string,string,int, int, int, int);
        User(const User&);
        
        string getName();
        string getSymbol();
        int getRow();
        int getColumn();
        int getWin();
        int getLose();
        

        void setName(string);
        void setId(string);
        void setRow(int);
        void setColumn(int);
        void setWin(int);
        void setLose(int);

        virtual int makeMove(int, const Board& board)=0;
};
#endif