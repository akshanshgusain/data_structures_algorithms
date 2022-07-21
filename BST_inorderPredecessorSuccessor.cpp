//
// Created by Akshansh Gusain on 18/03/21.
//
#include<stdc++.h>

using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};

Node *newNode(int item) {
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

Node *insert(Node *node, int key) {
    if (node == nullptr) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key) {
    // Base case
    if (root == nullptr) return;

    // If key is present at root
    if (root->key == key) {
        // the maximum value in left subtree is predecessor
        if (root->left != nullptr) {
            Node *tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }

        // the minimum value in right subtree is successor
        if (root->right != nullptr) {
            Node *tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            suc = tmp;
        }
        return;
    }

    // If key is smaller than root's key, go to left subtree
    if (root->key > key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    } else // go to right subtree
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

int main() {
    int key = 65;    //Key to be searched in BST

    /* Let us create following BST
               50
            /     \
           30      70
          /  \    /  \
        20   40  60   80 */
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);


    Node *pre = nullptr, *suc = nullptr;

    findPreSuc(root, pre, suc, key);
    if (pre != nullptr)
        cout << "Predecessor is " << pre->key << endl;
    else
        cout << "No Predecessor";

    if (suc != nullptr)
        cout << "Successor is " << suc->key;
    else
        cout << "No Successor";
    return 0;
}
