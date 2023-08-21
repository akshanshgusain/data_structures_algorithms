//
// Created by Akshansh Gusain on 09/02/22.
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

bool isIsomorphic(Node *root1, Node *root2) {
    if (root1 == nullptr and root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr or root2 == nullptr) {
        return false;
    }

    if (root1->data != root2->data) {
        return false;
    }

    // There are two possible cases for n1 and n2 to be isomorphic
    // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
    // Both of these subtrees have to be isomorphic, hence the &&
    // Case 2: The subtrees rooted at these nodes have been "Flipped"

    return (isIsomorphic(root1->left, root2->left) and isIsomorphic(root1->right, root2->right) or
                                                       (isIsomorphic(root1->left, root2->right) and
                                                        isIsomorphic(root1->right, root2->left)));
}

int main() {
    Node *node1 = new Node(1);
    node1->left = new Node(2);
    node1->right = new Node(3);
    node1->left->left = new Node(4);
    node1->left->right = new Node(5);
    node1->right->left = new Node(6);
    node1->left->right->left = new Node(7);
    node1->left->right->right = new Node(8);

    Node *node2 = new Node(1);
    node2->left = new Node(3);
    node2->right = new Node(2);
    node2->right->left = new Node(4);
    node2->right->right = new Node(5);
    node2->left->right = new Node(6);
    node2->right->right->left = new Node(8);
    node2->right->right->right = new Node(7);

    if (isIsomorphic(node1, node2))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}