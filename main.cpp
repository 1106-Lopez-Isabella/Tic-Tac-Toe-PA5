#include "board.h"

int main(int argc, char** argv){
    Player playerOne;
    Player playerTwo;
    Computer computer;
    User* usersArr[2];
    Player topPlayers[5];
    Board board;
    int choice, choice2, playerAmount=1;

	if(argc != 2)
	{
        cout << "Incorrect format! Please use:  ./game top5Players.txt" << endl;
        return 1;
    }

	ifstream playerData(argv[1]);
    if(!top5Players.is_open())
	{
        cout << "Top 5 Player File not found..." << endl;
        return 1;
    }

    do{
        choice=programMenu();
        switch choice{
            case 1:
                playerOne=createPlayer(playerAmount,"-");
                playerAmount++;
                cout<<"Do you want to play with (1) another Person or (2) a Computer"<<endl;
                do{
                    cin>>choice2;
                    validInput(choice2,2);
                }while(!validInput<int>(choice2,2));

                switch choice{
                    case 1:
                        cout<<"Player two, enter your information..."<<endl;
                        playerTwo=createPlayer(playerAmount,playerOne.getSymbol);
                        playerAmount++;
                    case 2:
                        computer=createComputer(playerOne.getSymbol);
                    default:
                        cout<<"ERROR: check line 44 in main"<<endl;
                }
                if(playerAmount==2){
                    if(playerOne.getSymbol()=="X"){
                        usersArr[0]=&playerOne;
                        usersArr[1]=&playerTwo ; 
                    }
                else{
                    usersArr[0]=&playerTwo;
                    usersArr[1]=&playerOne;
                }
                }
                else{
                    if(playerOne.getSymbol()=="X"){
                        usersArr[0]=&playerOne;
                        usersArr[1]=&computer;
                    }
                    else{
                        usersArr[0]=&computer;
                        usersArr[1]=&playerOne;
                    }
                }
                startGame();
            case 2:
                viewScoreBoard();
            default:
                cout<<"ERROR: check line 70 in main";
                return 0;
        }
    } while (choice != 0);
}

after these questions, make both users, game will start 
whoever chose X will go first
do this until board is full  
do that 3 times
after 3 games, game will be over 
give them the option to start a new game, quit, or go to main menu 
if newgame, start the process over
if quit, quit 
if main menu, send to mainmenu

important, whenever someone quits the game, make a file containing the User info



