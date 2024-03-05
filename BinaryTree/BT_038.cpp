//
// Created by Akshansh Gusain on 05/03/24.
//
#include "BT_000.cpp"

int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> q;

    q.push(root);
    TreeNode *a = nullptr;
    while (!q.empty()) {
        a = q.front();
        q.pop();

        // crucial to add right chlid first
        if (a->right != nullptr) {
            q.push(a->right);
        }
        if (a->left != nullptr) {
            q.push(a->left);
        }
    }
    return a->val;
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

    cout << findBottomLeftValue(root);

    return 0;
}