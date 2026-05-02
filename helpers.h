#include "Player.h"

#ifndef HELPERS_H
#define HELPERS_H

Player createPlayer();
void lookinFile(ifstream& inFile, Player* players);
void storeinFile(ifstream& inFile, Player* players);


void programMenu();
void displayScoreBoard();
void gameOver();
template <typename T>
T validInput(T){

}

#endif