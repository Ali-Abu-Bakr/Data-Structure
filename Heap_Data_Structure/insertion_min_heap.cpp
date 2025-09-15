#include<iostream>
using namespace std;

class MinHeap{
    int *arr;
    int size;
    int total_size;
    public:
     MinHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
     }

     //insertion in min heap
     void insertion(int value){
        //check for over flow
        if(size == total_size){
            cout<<"Min Heap overflow\n";
            return;
        }
      
        arr[size] = value;
        int index = size;
        size++;

        //ab sahi jagah per lao step up
        while(index>0 && arr[index] < arr[(index-1)/2]){
            swap(arr[(index-1)/2],arr[index]);
            index = (index-1)/2;
        }
        cout<<arr[index]<<" inserted in min Heap\n";

     }
     void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
     }
};

int main(){
    MinHeap h1(6);

    h1.insertion(10);
    h1.insertion(20);
    h1.insertion(5);
    h1.insertion(7);
    h1.insertion(3);
    h1.insertion(2);
    h1.insertion(1); // will show overflow

    h1.print(); // should show elements in min-heap order

    return 0;
}
