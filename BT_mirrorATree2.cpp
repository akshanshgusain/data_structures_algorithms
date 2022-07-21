//
// Created by Akshansh Gusain on 10/03/21.

//Swapping method
/*In order to change the original tree in its mirror tree, then we simply swap the left and right link of each node.
 * If the node is leaf node then do nothing.*/

#include<stdc++.h>

using namespace std;

typedef struct treenode {
    int val;
    struct treenode *left;
    struct treenode *right;
} node;

node *createNode(int val) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->val = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void inorder(node *root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val;
    inorder(root->right);
}

treenode *mirrorTree(node *root) {
    // Base Case
    if (root == nullptr)
        return root;
    node *t = root->left;
    root->left = root->right;
    root->right = t;

    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);

    return root;
}

int main() {

    node *tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);

    // Print inorder traversal of the input tree
    printf("Inorder of original tree: ");
    inorder(tree);
    mirrorTree(tree);

    // Print inorder traversal of the mirror tree
    printf("\nInorder of mirror tree: ");
    inorder(tree);

    return 0;
}
