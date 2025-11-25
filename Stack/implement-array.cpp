#include <iostream>
using namespace std;
class myarr
{
private:
    int top;
    int *arr;
    int size;

public:
    myarr(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    void insert(int x)
    {
        if (isfull())
        {
            cout << "OVERFLOW" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (isempty())
        {
            cout << "UNDERFLOW" << endl;
            return;
        }
        int temp = arr[top];
        cout << "The value which is to be deleted is " << temp << endl;
        top--;
    }
    int peek()
    {
        if (isempty())
        {
            cout << "Underflow" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isempty()
    {
        return top == -1;
    }
    bool isfull()
    {
        return top == size - 1;
    }
    void display()
    {
        if (isempty())
        {
            cout << "Underflow" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
myarr a(5);
a.insert(1);
a.insert(2);
a.insert(3);
a.insert(4);
a.insert(5);
a.display();
a.peek();
a.pop();


    return 0;
}