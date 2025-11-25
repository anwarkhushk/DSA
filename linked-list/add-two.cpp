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
 node* add_two(node* h1,node* h2){
node* t1=h1;
node* t2=h2;
node* dummynode=newnode(-1);
node*curr=dummynode;
int carry=0;
while(t1!=NULL || t2!=NULL){
int sum=carry;
if(t1){
sum=sum+t1->data;
}
if(t2){
sum=sum+t2->data;
}
newnode=new node(sum%10);
carry=sum/10;
}
curr=curr->next;
if(t1) t1=t1->next;
if(t2) t2=t2->next;

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
