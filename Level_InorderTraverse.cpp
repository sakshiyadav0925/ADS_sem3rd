#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;
    if (root == NULL) return result;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    vector<vector<int>> levels = levelOrder(root);
    for (auto &level : levels) {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}