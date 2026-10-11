#include<bits/stdc++.h>
using namespace std ;

struct node{
    int data;
    node * left, * right;
    node (int val)
    { data  = val;
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
node *search(node *root, int val)
{  if(root==NULL)
    return root ;
    if(val == root->data)
    return root;
    if(val<root->data)
    return search(root->left,val);
    
    return search(root->right,val) ;

}

int main()
{
    node * root = NULL;
    root= insertNode(root,10);
    insertNode(root,11);
    insertNode(root,5);
    insertNode(root,7);
    insertNode(root,4);
    insertNode(root,2);
    insertNode(root,25);
    insertNode(root,45);
    insertNode(root,22);
    insertNode(root,40);
    

    cout<<"Inorder Traversal: " <<endl;
    inorder(root);

   node *result =  search(root,25);
    if(result !=NULL)
    cout<<"Found : " << result->data <<endl;
    else
    cout<<"Not Found " <<endl;
    


    return 0;

}


