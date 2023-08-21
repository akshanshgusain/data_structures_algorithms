//
// Created by Akshansh Gusain on 01/02/22.
//
#include<stdc++.h>

using namespace std;

struct Node {
    char data;
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

// Time: O(N^2)

bool isLeaf(Node *node) {
    if (node == nullptr) {
        return false;
    }
    if (node->left == nullptr and node->right == nullptr) {
        return true;
    }
    return false;
}


int sum(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    return sum(root->left) + root->data + sum(root->right);
}

bool isSumTree(Node *root) {
    if (root == nullptr or isLeaf(root)) {
        return true;
    }
    int leftSubTree, rightSubTree;

    // get sum of nodes in the left and right subtrees
    leftSubTree = sum(root->left);
    rightSubTree = sum(root->right);

    // check the property for both Left and Right SubTrees
    if ((root->data == leftSubTree + rightSubTree) and isSumTree(root->left) and isSumTree(root->right)) {
        return true;
    } else {
        return false;
    }
}


/// uses the following rules to get the sum directly.
//1) If the node is a leaf node then the sum of the subtree rooted with this node is equal to the value of this node.
//2) If the node is not a leaf node then the sum of the subtree rooted with this node is twice the value of this node (Assuming that the tree rooted with this node is SumTree).
// OPTIMISED TIME : O(N)



bool isSumTreeOp(Node *root) {
    int leftSubTreeSum;
    int rightSubTreeSum;

    if (root == nullptr or isLeaf(root)) {
        return true;
    }

    if (isSumTreeOp(root->left) and isSumTreeOp(root->right)) {

        // Get the sum of nodes in left subtree
        if (root->left == nullptr) {
            leftSubTreeSum = 0;
        } else if (isLeaf(root->left)) {
            leftSubTreeSum = root->left->data;
        } else {
            leftSubTreeSum = 2 * (root->left->data);
        }

        // Get the sum of nodes in left subtree
        if (root->right == nullptr) {
            rightSubTreeSum = 0;
        } else if (isLeaf(root->right)) {
            rightSubTreeSum = root->right->data;
        } else {
            rightSubTreeSum = 2 * (root->right->data);
        }


        /* If root's data is equal to sum of nodes in left
           and right subtrees then return 1 else return 0*/
        return (root->data == leftSubTreeSum + rightSubTreeSum);
    }

    return false;
}

int main() {
    Node *root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    if (isSumTreeOp(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";

    return 0;
}