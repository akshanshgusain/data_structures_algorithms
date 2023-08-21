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

void postOrderTraversal(Node *root) {
    if (root == nullptr) {
        return;
    } else {

        if (root->left != nullptr) {
            postOrderTraversal(root->left);
        }
        if (root->right != nullptr) {
            postOrderTraversal(root->right);
        }
        cout << root->data << " ";
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

    postOrderTraversal(root); // 4 2 7 8 5 6 3 1
    return 0;
}