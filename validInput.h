#ifndef VALID_H
#define VALID_H
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T validInput(string prompt,T max, T min){
    T entry;
    bool isValid = false;

    cout<<prompt<<endl;

    while(!isValid){
        isValid=false;
        cin>>entry;
        if(min==0||min==1){
            if(entry>=min&& entry<=max){
                isValid=true;
            }
            else{
                cout<<"Invalid input, try again."<<endl;
            }

        }
        else{
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