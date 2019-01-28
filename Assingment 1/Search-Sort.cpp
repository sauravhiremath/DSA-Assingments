#include<iostream>
#include<chrono>
const int SIZE = 100;
using namespace std;

class algorithm{
private:
    int start=0,mid;
    int arr[SIZE];
public:
    int end,key;

    algorithm(){
        cout<<"Enter the size of array to be sorted: "<<endl;

        //Size of array input here
        cin>>end;
        cout<<"Enter the array line by line in descending order: "<<endl;

        //Array input here
        for(int i=0; i<end; i++){
            cin>>arr[i];
        }

        //Input for key to be found in array
        cout<<"Enter key to be found: "<<endl;
        cin>>key; 
    }

    int binarySearch(int key, int end, int start = 0){

        //Recursive Approach to Binary Search

        if (end >= start) { 
            int mid = (start + end) / 2; 
    
            if (arr[mid] == key) 
                return mid; 
    
            if (arr[mid] > key) 
                return binarySearch(key, end, mid + 1); 
    
            return binarySearch(key, mid - 1, start); 
        } 
    
        return -2; 
    }

    int linearSearch(int key, int start=0){

        //Recursive method for linear Search

        if(arr[start]==key){
            return start;
        }
        if(start == end){
            return -2;
        }
        else{
            return linearSearch(key,start+1);
        }
    }

    int checkOrder(){

        //Returns '1' if the order is not descending, returns '0' if order is descending

        int check = 0;
        for(int i = 0 ; i < end - 1 ; i++ ){
            if( arr[i] < arr[i+1] ){
                check++;
                break;
            }
        }

        return check;
    }

    void display(){

        //Display elements of the list

        cout<<"The elements in descending order are: "<<endl;
        for(int i=0; i<end; i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }

    void insertionSort(int n){

        //Sort the list in descending order if not given so

        if (n <= 1) 
            return; 
    
        insertionSort(n-1); 
    
        int key = arr[n-1]; 
        int j = n-2; 
    
        while (j >= 0 && arr[j] < key){
            arr[j+1] = arr[j]; 
            j--; 
        } 
        arr[j+1] = key; 
    } 

};

int main(){
    algorithm array;
    int position_bin_search, position_lin_search, check = 0;
 
    //Check the order of elements in array
    check = array.checkOrder();

    if(check==1){
        array.insertionSort(array.end);
    }

    array.display();

    //Binary Search
    position_bin_search = array.binarySearch(array.key, array.end, 0);
    cout<<"The number is found at position by Binary Search: "<<position_bin_search+1<<endl;

    //Linear Search
    position_bin_search = array.binarySearch(array.key, array.end, 0);
    cout<<"The number is found at position by Binary Search: "<<position_bin_search+1<<endl;
    
    //Insertion-sort including characters
    

    //Sub-Part for timing of the Search Algorithms

    //                          //Binary Search
    // auto start = std::chrono::high_resolution_clock::now();
    // position_bin_search = array.binarySearch(array.key, array.end, 0);
    // cout<<"The number is found at position by Binary Search: "<<position_bin_search+1<<endl;
    // auto finish = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> elapsed = finish - start;
    // cout << "Elapsed time for Binary Search is: " << elapsed.count() << " s\n";

    //                          //Linear Search
    // auto start = std::chrono::high_resolution_clock::now();
    // position_lin_search = array.linearSearch(array.key);
    // cout<<"The number is found at position by Linear Search: "<<position_lin_search+1<<endl;
    // auto finish = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> elapsed = finish - start;
    // cout << "Elapsed time for Linear Search is: " << elapsed.count() << " s\n";



    return 0;

}