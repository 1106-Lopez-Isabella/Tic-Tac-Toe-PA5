#ifndef PLAYER_H
#define PLAYER_H
#include "user.h"
#include "validInput.h"
using namespace std;

class Board;

class Player: public User{

    public:
        Player();
        Player(string,char,int, int, int,int);
        Player(const Player&);

        int makeMove(int);
        friend ostream& operator <<(ostream& out, const Player& Player);
};
#endif