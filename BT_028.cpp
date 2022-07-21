//
// Created by Akshansh Gusain on 02/02/22.
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

void sumOfLongRootToLeafPath(Node *root, int currentSum, int currentLength, int &maxSum, int &maxLength) {
    if (root == nullptr) {
        if (currentLength > maxLength) {
            maxLength = currentLength;
            maxSum = currentSum;
        } else if (currentLength == maxLength) {
            maxSum = max(maxSum, currentSum);
        }
        return;
    }
    sumOfLongRootToLeafPath(root->left, currentSum + root->data, currentLength + 1, maxSum, maxLength);
    sumOfLongRootToLeafPath(root->right, currentSum + root->data, currentLength + 1, maxSum, maxLength);
}

int sumOfLongRootToLeafPathUtil(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    int maxSum = INT_MIN, maxLength = 0, currentSum = 0, currentLength = 0;

    sumOfLongRootToLeafPath(root, currentSum, currentLength, maxSum, maxLength);

    return maxSum;
}

int main() {
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    root->left->right->left = new Node(6);

    cout << "Sum = " << sumOfLongRootToLeafPathUtil(root);

    return 0;

}