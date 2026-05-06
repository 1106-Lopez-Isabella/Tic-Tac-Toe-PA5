#include "board.h"
Board::Board(){
    maxRow=3;
    maxColumn=3;
    for(int r=0; r<maxRow; r++){
        for(int c=0; c<maxColumn; c++){
            board[r][c] = "-";
        }
    }
}

Board::Board(int r, int c, string s){
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

void Board::setMaxRow(int r){
    maxRow = r;
}
void Board::setMaxColumn(int c){
    maxColumn = c;
}
void displayBoard(int r, int c){
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
           cout<<"|  "<<board[r][c]<<"  |";
        }
        cout<<endl<<"-------------------"<<endl;
    }
}
void updateBoardInfo(int r,int c, string t){
    board[r][c]=t;
}

bool boardFull(){
    int total=0;
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
            if(board[r][c]=="X"||board[r][c]=="O"){
                total++;
            }
        }
    }
    if(total==9){
        return true;
    }
    return false;
}
bool won(){
    for(int row=0;row<3;row++){
        if(board[row][0]=="X"&&board[row][1]=="X"&&board[row][2]=="X"){
            return true;
        }
        else if(board[row][0]=="O"&&board[row][1]=="O"&&board[row][2]=="O"){
            return true;
        }
    }
    for(int column=0;column<3;column++){
        if(board[0][column]=="X"&&board[1][column]=="X"&&board[2][column]=="X"){
            return true;
        }
        else if(board[0][column]=="O"&&board[1][column]=="O"&&board[2][column]=="O"){
            return true;
        }
    }
    if(board[0][0]=="X"board[1][1]=="X"board[2][2]=="X"){
        return true;
    }
    else if(board[0][0]=="O"board[1][1]=="O"board[2][2]=="O"){
        return true;
    }
    if(board[0][2]=="X"board[1][1]=="X"board[2][0]=="X"){
        return true;
    }
    else if(board[0][2]=="O"board[1][1]=="O"board[2][0]=="O"){
        return true;
    }
    return false;
}