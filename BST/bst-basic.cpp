#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
class bst
{
private:
    node *root;
    void preorder(node *root)
    { // PLR
        if (root == NULL)
        {
            return;
        }
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
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
    node *deletenode(node *root, int key)
    { // delete by value
        if (root == NULL)
        {
            return root;
        }
        if (key < root->data)
        {
            root->left = deletenode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = deletenode(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            { // no left child
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                // no right child
                node *temp = root->left;
                delete root;
                return temp;
            }
            else
            { // If both have childs :)
                node *temp = findmin(root->right);
                root->data = temp->data;
                root->right = deletenode(root->right, temp->data);
            }
            return root;
        }
    }
    node *findmin(node *n)
    {
        while (n && n->left != NULL)
        {
            n = n->left;
        }
        return n;
    }

public:
    void insert(int data)
    {
        root = insert(root, data);
    }
    void preorder()
    {
        preorder(root);
    }
    void deletenode(int key)
    {
        root = deletenode(root, key);
    }
    bst()
    {
        root = NULL;
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