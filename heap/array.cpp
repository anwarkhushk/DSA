#include <iostream>
using namespace std;

class heap
{
private:
    int *arr;
    int capacity;
    int size;

public:
    heap(int cap)
    {
        capacity = cap;
        arr = new int[cap + 1];
        size = 0;
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap Overflow\n";
            return;
        }

        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                break;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // corrected delete
    void deletee()
    {
        if (size == 0)
        {
            cout << "Nothing to delete\n";
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (true)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest])
                largest = left;

            if (right <= size && arr[right] > arr[largest])
                largest = right;

            if (largest == i)
                break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    // corrected heapify function (recursive)
    void hepify(int A[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left < n && A[left] > A[largest])
            largest = left;

        if (right < n && A[right] > A[largest])
            largest = right;

        if (largest != i)
        {
            swap(A[i], A[largest]);
            hepify(A, n, largest);
        }
    }

    // wrapper to call hepify on internal data
    void call_heapify()
    {
        hepify(arr, size + 1, 1);
    }
};


int main()
{
    heap h(5);

    h.insert(50);
    h.insert(40);
    h.insert(33);
    h.insert(30);
    h.insert(60);

    h.print();

    h.deletee();
    h.call_heapify();  // valid call

    h.print();
}
