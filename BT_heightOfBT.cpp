//
// Created by Akshansh Gusain on 10/03/21.
//
#include<stdc++.h>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int data) {
    node *Node = new node();
    Node->data = data;
    Node->left = nullptr;
    Node->right = nullptr;

    return (Node);
}

int maxDepth(node *node){
    if(node == nullptr){
        return -1;
    }else{
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        if(lDepth > rDepth){
            return (lDepth + 1);
        }else{
            return (rDepth + 1);
        }
    }
}

int main() {
    node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Height of tree is " << maxDepth(root);
    return 0;
}

