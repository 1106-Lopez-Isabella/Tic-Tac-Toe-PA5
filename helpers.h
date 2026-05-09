#ifndef HELPERS_H
#define HELPERS_H
#include <iostream>
#include <string>
#include <fstream>
#include "board.h"
#include "user.h"
#include "player.h"
#include "computer.h"
#include "validInput.h"
using namespace std;

Player createPlayer(int,char);
Computer createComputer(char);


int programMenu();
void startGame(User* usersArr[], Board&, int,int);
void gameOver();
bool spotOpen(int,int,int, User*,Board&);
int viewPlayerInformation(Player,Player);
void savePlayerData(User* usersArr[],int amount);
#endif