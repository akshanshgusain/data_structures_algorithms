//
// Created by Akshansh Gusain on 04/02/22.
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

int getSumGrandChildren(Node *root, map<Node *, int> &map) {
    int sum = 0;

    if(root == nullptr){
        return sum;
    }

    if(root->left != nullptr){
        sum += getSumGrandChildren(root->left->left, map) + getSumGrandChildren(root->left->right, map);
    }

    if(root->right != nullptr){
        sum += getSumGrandChildren(root->right->left, map) + getSumGrandChildren(root->right->right, map);
    }

    return sum;
}

int getMaxSum(Node *root, map<Node *, int> &map) {
    if (root == nullptr) {
        return 0;
    }
    if(map.find(root) != map.end()){
        return map[root];
    }
    // Take the current node:
    int includingCurrentNode = root->data + getSumGrandChildren(root, map);

    // Not Take the current node:
    int excludingCurrentNode = getMaxSum(root->left, map) + getMaxSum(root->right, map);

    return map[root] = max(includingCurrentNode, excludingCurrentNode);
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left = new Node(1);

    map<Node *, int> map; // Memoization
    cout << getMaxSum(root, map) << endl;
}