//
// Created by Akshansh Gusain on 18/03/21.
//
#include<stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node *newNode(int data) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

struct node* lca(struct node* root, int n1, int n2){
    if(root==nullptr)
        return nullptr;

    if(root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);

    if(root->data < n1 && root->data <n2)
        return lca(root->right, n1, n2);

    return root;
}


int main() {
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    return 0;
}
