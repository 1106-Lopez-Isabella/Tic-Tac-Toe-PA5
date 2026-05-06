#ifndef PLAYER_H
#define PLAYER_H
#include "user.h"
using namespace std;

class Player:public User{

    public:
        Player();
        Player(string,string,int, int, bool);
        Player(const Player&);

        void makeMove();
        friend ostream& operator <<(ostream& out, const Player& Player);
};
#endif