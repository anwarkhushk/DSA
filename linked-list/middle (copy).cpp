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
    int middle(){
        node* slow=head;
        node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        int temp=slow->data;
        return temp;
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
cout<<endl;
cout<<s.middle()<<endl;
// cout<<endl;
// s.traverse();

    return 0;
}
