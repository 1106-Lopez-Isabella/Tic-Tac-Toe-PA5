#include "player.h"

Player::Player():User(){

}
Player::Player(string n,string s,int r, int c, int w, int l):User(n, s, r, c, w, l){

}
Player::Player(const Player& rhs):User(rhs){
        
 }
int Player::makeMove(int type){
    int entry;
    //prompts user for row or column
    if(type==1){
        entry=validInput<int>("Enter Row: ",1,3);          
    }
    else{
        entry=validInput<int>("Enter Column: ",1,3);
    }

    return entry-1;
}
ostream& operator <<(ostream& out, const Player& p){
    out<<"NAME: "<<p.getName()<<endl;
    out<<"WINS: "<<p.getWin()<<endl;
    out<<"LOSSES: "<<p.getLose()<<endl;
    return out;
}