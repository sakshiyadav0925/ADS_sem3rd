#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

node* insertNode(node* root, int key)
{
    if (root == NULL)
    {
        return new node(key);
    }

    if (key < root->data)
    {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insertNode(root->right, key);
    }

    return root;
}

node* findMin(node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

node* deleteNode(node* root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    else
    {
    
        if (root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

    
        node* successor = findMin(root->right);

        root->data = successor->data;

        root->right = deleteNode(root->right, successor->data);
    }

    return root;
}

void inorder(node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 11);
    root = insertNode(root, 5);
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 25);
    root = insertNode(root, 45);
    root = insertNode(root, 22);
    root = insertNode(root, 40);

    cout << "BST before deletion: ";
    inorder(root);

    root = deleteNode(root, 10);

    cout << "BST after deletion: "<<endl;
    inorder(root);

    return 0;
}