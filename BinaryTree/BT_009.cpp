//
// Created by Akshansh Gusain on 20/01/22.
//

#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;

    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }

    Node(int key, Node *left, Node *right) {
        data = key;
        this->left = left;
        this->right = right;
    }
};

void inorder(Node *node) {
    if (node == nullptr) {
        return;
    }

    if (node->left != nullptr) {
        inorder(node->left);
    }
    cout << node->data << " ";
    if (node->right != nullptr) {
        inorder(node->right);
    }
}

void mirrorTree(Node *root) {
    if (root == nullptr) {
        return;
    }

    // Simply Swap the left and right subtrees
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    if (root->left) {
        mirrorTree(root->left);
    }

    if (root->right) {
        mirrorTree(root->right);
    }
}

int main() {
    Node *tree = new Node(5);
    tree->left = new Node(3);
    tree->right = new Node(6);
    tree->left->left = new Node(2);
    tree->left->right = new Node(4);

    // Print inorder traversal of the input tree
    printf("Inorder of original tree: ");
    inorder(tree);
    mirrorTree(tree);

    // Print inorder traversal of the mirror tree
    printf("\nInorder of mirror tree: ");
    inorder(tree);
    return 0;
}
