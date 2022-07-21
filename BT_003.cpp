//
// Created by Akshansh Gusain on 19/01/22.
//

// Time: O(N)
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

int maxDFS(Node *root) {
    if (root == nullptr) {
        return -1;
    } else {
        int lHeight = maxDFS(root->left);
        int rHeight = maxDFS(root->right);
        if (lHeight > rHeight) {
            return (lHeight + 1);
        } else {
            return (rHeight + 1);
        }
    }
}

int main() {
//    Node *root = newNode(1);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Maximum Height of the give tree: " << endl;
    cout<<maxDFS(root);
    return 0;
}