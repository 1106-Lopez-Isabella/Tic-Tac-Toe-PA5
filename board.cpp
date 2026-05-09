#include "board.h"

Board::Board(){
    row=3;
    board=new char*[row];
    for(int i=0;i<row;i++){
        board[i]=new char[row];
    }
}

Board::Board(int s){
    row=s;
    board=new char*[row];
    for(int i=0;i<row;i++){
        board[i]=new char[row];
    }

}
Board::Board(const Board& rhs){
    row=rhs.row;
    board=new char*[row];
    for(int i=0; i< row;i++){
        board[i]=new char[row];
        for(int j=0;j<row;j++){
            board[i][j]=rhs.board[i][j];
        }
    }
}

char Board::getSpot(int r, int c){
   if (r < 0 || r >= row || c < 0 || c >= row) return '-'; // Guard
    return board[r][c];
}
int Board::getRow(){
    return row;
}

void Board::setRow(int r){
    row=r;
}
void Board::displayBoard(){
    for(int r=0;r<row;r++){
        for(int c=0;c<row;c++){
           cout<<"|  "<<board[r][c]<<"  |";
        }
        cout<<endl;
    }
}
void Board::clearBoard(){
    for(int r=0;r<row;r++){
        for(int c=0;c<row;c++){
           board[r][c]='-';
        }
    }
}
void Board::updateBoardInfo(int r,int c, char t){
    if (r >= 0 && r < row && c >= 0 && c < row) {
        board[r][c] = t;
    }
}
bool Board::boardFull(){
    int total=0;
    for(int r=0;r<row;r++){
        for(int c=0;c<row;c++){
            if(board[r][c]=='X'||board[r][c]=='O'){
                total++;
            }
        }
    }
    if(total==row*row){
        return true;
    }
    return false;
}

bool Board::won() {
    //checks horizontals
    for (int i = 0; i < row; i++) {
        char first = board[i][0];
        if (first == '-') continue;
        bool allMatch = true;
        for (int j = 1; j < row; j++) {
            if (board[i][j] != first) {
                allMatch = false;
                break;
            }
        }
        if (allMatch) return true;
    }
    for (int j = 0; j < row; j++) {
        char first = board[0][j];
        if (first == '-') continue;
        bool allMatch = true;
        for (int i = 1; i < row; i++) {
            if (board[i][j] != first) {
                allMatch = false;
                break;
            }
        }
        if (allMatch) return true;
    }

    //checks diagnols 
    char diag1First = board[0][0];
    if (diag1First != '-') {
        bool diag1Match = true;
        for (int i = 1; i < row; i++) {
            if (board[i][i] != diag1First) {
                diag1Match = false;
                break;
            }
        }
        if (diag1Match) return true;
    }

    char diag2First = board[0][row - 1];
    if (diag2First != '-') {
        bool diag2Match = true;
        for (int i = 1; i < row; i++) {
            if (board[i][row - 1 - i] != diag2First) {
                diag2Match = false;
                break;
            }
        }
        if (diag2Match) return true;
    }

    return false;
}
Board& Board::operator=(const Board& rhs){
    delete []board;
    row=rhs.row;
    board=new char*[row];
    for(int i=0; i< row;i++){
        board[i]=new char[row];
        for(int j=0;j<row;j++){
            board[i][j]=rhs.board[i][j];
        }
    }
    return *this;
}
Board::~Board(){
        delete[] board;
}