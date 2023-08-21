//
// Created by Akshansh Gusain on 27/06/23.
//
#include<stdc++.h>

using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *left, *right;

    TreeNode() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    explicit TreeNode(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int key, TreeNode *left, TreeNode *right) {
        data = key;
        this->left = left;
        this->right = right;
    }
};
