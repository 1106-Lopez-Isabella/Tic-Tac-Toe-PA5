#include "computer.h"
Computer::Computer():User(){
    

}
Computer::Computer(string n, string s, int r, int c, bool w, bool l):User(n, s, r, c, w, l){

}
Computer::Computer(const Computer& rhs):User(rhs){

}
int Computer::makeMove(){
    int random;
    random = rand() % 2;
    return random;
}