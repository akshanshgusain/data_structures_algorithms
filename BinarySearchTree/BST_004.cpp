//
// Created by Akshansh Gusain on 07/03/24.
//
#include "BST_000.cpp"

TreeNode *findMin(TreeNode *root) {
    TreeNode *current = root;
    while (current != nullptr and current->left != nullptr) {
        current = current->left;
    }
    return current;
}

TreeNode *findMax(TreeNode *root) {
    TreeNode *current = root;
    while (current != nullptr and current->right != nullptr) {
        current = current->right;
    }
    return current;
}

int main() {
    /* Let us create following BST
            50
         /      \
        30      70
     /    \    /   \
    20    40  60    80 */

    TreeNode *root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);

    cout << findMin(root)->val << endl;
    cout << findMax(root)->val << endl;
    return 0;
}