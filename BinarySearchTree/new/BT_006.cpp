//
// Created by Akshansh Gusain on 07/03/24.
//
#include "BST_000.cpp"

TreeNode *findLCA(TreeNode *root, int n1, int n2) {
    // base cases
    if (root == nullptr) {
        return new TreeNode(-1);
    }

    if (root->val > n1 and root->val > n2) {
        return findLCA(root->left, n1, n2);
    }
    if (root->val < n1 and root->val < n2) {
        return findLCA(root->right, n1, n2);
    }
    return root;
}

int main() {
    TreeNode *root = nullptr;
    root = insertInBST(root, 20);
    insertInBST(root, 8);
    insertInBST(root, 22);
    insertInBST(root, 4);
    insertInBST(root, 12);
    insertInBST(root, 10);
    insertInBST(root, 14);

    printBST(root);cout<<endl;

    int n1 = 4, n2 = 14;
    auto LCA = findLCA(root, n1, n2);
    cout<<"LCA of "<<n1<<" and "<<n2<<" is :"<<LCA->val<<endl;

    return 0;
}