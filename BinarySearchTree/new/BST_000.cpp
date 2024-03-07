//
// Created by Akshansh Gusain on 06/03/24.
//
#include<stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left, *right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    explicit TreeNode(int key) {
        val = key;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int key, TreeNode *left, TreeNode *right) {
        val = key;
        this->left = left;
        this->right = right;
    }
};

TreeNode *insertInBST(TreeNode *root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }

    if (key < root->val) {
        root->left = insertInBST(root->left, key);
    } else if (key > root->val) {
        root->right = insertInBST(root->right, key);
    }

    return root;
}

void printBST(TreeNode * root){
    if(root == nullptr){
        return;
    }
    cout<<root->val<<" ";
    printBST(root->left);
    printBST(root->right);
}