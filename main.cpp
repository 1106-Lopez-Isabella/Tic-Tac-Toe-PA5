#include "board.h"
#include "player.h"
#include "computer.h"
#include "helpers.h"

int main(int argc, char** argv){
    Player playerOne, playerTwo;
    Computer computer;
    User* usersArr[2]={&playerOne,&playerTwo};
    Player pastUsers[2];
    Board* board=nullptr;
    int choice;
    char choice2='Y';
    int round=1;
    int playerAmount=1;

    if(argc != 2)
	{
        cout << "Incorrect format! Please use:  ./game playerData.txt" << endl;
        return 1;
    }

	ifstream playerData(argv[1]);
    if(!playerData.is_open())
	{
        cout << "Player Data File not found..." << endl;
        return 1;
    }
    readPlayerData(playerData,pastUsers);
    //program menu
    do{
        choice=programMenu();
        switch (choice){
            case 1:{
                //make player one object
                playerOne=createPlayer(playerAmount,'-');
                choice=validInput<int>("Do you want to play with (1) another Person or (2) a Computer",2,1);
                switch (choice){
                    case 1:
                        //make player two object
                        playerAmount++;
                        cout<<endl<<"Player two, enter your information..."<<endl;
                        playerTwo=createPlayer(playerAmount,playerOne.getSymbol());
                        break;
                    case 2:
                        //make computer object
                        computer=createComputer(playerOne.getSymbol());
                        break;
                }
                //assigning who plays first 
                if(playerAmount==1){
                   if(playerOne.getSymbol()=='X'){
                        usersArr[0]=&playerOne;
                        usersArr[1]=&computer;
                    }
                    else if(playerOne.getSymbol()=='O'){
                        usersArr[0]=&computer;
                        usersArr[1]=&playerOne;
                    } 
                }
                else if(playerAmount==2){
                    if(playerOne.getSymbol()=='X'){
                        usersArr[0]=&playerOne;
                        usersArr[1]=&playerTwo ; 
                    }
                    else if(playerOne.getSymbol()=='O'){
                    usersArr[0]=&playerTwo;
                    usersArr[1]=&playerOne;
                    }
                }
                int size=validInput<int>("Enter board size (from 3 to 5):",5,3);
                board=new Board(size);
                //actual start of the game, also checks if the user wants to contiue the same game
                choice2='Y';
                while(choice2!='N'){
                    startGame(usersArr,*board, playerAmount,size);
                    round++;
                    choice2=validInput<char>("Continue?(Y/N)",'Y','N');
                    if(choice2=='Y'){
                        cout<<"Round "<<round<<"..."<<endl;
                    }
                }
                delete board;
                board=nullptr;
                playerAmount=1;
                break;
            }
            case 2:
                choice=viewPlayerInformation(playerOne,playerTwo)+1;
                break;
        }
    }while (choice != 0);
    savePlayerData(usersArr,playerAmount);
}

/*after these questions, make both users, game will start 
whoever chose X will go first
do this until board is full  
do that 3 times
after 3 games, game will be over 
give them the option to start a new game, quit, or go to main menu 
if newgame, start the process over
if quit, quit 
if main menu, send to mainmenu

important, whenever someone quits the game, make a file containing the User info*/



