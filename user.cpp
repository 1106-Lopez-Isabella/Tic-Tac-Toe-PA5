#include "user.h"

User::User(){
    string name = "";
    string symbol = "";
    int row = 0;
    int column = 0;
    int win = 0;
    int lose = 0;
}
User::User(string n, string s, int r, int c, bool w){ //do we need to add bool l for lose to this?
    name = n;
    symbol = s;
    row = r;
    column = c;
    win = w;
}
User::User(const User& rhs){
    name = rhs.name;
    symbol = rhs.symbol;
    row = rhs.row;
    column = rhs.column;
    win = rhs.win;
    lose = rhs.lose;

}
string User::getName(){
    return name;
}
string User::getSymbol(){
    return symbol;
}
int User::getRow(){
    return row;
}
int User::getColumn(){
    return column;
}
void User::setName(string n){
    name = n;
}
void User::setId(string s){
    symbol = s;
}
void User::setRow(int r){
    row = r;
}
void User::setColumn(int c){
     column = c;
}
void User::setWin(int w){
    win = w;
}
//does lose need a getter & setter lmk and I'll added it just incase
void User::displayPlayerData(){

}
