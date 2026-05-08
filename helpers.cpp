#include "helpers.h"

/*void readCoursesFile(ifstream& inFile, Player arrPlayer)
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
}*/
int programMenu(){
    cout<<"--------------------TIC-TAC-TOE-----------------------"<<endl<<"                      Welcome!                      "<<endl;
    int choice=validInput<int>("Start Game (1)    View Score Board (2)   Exit Menu (0)",2,0);
    return choice;
}
Player createPlayer(int amount, char s){
	Player player;
	string name;
    char symbol;

	cout <<endl<< "Please enter your first name: " << endl;
    cin>>name;
    player.setName(name);
    //assigning symbol and checking if its an X or O
    cout<<"This is the amount of players:"<<amount<<endl;
    if(amount==1){
	    symbol=validInput<char>("Please choose either the X or O: ",'X','O');
    }
    else if(amount==2){
        if(s=='X'){
            cout<<"Your symbol will be O"<<endl;
            symbol='O';
        }
        else{
            cout<<"Your symbol will be X"<<endl;
            symbol='X';
        }
    }
    player.setSymbol(symbol);
	return player;
}
Computer createComputer(char symbol)
{
	Computer computer;

    computer.setName("Computer");
    if(symbol=='X'){
        computer.setSymbol('O');
    }
    else{
        computer.setSymbol('X');
    }

	return computer;
}
void viewScoreBoard(){
    cout<<"nothing to see here..."<<endl;
    return;
}
bool spotOpen(int r ,int c, Board& board){
    if(board.getSpot(r,c)!='-'){
        cout<<"That spot has already been taken. Try again"<<endl;
        return false;
    }
    return true;
}
void startGame(User* usersArr[], Board& board) {
    cout<<"If you want to return to the main menu at any point, please enter 0 for both row and column"<<endl;
    bool gameOver = false;
    int i=0;
    int row,column;

    while (!gameOver) {
        gameOver=false;
        bool isValid = false; 

        //tells user it's their turn
        cout<<usersArr[i]->getName()<<", your turn!"<<endl;

        //show board so user can see their options
        board.displayBoard();

        //allows user to make their choice or lets computer do random choice
        //also checks if that spot is open, if not it will ask the user to choose another spot until they choose an open spot
        while(!isValid){
            isValid=false;
            row=usersArr[i]->makeMove(1);
            column=usersArr[i]->makeMove(2);
            isValid=spotOpen(row,column,board);
        }
        if (row== 0||column==0) { 
            return;
        }

        //updates the board with the user's choice
        board.updateBoardInfo(row,column,usersArr[i]->getSymbol());
        //checks if the user won or if the board is full, if either of those are true, it will end the game and update the score board
        if(board.won()){
            if(i==0){
                usersArr[0]->setWin(usersArr[0]->getWin()+1);
                usersArr[1]->setLose(usersArr[1]->getLose()+1);
                cout<<usersArr[0]->getName()<<" won!"<<endl;
                cout<<usersArr[1]->getName()<<" lost..."<<endl;
            }
            else{
                usersArr[1]->setWin(usersArr[1]->getWin()+1);
                usersArr[0]->setLose(usersArr[0]->getLose()+1);
                cout<<usersArr[1]->getName()<<" won!"<<endl;
                cout<<usersArr[0]->getName()<<" lost..."<<endl;
            }
            gameOver=board.won();
        }
        if(board.boardFull()){
            cout<<"No one won..."<<endl;
            gameOver=board.boardFull();
        }

        if(i==1){
            i=0;
        }
        else{
            i++;
        }
    }
}
