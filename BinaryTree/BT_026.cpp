//
// Created by Akshansh Gusain on 29/02/24.
//
#include "BT_000.cpp"

void findAncestors(TreeNode *root, vector<int> &ancestors) {
    ancestors[root->val] = -1;
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while(!nodeQueue.empty()){
        auto front = nodeQueue.front();
        nodeQueue.pop();

        if(front->left != nullptr){
            ancestors[front->left->val] = front->val;
            nodeQueue.push(front->left);
        }
        if(front->right != nullptr){
            ancestors[front->right->val] = front->val;
            nodeQueue.push(front->right);
        }
    }
}

int KthAncestor(TreeNode *root, int numberOfNodes, int k, int node) {
    // create a vector to store the 1st Ancestor
    vector<int> ancestors(numberOfNodes + 1, 0);

    findAncestors(root, ancestors);
    int count = 0;
    while (node != -1) {
        node = ancestors[node];
        count++;
        if (count == k) {
            break;
        }
    }

    return node;
}

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int numberOfNodes = 5;
    int k = 1;
    int node = 5;

    // print kth ancestor of given node
    cout << KthAncestor(root, numberOfNodes, k, node);
    return 0;
}