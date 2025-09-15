#include<iostream>
using namespace std;

class MaxHeap{
    int *arr;
    int size; //total element in heap
    int total_size; //total size of array
    public:
    //constructor of max heap
     MaxHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
     }
     //insertion function
     void insert(int value){

        //agar heap pura bhara hai toh overflow hoga
        if(size == total_size){
            cout<<"Heap Overflow\n";
            return;
        }
        //
        arr[size] = value;
        int index = size;
        size++;

        //ab sahi position per pahuchana hai 
        while(index > 0 && arr[index]>arr[(index-1)/2]){
           swap(  arr[index],arr[(index-1)/2]);
            index = (index-1)/2;
        }
        cout<<arr[index]<<" inserted in heap\n";
     }

     //ab heap ko print karne ka function
     void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
     }
};

int main(){
    MaxHeap h1(6);
    h1.insert(4);
    h1.insert(14);
    h1.insert(11);
    h1.print();
    h1.insert(114);
    h1.insert(24);
    h1.insert(1);
    h1.insert(10);
    h1.print();
   // h1.insert(14);
    return 0;
}