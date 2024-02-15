//
// Created by Akshansh Gusain on 27/01/24.
//
#include<bits/stdc++.h>

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