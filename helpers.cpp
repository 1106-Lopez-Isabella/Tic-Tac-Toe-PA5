#include "helpers.h"

void readCoursesFile(ifstream& inFile, Player arrPlayer)
{
	int count = 0; 
	int numC;
	string name;
    int wins, losts;
	getline(inFile, junk);
    for(int i=0;i<5;i++){
	    while(!inFile.eof())
	    {
            getline(inFile, junk);
            getline(inFile,junk,':');
            getline(inFile,name);
		    arrPlayer[i].setName(name);

		    getline(inFile, junk, ':');
		    getline(inFile,wins);
		    arrPlayer[i].setWin(wins);

		    getline(inFile, junk, ':');
		    getline(inFile,losts);
		    arrPlayer[i].setLose(losts);

	    }
    }
}
int programMenu(){
    cout<<"--------------------TIC-TAC-TOE-----------------------"<<endl<<cout<<"                      Welcome!                      "<<endl;
    cout<<"Start Game (1)    View Score Board (2)   Exit Menu (0)"<<endl;
    
    do{
        cin>>choice;
        validInput(choice,2);
    }while(!validInput<int>(choice,2));

    return choice;
}
Player createPlayer(int amount, string s){
	Player player;
	string name, symbol;

	cout << "Please enter your first name: " << endl;
    cin>>name;
    player.setName(name);
    if(playerAmount==1){
	    cout << "Please choose either the X or O: " << endl;
	    do{
            cin>>symbol;
            validInput(symbol,9);
        }while(!validInput<string>(symbol,9));
        
        if(symbol=="X"||symbol=="x"){
            symbol="X";
        }
        else{
            symbol="O";
        }
    }
    else{
        if(s=="X"){
            cout<<"Your symbol will be O"<<endl;
            symbol="O";
        }
        else{
            cout<<"Your symbol will be X"<<endl;
            symbol="X";
        }
    }
    player.setSymbol(symbol);
	return player;
}
Computer createComputer(string symbol)
{
	Computer computer;

    computer.setName("Computer");
    if(symbol=="X"){
        computer.setSymbol("O");
    }
    else{
        computer.setSymbol("X");
    }

	return player;
}
void startGame() {
    cout<<"If you want to return to the main menu at any point, please enter 0"<<endl;
    bool gameOver = false;
    int i=0;
    int row,column;
    string choices[2];

    while (!gameOver) {
        //tells user it's their turn
        cout<<usersArr[i]->getName()<<", your turn!"<<endl;

        //show board so user can see their options
        displayBoard();

        //allows user to make their choice or lets computer do random choice
        //also checks if that spot is open, if not it will ask the user to choose another spot until they choose an open spot
        do{
            choices[0]=usersArr[i]->makeMove(1);
            choices[1]=usersArr[i]->makeMove(2);
            spotOpen(choices[0],choices[1]);
            if(!spotOpen(choices[0],choices[1])&&usersArr[i]->getName()!="computer"){
                cout<<"That spot is already taken, please choose another spot."<<endl;
            }

        }while(!spotOpen(choices[0],choices[1]));
        
        //exits the game if you choose 0
        if (row== 0||column==0) { 
            return;
        }
        //updates the board with the user's choice
        updateBoardInfo(row,column,usersArr[i].getSymbol);
        
        //checks if the user won or if the board is full, if either of those are true, it will end the game and update the score board
        if(won()){
            if(i==0){
                usersArr[0].setWin(usersArr[0].getWin()+1);
                usersArr[1].setLose(usersArr[1].getLose+1);
                cout<<usersArr[0].getName()<<" won!"<<endl;
                cout<<usersArr[1].getName()<<" lost..."<<endl;
            }
            else{
                usersArr[1].setWin(usersArr[1].getWin()+1);
                usersArr[0].setLose(usersArr[0].getLose+1);
                cout<<usersArr[1].getName()<<" won!"<<endl;
                cout<<usersArr[0].getName()<<" lost..."<<endl;
            }
            gameOver=won();
        }
        if(boardFull()){
            cout<<"No one won..."<<endl;
            gameOver=boardFull();
        }

        if(i==1){
            i=0
        }
        else{
            i++;
        }
    }
}
