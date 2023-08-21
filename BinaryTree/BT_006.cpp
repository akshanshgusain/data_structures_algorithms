//
// Created by Akshansh Gusain on 20/01/22.
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

void preOrderTraversal(Node *root) {
    if (root == nullptr) {
        return;
    } else {
        cout << root->data << " ";
        if (root->left != nullptr) {
            preOrderTraversal(root->left);
        }
        if (root->right != nullptr) {
            preOrderTraversal(root->right);
        }
    }

}

int main() {
    /* Construct the following tree
           1
         /   \
        /     \
       2       3
      /      /   \
     /      /     \
    4      5       6
          / \
         /   \
        7     8
*/

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    preOrderTraversal(root); // 1 2 4 3 5 7 8 6
    return 0;
}
