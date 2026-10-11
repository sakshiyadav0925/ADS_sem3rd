#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = right = NULL;
    }
};

node* deletion_CBT(node* root, int target)
{
    if(root==NULL)
    return NULL ; 
    if(root->left ==NULL && root->right==NULL)
{
        if(root->data= target)
        {
            delete(root);
            return NULL;

        }
        else
         return root;
     
    node* deleteNode;
    node* lastParent ;
    node* lastNode ;
    queue<node* >q;
    q.push(root) ;
    while(! q.empty() )
    { node* curr = q.front() ;
    q.pop() ;
    
    if(curr->data ==target)
    deleteNode= curr;
    if(curr->left !=NULL)
     {
        lastParent = curr;
        lastNode = curr->left ;
        q.push(curr->left) ;

     }
    if(curr->right !=NULL)
     {
        lastParent =curr ;
        lastNode = curr->right;
        q.push(curr->right) ;
     }    
    
    if(deleteNode != NULL)
      deleteNode->data =lastNode->data;
      if(lastParent->right == lastNode) 
        lastParent->right = NULL ;
    else
      lastParent->left= NULL;
      delete lastNode;
      return root ;

    }
    }
}
vector<vector<int>> levelOrder(node* root) {
    vector<vector<int>> result;
    if (root == NULL) return result;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        for (int i = 0; i < levelSize; i++) {
            node* curr = q.front();
            q.pop();
            level.push_back(curr->data);

            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
        }
        result.push_back(level);
    }
    return result;
}

int main() {


    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7) ;
    root->left->left->left = new node(8) ;
    root->left->left->right = new node(9) ;


    cout<<"Before Deletion : "<<endl;
    vector<vector<int >> Del = levelOrder(root);
    for( auto level : Del)
    {
        for(int x: level)
        cout<<x<< "  ";

    }
    root = deletion_CBT(root, 5);
    cout<<"After Deletion: "<<endl;

    vector<vector<int >> res = levelOrder(root);
    for(auto level : res)
    {
        for(int x : level)
        cout<< x << "  ";

    }

    return 0;


}