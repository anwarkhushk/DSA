#include <iostream>
using namespace std;
#define endl '\n'
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
    void reverse()
    {
        node *prev = NULL;
        node *curr = head;
        node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail=head;
        head=prev;
    }
};
int main(){
singly s;
s.insert(1);
s.insert_back(2);
s.insert_back(3);
s.insert_back(4);
s.insert_back(5);
s.traverse();
s.reverse();
cout<<endl;
s.traverse();

    return 0;
}
