#ifndef USER_H
#define USER_H
#include <iostream>
#include <cstdlib>
#include <string>
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
        
        string getName()const;
        string getSymbol();
        int getRow();
        int getColumn();
        int getWin()const;
        int getLose()const;
        

        void setName(string);
        void setSymbol(string);
        void setRow(int);
        void setColumn(int);
        void setWin(int);
        void setLose(int);

        virtual int makeMove(int)=0;
};
#endif