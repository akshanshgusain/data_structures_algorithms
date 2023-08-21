//
// Created by Akshansh Gusain on 26/01/22.
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

//https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
// Time: O(N)

int toSumTree(Node *root){
    if(root == nullptr){
        return 0;
    }
    int previousValue = root->data;
    root->data = toSumTree(root->left) + toSumTree(root->right);
    return root->data + previousValue;
}

void printInOrder(Node *root){
    if(root == nullptr){
        return;
    }

    if(root->left != nullptr){
        printInOrder(root->left);
    }
    cout<<root->data<<" ";

    if(root->right != nullptr){
        printInOrder(root->right);
    }
}


int main() {
    Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    toSumTree(root);
    cout<<"Inorder Traversal of the resultant tree is: \n";
    printInOrder(root); //0 4 0 20 0 12 0

    return 0;
}