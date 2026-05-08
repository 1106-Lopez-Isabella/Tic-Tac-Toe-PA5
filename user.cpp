#include "user.h"

User::User(){
    name = "empty";
    symbol = '-';
    row = 0;
    column = 0;
    win = 0;
    lose = 0;
}
User::User(string n, char s, int r, int c, int w, int l){
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
char User::getSymbol(){
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
void User::setSymbol(char s){
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

