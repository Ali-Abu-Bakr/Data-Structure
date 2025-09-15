#include <iostream>
using namespace std;

class MaxHeap
{
  int *arr;
  int size;       // current size of heap
  int total_size; // total capacity of heap
public:
  MaxHeap(int n)
  {
    arr = new int[n];
    size = 0;
    total_size = n;
  }

  // insertion of element in to heap
  void insert(int value)
  {
    if (size == total_size)
    {
      cout << "Heap Overflow" << endl;
      return;
    }

    arr[size] = value;
    int index = size;
    size++;

    // ab sahi position ko elemnt per pahuchana hai
    while (index > 0 && arr[(index - 1) / 2] < arr[index])
    {
      swap(arr[(index - 1) / 2], arr[index]);
      index = (index - 1) / 2;
    }
    cout << arr[index] << " inserted in heap\n";
  }

  // heapify function
  void heapify(int index)
  {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest])
    {
      largest = left;
    }

    if (right < size && arr[right] > arr[largest])
    {
      largest = right;
    }

    if (largest != index)
    {
      swap(arr[index], arr[largest]);
      heapify(largest);
    }
  }

  // deletion of element from heap
  void deletion()
  {
    if (size == 0)
    {
      cout << "Heap Underflow\n";
      return;
    }
    // 1. last index ko root se replace karenge
    arr[0] = arr[size - 1];
    // 2. last ko hata denge
    size--;

    // 3. heapify karenge
    heapify(0);
  }

  // print heap
  void print()
  {
    for (int i = 0; i < size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  ~MaxHeap()
  {
    delete[] arr;
  }
};

int main()
{

  MaxHeap h1(5);

  h1.insert(9);
  h1.insert(5);
  h1.insert(1);
  h1.print();
  h1.insert(7);
  h1.insert(8);
  h1.insert(2);
  h1.print();
  h1.deletion();
  h1.deletion();
  h1.deletion();
  h1.print();

  return 0;
}