//
// Created by Akshansh Gusain on 10/03/21.
//
#include<stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node *newNode(int data) {
    auto *node
            = (struct node *) malloc(sizeof(struct node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;

    return (node);
}

int height(struct node* node){
      if(node == nullptr){
          return 0;
      }
      int lHeight = height(node->left);
      int rHeight = height(node->right);
      return (max(lHeight, rHeight) + 1);
}

int diameter(struct node* tree){
    if(tree == nullptr){
        return 0;
    }
    int lHeight = height(tree->left);
    int rHeight = height(tree->right);

    int lDiameter = diameter(tree->left);
    int rDiameter = diameter(tree->right);

    return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
}

int main() {
    /* Constructed binary tree is
            1
            / \
        2     3
        / \
    4     5
    */
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Function Call
    cout << "Diameter of the given binary tree is " <<
         diameter(root);

    return 0;
}
