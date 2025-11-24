#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        next = NULL;
    }
};

class singly {
public:
    node* head;
    node* tail;

    singly() {
        head = tail = NULL;
    }


    void insert_front(int data) {
        node* newnode = new node(data);
        if(head == NULL) {
            head = tail = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }


    void insert_back(int data) {
        node* newnode = new node(data);
        if(head == NULL) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void traverse() {
        node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


node* mergeLists(node* h1, node* h2) {

    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;

    if(h1->data <= h2->data) {
        h1->next = mergeLists(h1->next, h2);
        return h1;
    }
    else {
        h2->next = mergeLists(h1, h2->next);
        return h2;
    }
}

int main() {


    singly l1;
    l1.insert_back(1);
    l1.insert_back(3);
    l1.insert_back(5);


    singly l2;
    l2.insert_back(2);
    l2.insert_back(4);
    l2.insert_back(6);


    node* mergedHead = mergeLists(l1.head, l2.head);


    node* temp = mergedHead;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
