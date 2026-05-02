
void displayBoard(){
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
           cout<<"|  "<<board[r][c]<<"  |";
        }
        cout<<endl<<"-------------------"<<endl;
    }
}