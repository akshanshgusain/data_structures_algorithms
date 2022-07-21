//
// Created by Akshansh Gusain on 16/03/21.
//
#include<stdc++.h>
using namespace std;
int maxSum = 0;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return (node);
}

int findLargestSum(Node* root){
    if(!root){
        return 0;
    }

    int l = findLargestSum(root->left);
    int r = findLargestSum(root->right);
     maxSum = max(maxSum, l+r+root->data);
     return l+r+root->data;
}
int main(){

    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */

    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);

    cout << findLargestSum(root);

    return 0;
}
