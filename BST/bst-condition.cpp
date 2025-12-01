#include <iostream>
#include <climits>
using namespace std;

class node
{
public:
    int data;
    int count;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        count = 0;
        left = right = NULL;
    }
};

class bst
{
private:
    node *root;
    bool ischk;

    void preorder(node *root, int minVal, int maxVal)
    {
        if (root == NULL)
            return;

        if (root->data <= minVal || root->data >= maxVal)
        {
            ischk = false;
        }

        preorder(root->left, minVal, root->data);
        preorder(root->right, root->data, maxVal);
    }

    node *insert(node *r, int val)
    {
        if (r == NULL)
            return new node(val);

        if (val < r->data)
            r->left = insert(r->left, val);
        else if (val > r->data)
            r->right = insert(r->right, val);

        return r;
    }

public:
    bst()
    {
        root = NULL;
        ischk = true;
    }

    void insert(int data)
    {
        root = insert(root, data);
    }

    void check()
    {
        ischk = true;
        preorder(root, INT_MIN, INT_MAX);

        if (ischk)
            cout << "It is a BST" << endl;
        else
            cout << "It is not a BST" << endl;
    }
};

int main()
{
    bst b;
    b.insert(5);
    b.insert(3);
    b.insert(7);
    b.insert(1);
    b.insert(4);

    b.check();

    return 0;
}
