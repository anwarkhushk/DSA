#include <iostream>
#include <string>
using namespace std;
#define endl '\n'
class management
{
private:
    string name;
    int price;
    int quantity;
    string c_name;
    int priority;

public:
    management(string n = "", int p = 0, int q = 0, string c_n = "", int pr = 0)
    {
        name = n;
        price = p;
        quantity = q;
        c_name = c_n;
        priority = pr;
    }

    string getname() { return name; }
    int getprice() { return price; }
    int getquantity() { return quantity; }
    string getcname() { return c_name; }
    int getpriority() { return priority; }
};

class heap
{
private:
    management *arr;
    int capacity;
    int size;

public:
    heap(int cap)
    {
        capacity = cap;
        arr = new management[cap + 1];
        size = 0;
    }

    void insert()
    {
        if (size == capacity)
        {
            cout << "Heap Overflow\n";
            return;
        }

        string name, c_name;
        int price, quantity, priority;
        cout << "enter product name ";
        cin >> name;
        cout << "enter price ";
        cin >> price;
        cout << "enter quantity ";
        cin >> quantity;
        cout << "enter customer name";
        cin >> c_name;
        cout << "enter priority";
        cin >> priority;

        management val(name, price, quantity, c_name, priority);

        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent].getpriority() < arr[index].getpriority())
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                break;
        }
    }

    void deletee()
    {
        if (size == 0)
        {
            cout << "Nothing to delete"<<endl;
            return;
        }

        cout << "Serving order " << arr[1].getname() << " for " << arr[1].getcname() << endl;

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (true)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left].getpriority() > arr[largest].getpriority())
                largest = left;
            if (right <= size && arr[right].getpriority() > arr[largest].getpriority())
                largest = right;

            if (largest == i)
                break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    void print()
    {
        if (size == 0)
        {
            
            return;
        }

        
        for (int i = 1; i <= size; i++)
        {
            cout << "Item " << arr[i].getname()
                 << ", Price " << arr[i].getprice()
                 << ", Quantity " << arr[i].getquantity()
                 << ", Customer " << arr[i].getcname()
                 << ", Priority " << arr[i].getpriority() << endl;
        }
    }
};
int main()
{
    heap h(100); 
    int choice;

    while (true)
    {
        cout << "\n1. Insert new order\n2. Serve highest priority order\n3. Display all orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            h.insert();
            break;
        case 2:
            h.deletee();
            break;
        case 3:
            h.print();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice "<<endl;
        }
    }
}
