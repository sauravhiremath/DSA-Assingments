#include<iostream>
#include<regex>
const int MAX = 5;
using namespace std;

class printer{
private:
    int front = -1,rear = -1;
    string queue[MAX];
public:
    int size;

    bool isValid(string key){
        regex regNo("18BCE[0-9]{4}");
        if(regex_match(key.begin(), key.end(), regNo)){return true;}
        return false;
    }

    void insertq(string item)
    {
        if(isValid(item)){
            if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
            {
                cout<<"Queue is full"<<endl;
                return;
            }
            else if (rear ==  - 1)
            {
                rear++;
                front++;
            }
            else if (rear == MAX - 1 && front > 0)
            {
                rear = 0;
            }
            else
            {
                rear++;
            }
            queue[rear] = item;
            size = front > rear ? (MAX - front + rear + 1) : (rear - front + 1);
            insertionSort(size);
        }
        else{
            cout<<"Enter valid reg number"<<endl;
        }
    }

    void insertionSort(int size){

        int i, j;
        string key;
        for (i = 1; i <size; i++){

            string key = queue[size-1].substr(queue[size-1].size() - 4);
            string fullkey = queue[i]; 
            j = i-1; 
        
            while (j >= 0 && stoi(queue[j].substr(queue[j].size() - 4)) < stoi(key)){ 

                queue[j+1] = queue[j]; 
                j = j-1; 
            } 
            queue[j+1] = fullkey; 
        } 
    }

    void deleteq(){
        if (front ==  - 1){
            printf("Queue is empty ");
        }

        else if (front == rear){
            cout<<queue[front]<<" is deleted"<<endl;
            front =  - 1;
            rear =  - 1;
            size = front > rear ? (MAX - front + rear + 1) : (rear - front + 1);
            insertionSort(size);
        }

        else{
            cout<<queue[front]<<" is deleted"<<endl;
            front++;
            size = front > rear ? (MAX - front + rear + 1) : (rear - front + 1);
            insertionSort(size);
        }
    }

    void display(){

        int i;
        if (front > rear){

            for (i = front; i < MAX; i++){
                cout<<queue[i]<<endl;
            }
        }
        else{
            for (i = front; i <= rear; i++){
                cout<<queue[i]<<endl;
            }
        }
    }
};

int main(){
    printer p;
    int choice;
    string reg;
    bool finish = true;
    while(finish){
        cout<<"CIRCULAR QUEUE:\n1. Insert Element \n2. Delete Element\n3. Display Elements in the Queue\n0. Exit"<<endl;
        cout<<"Enter Choice"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter Reg Number: ";
                cin>>reg;
                p.insertq(reg);
                cout<<"The size is "<<p.size<<endl;
                break;
            case 2:
                p.deleteq();
                cout<<"THe size is "<<p.size<<endl;
                break;
            case 3:
                p.display();
                break;
            case 0:
                finish = false;
                break;
            default:
                cout<<"Enter valid Choice..."<<endl;
        }
    }

}