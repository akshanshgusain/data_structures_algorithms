//
// Created by Akshansh Gusain on 13/03/21.
//
//Simple approach: Get the sum of nodes in the left subtree and right subtree.
// Check if the sum calculated is equal to the root's data. Also, recursively
// check if the left and right subtrees are SumTrees.

//Another spproach : sapce O(height), time O(n)
#include<stdc++.h>

using namespace std;

int f = 1;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return (node);
}

int solve(Node *root) {
    if (!root) {
        return 0;
    }
    if (!root->left && !root->right) {
        return root->data;
    }
    if (f == 0) {
        return 0;
    }
    int a = solve(root->left);
    int b = solve(root->right);
    if (a + b != root->data) {
        f = 0;
    }
    return a + b + root->data;
}

bool isSumTree(Node *root) {
    f = 1;
    solve(root);
    return f;
}

int main() {
    struct Node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    if (isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";

    return 0;
}
