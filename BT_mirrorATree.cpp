//
// Created by Akshansh Gusain on 10/03/21.

//Recursive Method
/*Write a recursive function that will take two nodes as the argument, one of the original tree and the other of
 * the newly created tree. Now, for every passed node of the original tree, create a corresponding node in the mirror
 * tree and then recursively call the same method for the child nodes but passing the left child of the original tree
 * node with the right child of the mirror tree node and the right child of the original tree node with the left child
 * of the mirror tree node.*/

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
    cout<<root->val;
    inorder(root->right);
}

void mirrorify(node* root, node** mirror){
    if(root == nullptr){
        mirror = nullptr;
        return;
    }

    *mirror = createNode(root->val);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
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
    node *mirror = NULL;
    mirrorify(tree, &mirror);

    // Print inorder traversal of the mirror tree
    printf("\nInorder of mirror tree: ");
    inorder(mirror);

    return 0;
}
