#include "player.h"
Player::Player():User(){

}
Player::Player(string n,string s,int r, int c, int w, int l):User(n, s, r, c, w, l){

}
Player::Player(const Player&):User(rhs){
        
 }
int Player::makeMove(int type,const Board& board){
    int maxRow=board.getMaxRow();
    int maxColumn=board.getMaxColumn();
    int entry;
    if(choice==1){
        cout<<"Enter Row: "<<endl;          
        do{
            cin>>entry; 
            spotOpen()
        }while(!validInput<int>(entry,maxRow));
        return entry;
    }
    else{
        cout<<"Enter Column: "<<endl;
        do{
            cin>>entry; 
            validInput<int>(entry,maxColumn);
        }while(!validInput<int>(entry,maxColumn));
        return entry;
    }
}
friend ostream& operator <<(ostream& out, const Player& Player){
    out<<"NAME: "<<Player.getName()<<endl;
    out<<"WINS: "<<Player.getWin()<<endl;
    out<<"LOSSES: "<<Player.getLose()<<endl;
}