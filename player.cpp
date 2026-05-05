#include "player.h"
Player::Player(){

}
Player::Player(string,string,int, int, bool){

}
Player::Player(const Player&){
        
 }
int Player::makeMove(){
    int maxRow=board.getMaxRow();
    int maxColumn=board.getMaxColumn();
    int choice1,choice2;

    cout<<"Enter Row: "<<endl;
    cin>>choice1;           
    do{
        cin>>choice;
        validInput(choice,maxRow);
    }while(!validInput<int>(choice,maxRow));

    cout<<"Enter Column: "<<endl;
    do{
        cin>>choice;
        validInput(choice,maxColumn);
    }while(!validInput<int>(choice,maxColumn));
}