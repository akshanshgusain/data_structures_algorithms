//
// Created by Akshansh Gusain on 08/03/24.
//
#include "BST_000.cpp"

// 2 Methods
// 1. Sort the give pre-order, it will give us the in-order(since the in-order of a BST is a sorted array)
// with the pre-order and in-order construct a tree. O(N^2)
// 2. Sort the array, use divide and conquer to build the BST. O(NlogN)
// 3.

TreeNode *buildTreeHelper(vector<int> &nodes, int &i, int bound) {
    if (i == nodes.size() or nodes[i] > bound) {
        return nullptr;
    }
    auto root = new TreeNode(nodes[i]);
    i++;
    root->left = buildTreeHelper(nodes, i, root->val);
    root->right = buildTreeHelper(nodes, i, bound);
    return root;
}

TreeNode *buildTree(vector<int> &nodes) {
    int i = 0;
    return buildTreeHelper(nodes, i, INT_MAX);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    auto root = buildTree(preorder);
    printBST(root);

    return 0;
}