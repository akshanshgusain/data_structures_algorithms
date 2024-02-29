//
// Created by Akshansh Gusain on 27/02/24.
//
#include "BT_000.cpp"

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    //base case
    if (root == nullptr or root == p or root == q) {
        return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    //result
    if (left == nullptr) {
        return right;
    } else if (right == nullptr) {
        return left;
    } else { //both left and right are not null, we found our result
        return root;
    }
}

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode *p = root->left->left; //4
    TreeNode *q = root->right->right; //7

    cout << "LCA: " << lowestCommonAncestor(root, p, q)->val;
    return 0;
}