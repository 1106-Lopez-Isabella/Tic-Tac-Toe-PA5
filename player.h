#ifndef PLAYER_H
#define PLAYER_H
#include "user.h"
#include <iostream>
#include <string>
using namespace std;

class Board;

class Player: public User{

    public:
        Player();
        Player(string,string,int, int, bool);
        Player(const Player&);

        int makeMove(int);
        friend ostream& operator <<(ostream& out, const Player& Player);
};
#endif