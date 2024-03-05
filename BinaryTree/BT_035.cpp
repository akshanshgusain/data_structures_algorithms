//
// Created by Akshansh Gusain on 05/03/24.
//
#include "BT_000.cpp"

unordered_map<TreeNode*, int> memo;

int getSumGrandchildren(TreeNode *root) {
    int sum = 0;

    if (root == nullptr) {
        return sum;
    }

    if (root->left != nullptr) {
        sum += getSumGrandchildren(root->left->left) + getSumGrandchildren(root->left->right);
    }
    if (root->right != nullptr) {
        sum += getSumGrandchildren(root->right->left) + getSumGrandchildren(root->right->right);
    }

    return sum;
}


int getMaxSum(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    if(memo.find(root) != memo.end()){
        return memo[root];
    }

    int includingCurrentRoot = root->val + getSumGrandchildren(root);

    int excludingCurrentRoot = getMaxSum(root->left) + getMaxSum(root->right);

    return memo[root] = max(includingCurrentRoot, excludingCurrentRoot);
}

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->left->left = new TreeNode(1);

    cout << getMaxSum(root);

    return 0;
}