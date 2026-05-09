#include "computer.h"
Computer::Computer():User(){
    

}
Computer::Computer(string n, char s, int r, int c, int w, int l):User(n, s, r, c, w, l){

}
Computer::Computer(const Computer& rhs):User(rhs){

}
int Computer::makeMove(int type,int limit){
    return (rand() % limit) + 1;
}