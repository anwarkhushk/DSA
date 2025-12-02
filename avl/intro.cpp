#include <iostream>
using namespace std;
class node
{
public:
    int data;
    int height;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = right = NULL;
        height = 1;
    }
};
class avl
{
private:
    node *root;
    void preorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    int height(node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        return (root->height);
    }
    int getbalance(node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        return height(root->left) - height(root->right);
    }
    int max(int a, int b)
    {
        if (a > b)
            return a;
        return b;
    }

    // rotations :)
    node *rightrotation(node *root)
    {
        // LL case
        node *x = root->left;
        node *x2 = x->right;

        x->right = root;
        root->left = x2;

        root->height = 1 + max(height(root->left), height(root->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }
    node *leftrotation(node *root)
    {
        // LL case
        node *x = root->right;
        node *x2 = x->left;
        x->left = root;
        root->right = x2;

        root->height = 1 + max(height(root->left), height(root->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }

    node *insert(node *root, int val)
    {
        if (root == NULL)
        {
            return new node(val);
        }
        if (val < root->data)
        {
            root->left = insert(root->left, val);
        }
        else if (val > root->data)
        {
            root->right = insert(root->right, val);
        }
        else
        {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getbalance(root);

        if (balance > 1 && val < root->left->data)
        {
            return rightrotation(root);
        }
        if (balance < -1 && val < root->right->data)
        {
            return leftrotation(root);
        }
        if (balance > 1 && val > root->left->data)
        {
            root->left = leftrotation(root);
            return rightrotation(root);
        }
        if (balance < -1 && val < root->right->data)
        {
            root->right = rightrotation(root);
            return leftrotation(root);
        }
        return root;
    }

public:
    void preorder()
    {
        preorder(root);
    }
    void insert(int data)
    {
        root = insert(root, data);
    }
    avl()
    {
        root = NULL;
    }
};
int main()
{
    avl a;
    a.insert(1);
    a.insert(2);
    a.insert(133);
    a.insert(112);
    a.insert(109);
    a.preorder();
}