#include "player.h"
Player::Player(){

}
Player::Player(string,string,int, int, bool){

}
Player::Player(const Player&){
        
 }
int Player::makeMove(int choice){
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