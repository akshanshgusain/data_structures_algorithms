//
// Created by Akshansh Gusain on 25/01/22.
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


void printLeaves(Node *root) {
    if (root == nullptr) {
        return;
    }

    printLeaves(root->left);

    if ((root->left == nullptr) and (root->right == nullptr)) {
        cout << root->data << " ";
    }

    printLeaves(root->right);
}


void printBoundaryLeft(Node *root) {
    if (root == nullptr) {
        return;
    }
    if (root->left != nullptr) {
        // to ensure top down order, print the node
        // before calling itself for left subtree

        cout << root->data << " ";
        printBoundaryLeft(root->left);
    } else if (root->right != nullptr) {
        cout << root->data << " ";
        printBoundaryLeft(root->right);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}


void printBoundaryRight(Node *root) {
    if (root == nullptr) {
        return;
    }
    if (root->right != nullptr) {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        printBoundaryRight(root->right);
        cout << root->data << " ";
    } else if (root->left != nullptr) {
        printBoundaryRight(root->left);
        cout << root->data << " ";
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

void printBoundary(Node *root) {
    if (root != nullptr) {
        cout << root->data << " ";
    }

    printBoundaryLeft(root->left);
    printLeaves(root);
    printBoundaryRight(root->right);
}

int main() {
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    printBoundary(root); // 20 8 4 10 14 25 22
    return 0;
}
