//
// Created by Akshansh Gusain on 17/03/21.
//
/* 3 Cases:
 * 1. Node to be deleted is leaf: Simply remove from the tree.
 * 2. Node to be deleted has only one child: Copy the child to the node and delete the child.
 * 3. Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder
 * successor to the node and delete the inorder successor. Note that inorder predecessor can also be used. */
#include<stdc++.h>

using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item) {
    struct node *temp
            = (struct node *) malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

// A utility function to do
// inorder traversal of BST
void inorder(struct node *root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key;
        inorder(root->right);
    }
}

struct node *insert(struct node *node, int key) {
    /* If the tree is empty, return a new node */
    if (node == nullptr)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != nullptr)
        current = current->left;

    return current;
}



int main() {
/* Let us create following BST
            50
        /     \
        30     70
        / \ / \
    20 40 60 80 */
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of the given tree \n";
    inorder(root);

    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    return 0;
}
