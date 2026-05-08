#ifndef HELPERS_H
#define HELPERS_H
#include <iostream>
#include <string>
#include "board.h"
#include "user.h"
#include "player.h"
#include "computer.h"
#include "validInput.h"
using namespace std;

Player createPlayer(int,char);
Computer createComputer(char);
void lookinFile(ifstream& inFile, Player* players);
void storeinFile(ifstream& inFile, Player* players);


int programMenu();
void startGame(User* usersArr[], Board&);
void viewScoreBoard();
void gameOver();
bool spotOpen(int,int, Board&);
#endif