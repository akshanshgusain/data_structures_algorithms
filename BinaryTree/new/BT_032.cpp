//
// Created by Akshansh Gusain on 04/03/24.
//
#include "BT_000.cpp"

void sumNodesLongestPathUtil(TreeNode *root, int currentPathLength,
                             int &maxPathLength, int currentSum, int &maxSum) {
    if (root == nullptr) {
        if (currentPathLength > maxPathLength){
            maxPathLength = currentPathLength;
            maxSum = currentSum;
        }else if(currentPathLength == maxPathLength){
            maxSum = max(currentSum, maxSum);
        }
        return;
    }

    sumNodesLongestPathUtil(root->left, currentPathLength + 1,
                            maxPathLength, currentSum + root->val, maxSum);
    sumNodesLongestPathUtil(root->right, currentPathLength + 1,
                            maxPathLength, currentSum + root->val, maxSum);
}

int sumNodesLongestPath(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int maxPathLength = 0;
    int maxSum = INT_MIN;
    int currentSum = 0;
    int currentLength = 0;

    sumNodesLongestPathUtil(root, currentLength, maxPathLength, currentSum, maxSum);
    return maxSum;
}

int main() {
    auto root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->left->right->left = new TreeNode(6);

    cout << "sum : " << sumNodesLongestPath(root);
    return 0;
}