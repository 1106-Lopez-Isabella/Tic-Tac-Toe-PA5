#ifndef VALID_H
#define VALID_H
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T validInput(string prompt,T max, T min){
    T entry;
    bool isValid = false;

    //prompts user
    cout<<prompt<<endl;

    //loops until answer is valid
    while(!isValid){
        isValid=false;

        //gets entry
        cin>>entry;

        //if we want a number but get a letter, tells user to enter number
        if (cin.fail()) { 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Invalid input, please enter a number." << endl;
            continue;
        }

        //if valid number checks if within range
        if(min==0||min==1||min==3){
            if(entry>=min&& entry<=max){
                isValid=true;
            }
            else{
                cout<<"Invalid input, try again."<<endl;
            }

        }
        else{ //if letter wanted, checks if its within range
            if(entry==max||entry==min){
                isValid=true;
            }
            else{
                cout<<"Invalid input, try again."<<endl;
            }
        }

    }
    return entry;

}

#endif