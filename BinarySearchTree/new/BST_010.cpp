//
// Created by Akshansh Gusain on 08/03/24.
//

#include "BST_000.cpp"


void arrayToBST(TreeNode *root, vector<int> sortedInOrder, int &index) {
    if (root == nullptr) {
        return;
    }

    arrayToBST(root->left, sortedInOrder, index);
    root->val = sortedInOrder[index];
    index++;
    arrayToBST(root->right, sortedInOrder, index);
}


void binaryTreeToBST(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    vector<int> sortedInorder;
    // 1 .Store in Array
    buildInOrderArray(root, sortedInorder);
    // 2. Sort the array
    sort(sortedInorder.begin(), sortedInorder.end());
    // 3. Create BST from the sorted array
    int i = 0;
    arrayToBST(root, sortedInorder, i);
}

int main() {
    auto *root = new TreeNode(10);
    root->left = new TreeNode(30);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(20);
    root->right->right = new TreeNode(5);

    // convert Binary Tree to BST
    root = binaryTreeToBST(root);

    cout << "Following is Inorder Traversal of the converted BST:" << endl;
    printBST(root);

    return 0;
}