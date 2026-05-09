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
    int choice=validInput<int>("Start New Game (1)    View Current Player Information (2)   Exit Game (0)",2,0);
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
    if(amount==1){
	    symbol=validInput<char>("Please choose either the X or O: ",'X','O');
    }
    else if(amount==2){
        if(s=='X'){
            cout<<"Your symbol will be O"<<endl<<endl;
            symbol='O';
        }
        else{
            cout<<"Your symbol will be X"<<endl<<endl;
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
int viewPlayerInformation(Player playerOne, Player playerTwo){
    cout<<playerOne<<endl;
    if(playerTwo.getName()!="empty"){
        cout<<playerTwo<<endl;
    }
    int choice=validInput<int>("Enter 0 to go back to the main menu",0,0);
    return choice;
}
bool spotOpen(int r ,int c, int playerAmount, Board& board){
    if(board.getSpot(r,c)!='-'){
        if(playerAmount==2){
            cout<<"That spot has already been taken. Try again"<<endl;
        }
        return false;
    }
    return true;
}
void startGame(User* usersArr[], Board& board, int playerAmount, int maxSize) {
    bool gameOver = false;
    int i=0;
    int row,column;

    board.clearBoard();
    cout<<"If you want to return to the main menu at any point, please enter 0 for both row and column"<<endl;

    while (!gameOver) {
        //dont get rid of this or it will crash
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
            if(usersArr[i]->getName()!="Computer"){
                row=usersArr[i]->makeMove(1,maxSize);
                column=usersArr[i]->makeMove(2,maxSize);
            }
            else if(usersArr[i]->getName()=="Computer"){
                row=usersArr[i]->makeMove(1,maxSize);
                column=usersArr[i]->makeMove(2,maxSize);
            }
                isValid=spotOpen(row-1,column-1, playerAmount, board);
        }
        if (row== 0||column==0) { 
            return;
        }

        //updates the board with the user's choice
        board.updateBoardInfo(row-1,column-1,usersArr[i]->getSymbol());
        //checks if the user won or if the board is full, if either of those are true, it will end the game and update the score board
        if(board.won()){
            board.won();
            board.displayBoard();
            if(i==0){
                usersArr[0]->setWin(usersArr[0]->getWin()+1);
                usersArr[1]->setLose(usersArr[1]->getLose()+1);
                cout<<endl;
                cout<<usersArr[0]->getName()<<" won!"<<endl;
                cout<<usersArr[1]->getName()<<" lost..."<<endl;
            }
            else{
                usersArr[1]->setWin(usersArr[1]->getWin()+1);
                usersArr[0]->setLose(usersArr[0]->getLose()+1);
                cout<<endl;
                cout<<usersArr[1]->getName()<<" won!"<<endl;
                cout<<usersArr[0]->getName()<<" lost..."<<endl;
            }
            gameOver=board.won();
            break;
        }
        if(board.boardFull()){
            board.boardFull();
            cout<<"No one won..."<<endl;
            break;
        }

        if(i==1){
            i=0;
        }
        else{
            i++;
        }
    }
}
void savePlayerData(User* usersArr[],int amount){
    ofstream outFile("playerData.txt");

    if(outFile.is_open()){
        if(usersArr[0]->getName()!="Computer"){
            outFile<<"PlAYER DATA"<<endl;
            outFile<<"NAME: "<<usersArr[0]->getName()<<endl<<"WINS: "<<usersArr[0]->getWin()<<endl<<"LOSSES: "<<usersArr[0]->getLose()<<endl;
        }
    }
} 
void readPlayerData (ifstream& inFile, Player pastUsers[]){
    Player temp;
	string name,sWin,sLose,junk;
    int win,lose;
	int i=0;
	getline(inFile,junk);

	while (!inFile.eof()){
		getline(inFile,junk,':');
		getline(inFile,name);
        temp.setName(name);
		getline(inFile,junk,':');
		getline(inFile,sWin);
        win=stoi(sWin);
        temp.setWin(win);
		getline(inFile,junk,':');
        getline(inFile,sLose);
        lose=stoi(sLose);
        temp.setLose(lose);
        pastUsers[i]=temp;
		i++;
	}
}
