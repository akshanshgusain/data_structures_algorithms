//
// Created by Akshansh Gusain on 11/03/21.
//
#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node *newNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// d -  distance of current line from rightmost-topmost slope.

void diagonalPrintUtil(Node *root, int d, map<int, vector<int>> &diagonalPrint) {
    if (!root)
        return;

    // Store all nodes of same
    // line together as a vector
    diagonalPrint[d].push_back(root->data);

    // Increase the vertical
    // distance if left child
    diagonalPrintUtil(root->left, d + 1, diagonalPrint);

    // Vertical distance remains
    // same for right child
    diagonalPrintUtil(root->right, d, diagonalPrint);

}

void diagonalPrint(Node *root) {

    map<int, vector<int>> diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :diagonalPrint) {
        vector<int> v = it.second;
        for (auto it:v)
            cout << it << " ";
        cout << endl;
    }
}

int main() {
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    diagonalPrint(root);
    return 0;
}
