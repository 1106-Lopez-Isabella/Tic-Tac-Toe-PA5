#include "player.h"

Player::Player():User(){

}
Player::Player(string n,char s,int r, int c, int w, int l):User(n, s, r, c, w, l){

}
Player::Player(const Player& rhs):User(rhs){
        
 }
int Player::makeMove(int type){
    int entry;
    //prompts user for row or column
    if(type==1){
        entry=validInput<int>("Enter Row: ",3,0);          
    }
    else{
        entry=validInput<int>("Enter Column: ",3,0);
    }
    return entry;
}
ostream& operator <<(ostream& out, const Player& p){
    out<<"NAME: "<<p.getName()<<endl;
    out<<"WINS: "<<p.getWin()<<endl;
    out<<"LOSSES: "<<p.getLose()<<endl;
    return out;
}