//
// Created by Akshansh Gusain on 26/02/24.
//
#include "BT_000.cpp"

int toSumTree(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int sumOfLeftChild = toSumTree(root->left);
    int sumOfRightChild = toSumTree(root->right);

    int prevNodeVal = root->val;
    root->val = sumOfLeftChild + sumOfRightChild;

    return prevNodeVal + sumOfLeftChild + sumOfRightChild;
}

int main() {
    auto *root = new TreeNode(10);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(-4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(5);

    toSumTree(root);
    cout << "Inorder Traversal of the resultant tree is: \n";
    printInorder(root); //0 4 0 20 0 12 0
    return 0;
}