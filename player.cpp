#include "player.h"

Player::Player():User(){

}
Player::Player(string n,char s,int r, int c, int w, int l):User(n, s, r, c, w, l){

}
Player::Player(const Player& rhs):User(rhs){
        
 }
int Player::makeMove(int type,int maxSize){
    int entry;
    //prompts user for row or column
    if(type==1){
        //checks if it is valid
        entry=validInput<int>("Enter Row: ",maxSize,0);          
    }
    else{
        //checks if it is valid
        entry=validInput<int>("Enter Column: ",maxSize,0);
    }
    return entry;
}
ostream& operator <<(ostream& out, const Player& p){
    //prints out player information
    out<<"NAME:"<<p.getName()<<endl;
    out<<"WINS:"<<p.getWin()<<endl;
    out<<"LOSSES:"<<p.getLose()<<endl;
    return out;
}