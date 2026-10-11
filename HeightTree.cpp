#include<iostream>
using namespace std;

struct node {
    int val;
    node*left;
    node*right;
    node(int data)
    {
        val= data;
        left = right = NULL ;

    }
};

int Height(node*root)
{
    if(root == NULL)
    return 0;
    else 
     left =Height(root->left) ;
    int right = Height(root->right);
     if(left > right)
    return 1+left ;
     else 
    return 1+right ;

}

int main() {
    node*root = new node(1);
    root->left = new node(2) ;
    root->right = new node(3) ;
    root->left->left = new node(4) ;
    root->left->right= new node(5);
    root->right->right = new node(6) ;
    root->right->right->left = new node(7) ;


    cout<<"Height of a tree: "<<Height(root) ;


    return 0;

}