// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// //Array
// //1. array to max heap
// //2.1. delete top element
// //2.2. store in ans
// //2.3. heapify the array
// //till all elemnt empty form array
// void heapify(int arr[],int n,int index){
   
//         int largest = index;
//         int left = 2*index+1;
//         int right = 2*index + 2;
//         if(left<n && arr[left]>arr[largest]){
//             largest = left;
//         }
//         if(right < n && arr[right] > arr[largest]){
//             largest = right;
//         }
//         if(largest != index){
//             swap(arr[largest],arr[index]);
//             heapify(arr,n,largest);
//         }
    
// }

// void BuildMaxHeap(int arr[],int n){
//      for(int i=n/2-1;i>=0;i--){
//         heapify(arr,n,i);
//      }

// }
// void deletion(int arr[],int &N){
//     swap(arr[0],arr[N-1]);
//     N--;
//     heapify(arr,N,0);
// }
// void sortArray(int arr[],int n){
//     while(n){
//     swap(arr[0],arr[n-1]);
//     n--;
//     heapify(arr,n,0);
//     }
// }

// int main(){
//     int arr[] = {95,46,15,78,23,87,23,58,4,78,70,32,44,22};
//     int N = 14;
//     BuildMaxHeap(arr,N);
//     //vector<int> ans;

//     // while(N){
//     //     int temp = arr[0];
//     //     deletion(arr,N);
//     //     ans.push_back(temp);
//     // }
//     // reverse(ans.begin(),ans.end());
//     sortArray(arr,N);
//     for(int i=0;i<N;i++){
//         cout<<arr[i]<<",";
//     }
//     cout<<endl;

//     return 0;
// }

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {95, 46, 15, 78, 23, 87, 23, 58, 4, 78, 70, 32, 44, 22};
    int N = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, N);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;

    return 0;
}
