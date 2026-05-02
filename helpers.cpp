template <typename T>
T validInput(T c, int a){
    string type;
    switch(t){
        case "i":
            type=int;
        case ch:
            type=char;
        default:
        cout<<"ERROR: Check programMenu";
        return;
    }
    if(type==i){
        if(c>=0&&c<a+1){
            return true;
        }
        else{
            cout<<"ERROR: enter valid input"
            return false;
        }
    }
    else{
        if(c!="X"||c!="x"||x!="O"||c!="o"){
           cout<<"ERROR: enter valid input"
            return false; 
        }
        else{
            return true;
        }
    }
}
programMenu(int choice){
    cout<<"--------------------TIC-TAC-TOE-----------------------"<<endl<<cout<<"                      Welcome!                      "<<endl;
    cout<<"Start Game (1)    View Score Board (2)   Exit Menu (3)"endl;
    cin>>choice
    choice=validInput<int>(choice,3);
}