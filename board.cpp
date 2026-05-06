#include "board.h"

Board::Board(){
    maxRow=3;
    maxColumn=3;
    for(int r=0; r<maxRow; r++){
        for(int c=0; c<maxColumn; c++){
            board[r][c] = " ";
        }
    }
}

Board::Board(int r, int c){
    maxRow = r;
    maxColumn =c;
    for(int r=0; r<maxRow; r++){
        for(int c=0; c<maxColumn; c++){
            board[r][c]= " ";
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
void Board::updateBoardInfo(int r,int c, string t){
    board[r][c]=t;
    
}
bool Board::boardFull(){
    int total=0;
    for(int r=0;r<maxRow;r++){
        for(int c=0;c<maxColumn;c++){
            if(board[r][c]=="X"||board[r][c]=="O"){
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
    // Check rows
    for(int row=0; row<maxRow; row++){
        string first = board[row][0];
        if(first == " ") continue;
        bool win = true;
        for(int c=1; c<maxColumn; c++){
            if(board[row][c] != first){
                win = false;
                break;
            }
        }
        if(win) return true;
    }
    // Check columns
    for(int col=0; col<maxColumn; col++){
        string first = board[0][col];
        if(first == " ") continue;
        bool win = true;
        for(int r=1; r<maxRow; r++){
            if(board[r][col] != first){
                win = false;
                break;
            }
        }
        if(win) return true;
    }
    // Check diagonals if square
    if(maxRow == maxColumn){
        // Main diagonal
        string first = board[0][0];
        if(first != " "){
            bool win = true;
            for(int i=1; i<maxRow; i++){
                if(board[i][i] != first){
                    win = false;
                    break;
                }
            }
            if(win) return true;
        }
        // Anti-diagonal
        first = board[0][maxColumn-1];
        if(first != " "){
            bool win = true;
            for(int i=1; i<maxRow; i++){
                if(board[i][maxColumn-1-i] != first){
                    win = false;
                    break;
                }
            }
            if(win) return true;
        }
    }
    return false;
}