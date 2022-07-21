//
// Created by Akshansh Gusain on 10/03/21.
//
#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Recursive function to perform postorder traversal on the tree
void postorder(Node *root) {
    // if the current node is empty
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    postorder(root->left);

    // Traverse the right subtree
    postorder(root->right);

    // Display the data part of the root (or current node)
    cout << root->data << " ";
}

int main() {

    return 0;
}
