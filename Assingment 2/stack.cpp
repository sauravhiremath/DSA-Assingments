#include<iostream>
const int MAX = 5;
using namespace std;


class stack{
private:
    string arr[MAX];
    int top = -1;
public:
    stack(){
        cout<<"Enter only registeration number in the form 18BCExxxx"<<endl;
    }

    bool isEmpty(){
        if(top==-1 || top != MAX){return true;}
        return false;
    }

    bool isValid(string key){
        if(key[0]=='1' && key[1]=='8' && key[2]=='B' && key[3]=='C' && key[4]=='E' && key[5]){return true;}
        return false;
    }
    void push(string key){
        if (isEmpty() && isValid(key)){
            top++;
            arr[top] = key;;
        }
        else{
            cout<<"Traceback Error: Stack Overflow"<<endl;
        }
    }

    bool isFull(){
        if(top != -1){return true;}
        return false;
    }

    string pop(){
        if(isFull()){
            top--;
            return arr[top+1];
        }
        else{
            cout<<"Traceback Error: Stack Underflow"<<endl;
            return "ERROR";
        }
    }
};

int main(){
    stack p;
    int check;
    string userInp;
    cout<<"1 for Push() operation\n2 for Pop() operation"<<endl;
    cin>>check;

    switch(check){
        case 1: {cout<<"Enter valid reg number: ";cin>>userInp;p.push(userInp);}
    }
}