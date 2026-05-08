#ifndef COMPUTER_H
#define COMPUTER_H
#include "user.h"
using namespace std;


class Computer:public User{

    public:
        Computer();
        Computer(string,char,int, int, int,int);
        Computer(const Computer&);

        int makeMove(int); //will use the cstdlib library to choose random number for row and column
        ~Computer();
};
#endif