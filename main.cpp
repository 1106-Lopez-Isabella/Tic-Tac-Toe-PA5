#include "board.h"
#include "player.h"
#include "computer.h"
#include "helpers.h"

int main(int argc, char** argv){
    Player playerOne, playerTwo;
    Computer computer;
    User* usersArr[2];
    Board board;
    int choice;
    char choice2='Y';
    int round=1;
    int playerAmount=1;

    //something to do with the top5Player file 
	/*if(argc != 2)
	{
        cout << "Incorrect format! Please use:  ./game top5Players.txt" << endl;
        return 1;
    }

	ifstream playerData(argv[1]);
    if(!top5Players.is_open())
	{
        cout << "Top 5 Player File not found..." << endl;
        return 1;
    }*/

    //program menu
    do{
        choice=programMenu();
        switch (choice){
            case 1:
                //make player one object
                playerOne=createPlayer(playerAmount,'-');
                choice=validInput<int>("Do you want to play with (1) another Person or (2) a Computer",2,1);
                switch (choice){
                    case 1:
                        //make player two object
                        playerAmount++;
                        cout<<endl<<"Player two, enter your information..."<<endl;
                        playerTwo=createPlayer(playerAmount,playerOne.getSymbol());
                    case 2:
                        //make computer object
                        computer=createComputer(playerOne.getSymbol());
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
                //actual start of the game
                startGame(usersArr,board);
                while(choice!='N'){
                    choice2=validInput<char>("Continue?(Y/N)",'Y','N');
                    round++;
                    cout<<"Round "<<round<<"..."<<endl;
                    startGame(usersArr,board);
                }
                //wrtieToFile(usersArr,playerAmount);
                choice=0;
            case 2:
                //should display the information from top5Players
                //will probably take this out since you dont need to display it 
                //viewScoreBoard();
            default:
                return 0;
        }
    }while (choice != 0);
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



