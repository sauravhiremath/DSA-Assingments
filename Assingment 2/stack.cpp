#include<iostream>
#include<regex>
const int MAX = 5;
using namespace std;


class stackSort{
private:
    int arr[MAX];
    int top = -1;
public:
    stackSort(){
        cout<<"Enter only registeration number in the form 18BCExxxx"<<endl;
    }

    bool isEmpty(){
        if(top==-1 || top >= MAX-1){return true;}
        return false;
    }

    bool isValid(string key){
        regex regNo("18BCE[0-9]{4}");
        if(regex_match(key.begin(), key.end(), regNo)){return true;}
        return false;
    }

    void push(string key){
        if (isEmpty() && isValid(key)){
            top++;
            arr[top] = stoi(key.substr(5));
            insertionSort(top);
            cout<<key<<" is pushed to stack successfully"<<endl;
        }
        else if(isValid(key)==false){cout<<"Enter Valid Reg Number please"<<endl;}
        else{cout<<"Traceback Error: Stack Overflow"<<endl;}
    }

    bool isFull(){
        if(top != -1){return true;}
        return false;
    }

    string pop(){
        if(isFull()){
            top--;
            insertionSort(top);
            return "18BCE"+ to_string(arr[top+1]);
        }
        else{return "\tTraceback Error: Stack Underflow";}
    }

    void insertionSort(int n){

        //Sort the list in ascending order using recursion

        if (n <= 1) 
            return; 
    
        insertionSort(n-1); 
    
        char key = arr[n-1]; 
        int j = n-2; 
    
        while (j >= 0 && int(arr[j]) > int(key)){
            arr[j+1] = arr[j]; 
            j--; 
        } 
        arr[j+1] = key; 
    }

};

int main(){
    stackSort p;
    int check;
    bool conti = true;
    string userInp;

    while(conti == true){

        cout<<"1 for Push() operation\n2 for Pop() operation\n3 for END operation"<<endl;
        cin>>check;

        switch(check){
            case 1: {cout<<"Enter valid reg number: ";cin>>userInp; p.push(userInp);}
                break;
            case 2: {cout<<"The Reg Number popped out is: "<<p.pop()<<endl;}
                break;
            case 3: conti = false;
                break;
            default: cout<<"Enter Valid Command"<<endl;
                break;
        }
    }
}