#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;
class User{
    protected:
        string name, symbol;
        int row,column;
        int win,lose; 
    public:
        User();
        User(string,string,int, int, bool);
        User(const User&);
        string getName();
        string getSymbol();
        int getRow();
        int getColumn();
        int getWin();
        

        void setName(string);
        void setId(string);
        void setRow();
        void setColumn();
        void setWin();

        virtual void makeMove()=0;
};
};
#endif