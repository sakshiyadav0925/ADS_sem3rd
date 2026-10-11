#include<bits/stdc++.h>
using namespace std ;


struct node {
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = right = NULL;
    }
};


node * insertNode(node * root, int val)
{
   if(root ==NULL)
   return new node(val);
   if(val>root->data)
   root->right = insertNode(root->right,val);

   else if(val<root->data )
   root->left = insertNode(root->left,val) ;

   return root ;

}
void inorder(node * root)
{
  if (root==NULL)
  return ;
  inorder(root->left);
  cout<<root->data <<endl;;
  inorder(root->right) ;

}
node *findMin(node* root)
{while(root->left!=NULL)
  root=root->left;
  return root;
}

node * deleteNode(node * root, int key)
{
    if(root==NULL)
    return root ;
    if(key<root->data)
    root->left=deleteNode(root->left,key);
    else if(key>root->data)
    root->right=deleteNode(root->right,key);

    else
    {
        if(root->left ==NULL)
        {
            node * temp=root->right;
            delete(root) ;
            return temp;

        }
        if(root->right==NULL)
        {
         
            node * temp=root->left;
            delete(root) ;
            return temp;

        }
    }
    node * successor=findMin(root->right){
    root->data=successor->data;
    root->right delete(root->right,successor->data);
    return root;
    }

}

int main() {
node * root = NULL;
    root= insertNode(root,10);
  
    insertNode(root,5);
    insertNode(root,2);
    insertNode(root,1);
    insertNode(root,8);
    insertNode(root,15);
    insertNode(root,14);
    insertNode(root,25);
    insertNode(root,20);
    insertNode(root,18);
    insertNode(root,30);
    
    

    cout<<"Inorder Traversal: " <<endl;
    inorder(root);
    





}