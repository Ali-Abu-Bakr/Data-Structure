#include <iostream>
using namespace std;

class MinHeap
{
    int *arr;
    int size;
    int total_size;

public:
    MinHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // heapify
    void heapify(int index)
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // small will store smalles among three
        if (left < size && arr[smallest] > arr[left])
        {
            smallest = left;
        }

        if (right < size && arr[smallest] > arr[right])
        {
            smallest = right;
        }
        if (smallest != index)
        {
            swap(arr[smallest], arr[index]);
            heapify(smallest);
        }
    }

    // deletion in min heap
    void deletion()
    {
        // check for underflow
        if (size == 0)
        {
            cout << "Min Heap Underflow\n";
            return;
        }
        // last index ko root per le jao
        arr[0] = arr[size - 1];
        // delte last index
        size--;

        // heapify
        heapify(0);
    }

    // insertion in min heap
    void insertion(int value)
    {
        // check for over flow
        if (size == total_size)
        {
            cout << "Min Heap overflow\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        // ab sahi jagah per lao step up
        while (index > 0 && arr[index] < arr[(index - 1) / 2])
        {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }
        cout << arr[index] << " inserted in min Heap\n";
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~MinHeap()
    {
        delete[] arr;
    }
};

int main()
{
    MinHeap h1(6);

    h1.insertion(10);
    h1.insertion(20);
    h1.insertion(5);
    h1.insertion(7);
    h1.insertion(3);
    h1.insertion(2);
    h1.insertion(1); // will show overflow

    h1.print(); // should show elements in min-heap order

    h1.deletion();
    h1.print();

    h1.deletion();
    h1.print();

    h1.deletion();
    h1.print();

    return 0;
}
