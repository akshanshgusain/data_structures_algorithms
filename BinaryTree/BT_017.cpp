//
// Created by Akshansh Gusain on 21/02/24.
//
#include "BT_000.cpp"

int dfs(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = dfs(root->left);
    if (leftHeight == -1) {
        //not balanced
        return -1;
    }

    int rightHeight = dfs(root->right);
    if (rightHeight == -1) {
        //not balanced
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode *root) {
    return dfs(root) != -1;
}

int main() {
    auto root = new TreeNode(4);
    root->left = new TreeNode(7);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(11);
    root->left->left->left = new TreeNode(0);

    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(0);
    root->right->left->left = new TreeNode(3);
    root->right->left->left->left = new TreeNode(5);

    cout << isBalanced(root);

    return 0;
}