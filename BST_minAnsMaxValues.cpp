//
// Created by Akshansh Gusain on 18/03/21.
//
#include<stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data) {
    struct node *node = (struct node *)
            malloc(sizeof(struct node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;

    return (node);
}

struct node *insert(struct node *node, int data) {
/* 1. If the tree is empty, return a new,
    single node */
    if (node == NULL)
        return (newNode(data));
    else {
        /* 2. Otherwise, recur down the tree */
        if (data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        /* return the (unchanged) node pointer */
        return node;
    }
}
int minValue(node* root){
    node* current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    return current->data;
}

int maxValue(node* root){
    node* current = root;
    while(current->right != nullptr){
        current = current->right;
    }
    return current->data;
}

int main() {
    struct node* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);

    cout << "\n Minimum value in BST is " << minValue(root);
    cout << "\n Maximum value in BST is " << maxValue(root);
    return 0;
}
