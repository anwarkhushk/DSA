#include <iostream>
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
        count = 0;
        this->data = data;
        left = right = NULL;
    }
};
class bst
{
private:
    node *root;
    int maxh;
    void preorder(node *root, int count)
    { // PLR
        if (root == NULL)
        {
            return;
        }
        // cout << root->data;

        count++;
        if (count > maxh)
        {
            maxh = count;
        }
        preorder(root->left, count);
        preorder(root->right, count);
    }
    node *insert(node *r, int val)
    {
        if (r == NULL)
        {
            return new node(val);
        }
        if (val < r->data)
        {
            r->left = insert(r->left, val);
        }
        else if (val > r->data)
        {
            r->right = insert(r->right, val);
        }
        return r;
    }

public:
    void insert(int data)
    {
        root = insert(root, data);
    }
    void preorder()
    {
        maxh = 0;
        preorder(root, 0);
        cout << "Hright of binary is " << maxh << endl;
    }

    bst()
    {
        root = NULL;
        maxh = 0;
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
    b.preorder();
    return 0;
}