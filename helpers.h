
#ifndef HELPERS_H
#define HELPERS_H
#include <iostream>
#include <string>

Player createPlayer();
void lookinFile(ifstream& inFile, Player* players);
void storeinFile(ifstream& inFile, Player* players);


void programMenu();
void displayScoreBoard();
void gameOver();
bool spotOpen();
template <typename T>
bool validInput(T c, int a){
    if(a==0){
        return true;
    }
    else if(a!=0){
        if(c>0&&c<a+1){
            return true;
        }
        else{
            cout<<"ERROR: enter valid input"<<endl;
            return false;
        }
    }
    else {
        if(c!="X"||c!="x"||c!="O"||c!="o"){
           cout<<"ERROR: enter valid input"<<endl;
            return false; 
        }
        else{
            return true;
        }
    }
}

#endif