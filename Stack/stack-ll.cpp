#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class ss
{
private:
    node *head;

public:
    ss()
    {
        head = NULL;
    }
    bool empty()
    {
        return head == NULL;
    }
    void push(int x)
    {
        node *newnode = new node(x);
        if (empty())
        {
            head = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Underflow " << endl;
            return;
        }
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    int peek()
    {
        if (empty())
        {
            return -1;
        }
        return head->data;
    }
    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    ss a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.print();
    cout << a.peek() << endl;

    return 0;
}