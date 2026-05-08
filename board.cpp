#include "board.h"

Board::Board(){
    maxRow=3;
    maxColumn=3;
    for(int r=0; r<maxRow; r++){
        for(int c=0; c<maxColumn; c++){
            board[r][c] = '-';
        }
    }
}

Board::Board(int r, int c, char s){
    maxRow = r;
    maxColumn =c;
    for(int r=0; r<maxRow; r++){
        for(int c=0; c<maxColumn; c++){
            board[r][c]= s;
        }
    }

}
Board::Board(const Board& rhs){
    maxRow=rhs.maxRow;
    maxColumn=rhs.maxColumn;
    for(int r = 0; r<maxRow; r++){
        for(int c = 0; c<maxColumn; c++){
            board [r][c] = rhs.board[r][c];
        }
    }
}

int Board::getMaxRow(){
    return maxRow;
}
int Board::getMaxColumn(){
    return maxColumn;

}
char Board::getSpot(int r, int c){
    return board[r][c];
}

void Board::setMaxRow(int r){
    maxRow = r;
}
void Board::setMaxColumn(int c){
    maxColumn = c;
}
void Board::displayBoard(){
    for(int r=0;r<maxRow;r++){
        for(int c=0;c<maxColumn;c++){
           cout<<"|  "<<board[r][c]<<"  |";
        }
        cout<<endl<<"-------------------"<<endl;
    }
}
void Board::updateBoardInfo(int r,int c, char t){
    board[r][c]=t;
}
bool Board::boardFull(){
    int total;
    for(int r=0;r<maxRow;r++){
        for(int c=0;c<maxColumn;c++){
            if(board[r][c]=='X'||board[r][c]=='O'){
                total++;
            }
        }
    }
    if(total==maxRow*maxColumn){
        return true;
    }
    return false;
}
bool Board::won(){
    for (int i = 0; i < 3; i++) {
        // Check Rows
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        
        // Check Columns
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    // Check Diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false; // No winner yet
}