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
class singly
{
private:
    node *head;
    node *tail;

public:
    singly()
    {
        head = tail = NULL;
    }
    void traverse()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void insert(int data)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }

    void insert_back(int data)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }
    void found()
    {
        node *slow = head;
        node *fast = head;
        bool chk = false;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                // cout<<"True "<<endl;
                chk = true;
                break;
            }
        }
        if (chk)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }
};
int main()
{
    singly s;
    s.insert(1);
    s.insert_back(2);
    s.insert_back(3);
    s.insert_back(4);
    s.insert_back(2);
    s.traverse();
    s.found();

    return 0;
}
