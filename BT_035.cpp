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


Node *findLCA(Node *root, int n1, int n2, int &d1, int &d2, int &dist, int level) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == n1) {
        d1 = level;
        return root;
    }
    if (root->data == n2) {
        d2 = level;
        return root;
    }

    Node *leftLCA = findLCA(root->left, n1, n2, d1, d2, dist, level + 1);
    Node *rightLCA = findLCA(root->right, n1, n2, d1, d2, dist, level + 1);

    if (leftLCA != nullptr and rightLCA != nullptr) {
        dist = d1 + d2 - 2 * level;
        return root;
    }
    if (leftLCA != nullptr) {
        return leftLCA;
    } else {
        return rightLCA;
    }
}

int findLevel(Node *root, int k, int level) {
    if (root == nullptr) {
        return -1;
    }

    if (root->data == k) {
        return level;
    }

    int l = findLevel(root->left, k, level + 1);
    if (l != -1) {
        return l;
    } else {
        return findLevel(root->right, k, level + 1);
    };
}

// Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)
int findDistance(Node *root, int n1, int n2) {
    int d1 = -1, d2 = -1, dist, level = 1;
    Node *LCA = findLCA(root, n1, n2, d1, d2, dist, level);

    // if both the values are present in the binary tree
    if (d1 != -1 and d2 != -1) {
        return dist;
    }

    // If n1 is ancestor of n2, consider n1 as root
    // and find level of n2 in subtree rooted with n1
    if (d1 != -1) {
        dist = findLevel(LCA, n2, 0);
        return dist;
    }
    // If n2 is ancestor of n1, consider n2 as root
    // and find level of n1 in subtree rooted with n2
    if (d2 != -1) {
        dist = findLevel(LCA, n1, 0);
        return dist;
    }

    return -1;

}


int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);

    return 0;
}