//
// Created by Akshansh Gusain on 30/01/24.
//
#include "BT_000.cpp"

int heightOfBinaryTree(TreeNode *&head) {
    if (head == nullptr) {
        return 0;
    }

    int leftHeight = heightOfBinaryTree(head->left);
    int rightHeight = heightOfBinaryTree(head->right);

    return 1 + max(leftHeight , rightHeight);
}

int main() {
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Print the result
    cout << "Height of the Binary Tree: " << heightOfBinaryTree(root) << endl;
    return 0;
}