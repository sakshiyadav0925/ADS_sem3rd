#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

struct node {
    int data;
    node*left;
    node*right;
    node(int val)
    {
        data= val;
        left = right = NULL ;

    }
};


void  deletedeep(node* root,node* dnode)
{
    queue<node*>q ;

     q.push(root);
     node* temp;
     while(! q.front()){
        temp=q.front();
        q.pop();
        if(temp==dnode)
        { temp= NULL ;
        delete(dnode);
         return ;
        }
        if(temp->right!=NULL)
        { if(temp->right==dnode)
        {
            temp->right= NULL;
            delete(dnode);
            return ;

        }
    q.push(temp->right);
    }
    if(temp->left!=NULL)
    {
        if(temp->left==dnode)
        { temp->left=NULL;
        delete(dnode);
        return ;
    }
    q.push(temp->left);

    }
}

}
node* deletion(node* root,int key)
{
    if(root==NULL)
    return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data==key)
        {
            return NULL;
        }
        else 
        return root ;

    }
    queue<node*>q;
    q.push(root);
    int x;
    node* temp ;
 node * keynode=NULL;
 while(!q.empty() )
 { temp=q.front();
   q.pop() ;
   if(temp->data==key)
     keynode= temp ;
   if(temp->left!=NULL)
     q.push(temp->left) ;
    if(temp->right !=NULL)
    q.push(temp->right) ;

}   
if(keynode !=NULL)
 {
    x=temp->data;
    keynode->data=x;
    deletedeep(root,temp);
    return root;
 }

}



 int main() {
    node*root = new node(10);
    root->left = new node(9) ;
    root->right = new node(11) ;
    root->left->left = new node(8) ;
    root->left->right= new node(7);
    root->right->right = new node(5) ;
    root->right->left = new node(6) ;


    


    return 0;
}