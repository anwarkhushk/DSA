#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node(int data) {
        this->data = data;
        next = NULL;
    }
};

class singly {
private:
    node *head;
    node *tail;

public:
    singly() {
        head = tail = NULL;
    }

    void traverse() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert(int data) {
        node *newnode = new node(data);
        if (!head) {
            head = tail = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }

    void insert_back(int data) {
        node *newnode = new node(data);
        if (!head) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void remove() {
        node* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->data == temp->next->data) {
                node* deletee = temp->next;
                temp->next = temp->next->next;
                delete deletee;
            } else {
                temp = temp->next;
            }
        }
    }
};

int main() {
    singly s;
    s.insert(1);
    s.insert_back(2);
    s.insert_back(2);
    s.insert_back(4);
    s.insert_back(4);

    s.traverse(); 

    s.remove();

    s.traverse(); 

    return 0;
}
