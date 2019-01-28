#include<iostream>
#include<chrono>
const int SIZE = 100;
using namespace std;

class algorithm{
private:
    char arr[SIZE];
public:
    int siz;

    algorithm(){
        cout<<"Enter the size of array to be sorted: "<<endl;

        //Size of array input here
        cin>>siz;
        cout<<"Enter the character array line by line: "<<endl;

        //Array input here
        for(int i=0; i<siz; i++){
            cin>>arr[i];
        }
    }

    void display(){

        //Display elements of the list

        cout<<"The elements are: "<<endl;
        for(int i=0; i<siz; i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl<<endl;
    }

    void insertionSort(int n){

        //Sort the list in descending order using recursion

        if (n <= 1) 
            return; 
    
        insertionSort(n-1); 
    
        char key = arr[n-1]; 
        int j = n-2; 
    
        while (j >= 0 && int(arr[j]) < int(key)){
            arr[j+1] = arr[j]; 
            j--; 
        } 
        arr[j+1] = key; 
    }

    void selectionSort(int n){

        //Insertion sort using iteration

        int max; 
    
        for (int i = 0; i < n-1; i++) 
        { 
            max = i; 
            for (int j = i+1; j < n; j++){
                if (int(arr[j]) > int(arr[max])){
                    max = j;
                } 
            }

            char temp = arr[max];
            arr[max] = arr[i];
            arr[i] = temp;  
 
        } 
    } 

};

int main(){
    algorithm insert;

    //Another object is not explicitly initialized, to avoid taking two inputs for the process.
    algorithm select = insert;

    //Before Sorting
    cout<<"Before Sort: "<<endl;
    insert.display();

    //Insertion Sort including characters
    cout<<"After Insertion Sort: "<<endl;
    insert.insertionSort(insert.siz);
    insert.display();

    //Selection Sort including characters
    cout<<"After Selection Sort: "<<endl;
    select.selectionSort(select.siz);
    select.display();

    return 0;

}