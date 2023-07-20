//
// Created by Akshansh Gusain on 01/02/22.
//
#include<stdc++.h>

using namespace std;

struct Node {
    char data;
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

bool check_(Node *root, int level, int &leafLevel) {
    if (root == nullptr) {
        return true;
    }

    // Check if a leaf node is encountered
    if (root->left == nullptr and root->right == nullptr) {

        if (leafLevel == 0) {
            leafLevel = level;
            return true;
        }
        return leafLevel == level;
    }

    return check_(root->left, level + 1, leafLevel) and check_(root->right, level + 1, leafLevel);
}

bool check(Node *root) {
    int level = 0, leafLevel = 0;
    return check_(root, level, leafLevel);
}

int main() {
    Node *root = new Node(12);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->left->left->left = new Node(1);
    root->left->right->left = new Node(1);
    if (check(root))
        cout << "Leaves are at same level\n";
    else
        cout << "Leaves are not at same level\n";
    return 0;

}