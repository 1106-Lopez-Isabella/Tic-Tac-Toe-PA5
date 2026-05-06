#include "player.h"

Player::Player():User(){

}
Player::Player(string n,string s,int r, int c, int w, int l):User(n, s, r, c, w, l){

}
Player::Player(const Player&):User(rhs){
        
 }
int Player::makeMove(int type){
    int entry;
    if(choice==1){
        cout<<"Enter Row: "<<endl;          
    }
    else{
        cout<<"Enter Column: "<<endl;
    }
    do{
        cin>>entry; 
        validInput<int>(entry-1,3);
    }while(!validInput<int>(entry-1,3));

    return entry-1;
}
ostream& Player::operator <<(ostream& out, const Player& Player){
    out<<"NAME: "<<Player.getName()<<endl;
    out<<"WINS: "<<Player.getWin()<<endl;
    out<<"LOSSES: "<<Player.getLose()<<endl;
}