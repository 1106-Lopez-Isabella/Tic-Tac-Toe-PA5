#include "user.h"

User::User(){
    string name = "empty";
    string symbol = "-";
    int row = 0;
    int column = 0;
    int win = 0;
    int lose = 0;
}
User::User(string n, string s, int r, int c, int w, int l){
    name = n;
    symbol = s;
    row = r;
    column = c;
    win = w;
    lose = l;
}
User::User(const User& rhs){
    name = rhs.name;
    symbol = rhs.symbol;
    row = rhs.row;
    column = rhs.column;
    win = rhs.win;
    lose = rhs.lose;

}
string User::getName()const{
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
int User::getWin()const{
    return win;
}
int User::getLose()const{
    return lose;
}
void User::setName(string n){
    name = n;
}
void User::setSymbol(string s){
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
void User::setLose(int l){
    lose = l;
}

