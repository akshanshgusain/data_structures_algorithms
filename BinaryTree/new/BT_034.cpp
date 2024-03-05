//
// Created by Akshansh Gusain on 05/03/24.
//
#include "BT_000.cpp"

int findLargestSubtreeSum(TreeNode *root, int sum){
    if(root == nullptr){
        return 0;
    }

    int leftSubTreeSum = findLargestSubtreeSum(root->left,sum);
    int rightSubTreeSum = findLargestSubtreeSum(root->right, sum);

    return max(leftSubTreeSum + rightSubTreeSum + root->val, sum);
}

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(2);

    int sum = INT_MIN;
    cout << findLargestSubtreeSum(root, sum);
    return 0;
}