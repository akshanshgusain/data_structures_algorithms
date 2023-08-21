//
// Created by Akshansh Gusain on 08/02/22.
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


//Node *findLCA(Node *root, int n1, int n2, int &d1, int &d2, int &dist, int level) {
//    if (root == nullptr) {
//        return nullptr;
//    }
//
//    if (root->data == n1) {
//        d1 = level;
//        return root;
//    }
//    if (root->data == n2) {
//        d2 = level;
//        return root;
//    }
//
//    Node *leftLCA = findLCA(root->left, n1, n2, d1, d2, dist, level + 1);
//    Node *rightLCA = findLCA(root->right, n1, n2, d1, d2, dist, level + 1);
//
//    if (leftLCA != nullptr and rightLCA != nullptr) {
//        dist = d1 + d2 - 2 * level;
//        return root;
//    }
//    if (leftLCA != nullptr) {
//        return leftLCA;
//    } else {
//        return rightLCA;
//    }
//}

Node *temp = NULL;

// recursive function to calculate Kth ancestor
Node *kthAncestorDFS(Node *root, int node, int &k) {
    // Base case
    if (!root){
        return nullptr;
    }


    if (root->data == node ||
        (temp = kthAncestorDFS(root->left, node, k)) ||
        (temp = kthAncestorDFS(root->right, node, k))) {
        if (k > 0)
            k--;

        else if (k == 0) {
            // print the kth ancestor
            cout << "Kth ancestor is: " << root->data;

            // return NULL to stop further backtracking
            return nullptr;
        }

        // return current node to previous call
        return root;
    }
    return nullptr;
}


int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2;
    int node = 5;

    // print kth ancestor of given node
    Node *parent = kthAncestorDFS(root, node, k);

    // check if parent is not NULL, it means
    // there is no Kth ancestor of the node
    if (parent)
        cout << "-1";

    return 0;
}