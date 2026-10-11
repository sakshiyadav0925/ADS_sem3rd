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

node* Insertion_CBT(node* root, int val, queue<node*>& q) {
    node* newNode = new node(val);
    
    if (root == NULL) {
        root = newNode;
        q.push(root);
        return root;
    }
    node* curr = q.front();

    if (curr->left == NULL) {
        curr->left = newNode;
    } else if (curr->right == NULL) {
        curr->right = newNode;
        q.pop(); 
    }
    q.push(newNode);
    return root;
}
vector<vector<int>> levelOrder(node* root) {
    vector<vector<int>> result;
    if (root == NULL)
     return result;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;

        for (int i = 0; i < levelSize; i++) {
            node* curr = q.front();
            q.pop();
            level.push_back(curr->data);

            if (curr->left != NULL) 
            q.push(curr->left);
            if (curr->right != NULL)
             q.push(curr->right);
        }
        result.push_back(level);
    }
    return result;
}

int main() {
    node* root = NULL;
    queue<node*> q;

    int values[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = Insertion_CBT(root, values[i], q);
    }

    vector<vector<int>> levels = levelOrder(root);
    
    cout << "Level-Order Traversal of Complete Binary Tree:" << endl;
    for ( auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}