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
public:
    node *head;
    node *tail;

    singly()
    {
        head = tail = NULL;
    }

    void insert_front(int data)
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

    void traverse()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    node *nth(int n)
    {
        node *temp = head;
        int length = 0;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        if (length == n)
        {
            node *newhead = head->next;
            head->next = NULL; // grabage collector
            return newhead;
        }
        temp = head;
        int rev = length - n;
        while (temp != NULL)
        {
            rev--;
            if (rev == 0)
            {
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        node *deletenode = temp->next;
        temp->next = temp->next->next;
        return head;
    }
};
int main()
{

    singly l1;
    l1.insert_back(1);
    l1.insert_back(3);
    l1.insert_back(5);
    l1.nth(2);
    l1.traverse();
    return 0;
}
