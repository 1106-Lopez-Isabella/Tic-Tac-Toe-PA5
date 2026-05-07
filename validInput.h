#ifndef VALID_H
#define VALID_H
#include <iostream>
#include <string>
#include <limits>
using namespace std;

template <typename T>
T validInput(string prompt,T min, T max){
    T input;
    bool isValid = false;
    
    while(!isValid){
        cout<<prompt<<endl;
        cin>>input;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid type. Please try again."<<endl;
            continue;
        }

        if(input >=min && input <=max){
            isValid=true;
        }
        else{
            cout<<"Not within range, choose again"<<endl;
        }
    }
    return input;
    
    /*if(a==0){
        return true;
    }
    else if(a!=0){
        if(c>0&&c<a+1){
            return true;
        }
        else{
            cout<<"ERROR: enter valid input"<<endl;
            return false;
        }
    }
    else {
        if(c!='X'||c!='x'||c!='O'||c!='o'){
           cout<<"ERROR: enter valid input"<<endl;
            return false; 
        }
        else{
            return true;
        }
    }*/
}

#endif