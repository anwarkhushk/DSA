#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

public:
    node(int data)
    {
        this->data = data;
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
    void back(int data)
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
    void popfront()
    {
        if (head == NULL)
        {
            return;
        }
        node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    void popback()
    {
        node *temp = head;
        if (head == NULL)
        {
            return;
        }
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
        
    }
    int search(int key){
        int index=-1;
        node* temp=head;
        while(temp!=NULL){
            if(temp->data==key){
                cout<<"Found "<<endl;
                return index;
            }
            else{
                temp=temp->next;
                index++;
            }
        }
        return -1;
    }
    void middle(int value,int position){
        node* newnode=new node(value);
        node* temp=head;
        if(position<0){
            return;
        }
        else if(position==0){
            insert(value);
        }
        for(int i=0; i<position-1;i++){
            temp=temp->next;
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
};
int main()
{
    singly s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.back(5);
    s.traverse();
    s.popfront();
    s.traverse();
    s.popback();
    s.traverse();
    s.search(3);
    s.middle(9,2);
    s.traverse();

    return 0;
}
