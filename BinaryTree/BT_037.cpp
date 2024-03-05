//
// Created by Akshansh Gusain on 05/03/24.
//
#include "BT_000.cpp"

unordered_map<long long, int> lookup;
int cnt = 0;

void countPathSum(TreeNode *root, int target, long long sum) {
    if (root == nullptr){
        return;
    }

    sum += root->val;        //Path sum from root
    if (sum == target){
        cnt++;
    }
    //checking whether any target sum path present in the path from root to the current node
    if (lookup.find(sum - target) !=lookup.end()){
        cnt += lookup[sum - target];
    }

    lookup[sum]++;
    countPathSum(root->left, target, sum);
    countPathSum(root->right, target, sum);

    //After visiting the left and right subtree, we have to reduce this path sum count from map since we are leaving this path
    lookup[sum]--;
}

int pathSum(TreeNode *root, int targetSum) {
    countPathSum(root, targetSum, 0);
    return cnt;
}

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->left->right->left = new TreeNode(1);
    root->right = new TreeNode(-1);
    root->right->left = new TreeNode(4);
    root->right->left->left = new TreeNode(1);
    root->right->left->right = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(2);

    int k = 5;
    cout << pathSum(root, k);

    return 0;
}