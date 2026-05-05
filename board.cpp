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
void displayBoard(){
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
           cout<<"|  "<<board[r][c]<<"  |";
        }
        cout<<endl<<"-------------------"<<endl;
    }
}