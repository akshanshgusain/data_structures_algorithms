//
// Created by Akshansh Gusain on 03/02/22.
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

int findLargestSubtreeSum(Node *root, int sum){
    if(root == nullptr){
        return 0;
    }

    int leftSubTreeSum = findLargestSubtreeSum(root->left,sum);
    int rightSubTreeSum = findLargestSubtreeSum(root->right, sum);

    return max(leftSubTreeSum + rightSubTreeSum + root->data, sum);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    int sum = INT_MIN;
    cout << findLargestSubtreeSum(root, sum);
    return 0;
}