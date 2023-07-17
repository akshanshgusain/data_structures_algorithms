//
// Created by Akshansh Gusain on 21/01/22.
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

void leftView(Node *root, int currentLevel, int &maxLevel){
    if(root == nullptr){
        return;
    }

    if(currentLevel > maxLevel){
        cout<<root->data<<" ";
        maxLevel = currentLevel;
    }

    if(root->left != nullptr){
        leftView(root->left, currentLevel + 1, maxLevel);
    }
    if(root->right != nullptr){
        leftView(root->right, currentLevel + 1, maxLevel);
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right->left = new Node(14);

    int maxLevel = INT_MIN;
    leftView(root, 1, maxLevel);
    return 0;
}
