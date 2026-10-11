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

//1 number of nodes as count node
int CountNode(node*root)
{
    if(root==NULL)
    return 0;

    return 1+CountNode(root->left)+CountNode(root->right) ;
}

//2  heigth of tree
int Height(node*root)
{
    if(root == NULL)
    return 0;
    else 
     left = Height(root->left) ;
    int right = Height(root->right);
     if(left > right)
    return 1+left ;
     else 
    return 1+right ;

}
//3
int CountLeaf(node*root)
{
    if(root == NULL)
    return 0;
    if (root->left==NULL && root->right==NULL)
    return 1;
    else
    return CountLeaf(root->left)+CountLeaf(root->right);

}
//4 Count Nodes with 1 child
int Count1Child(node*root) {
    if(root ==NULL)
     return 0 ;
     else{

        if(root->left!=NULL && root->right ==NULL)
        return 1+ Count1Child(root->left)  ;
        else if (root->left==NULL && root->right!=NULL)
        return 1 + Count1Child(root->right) ;
     }
    
      return Count1Child(root->left) + Count1Child(root->right) ;
}

//5. Count node with 2 child 
int Count2Child(node*root)
{
    if(root ==NULL)
     return 0 ;
    if(root->left !=NULL && root->right!=NULL)
    return 1+ Count2Child(root->left) + Count2Child(root->right) ;
    else
    return Count2Child(root->left) + Count2Child(root->right) ;

}

//6.Sum of nodes in the tree
int SumNode(node*root)
{
    if(root ==NULL)
     return 0 ;

    else
    return root->data + SumNode(root->left) +SumNode(root->right)  ;

}

//7.Travesing (a).Inorder
int Inorder(node*root)
{
    if(root==NULL)
     return ;
    Inorder(root->left) ;
    cout<< root->data;
    Inorder(root->right) ;

}

//8.Traversing (b).Preorder
int Preorder(node*root) {
    if(root==NULL)
    return ;
    cout<<root->data;

    Preorder(root->left);
    Preorder(root->right) ;


}
//7.Traversing (c).Postorder
int Postorder(node*root)
{
    if(root==NULL)
    return ;
    Postorder(root->left) ;
    Postorder(root->right) ;
    cout<<root->data ;

}

int main() {
    node*root = new node(1);
    root->left = new node(2) ;
    root->right = new node(3) ;
    root->left->left = new node(4) ;
    root->left->right= new node(5);
    root->right->right = new node(6) ;
    root->right->right->left = new node(7) ;


    cout<<"The numbers of nodes: "<<CountNode(root) ;
    cout<<"The Height of Tree: "<<Height(root) ;
    cout<<"The number of Leaf Nodes :"<<CountLeaf(root) ;

     cout<<"The numbers of node with 1 child: "<<Count1Child(root) ;
    cout<<"The numbers of node with 2 child : "<<Count2Child(root) ;
    cout<<"The Sum of the node : "<<SumNode(root) ;
    cout<<"Traversing Using Inorder: "<<Inorder(root);
    cout<<"Traversing Using Preorder:" <<Preorder(root) ;
    cout<<"Traversing Using PostOrder: "<<Postorder(root) ;
    

    return 0;

}