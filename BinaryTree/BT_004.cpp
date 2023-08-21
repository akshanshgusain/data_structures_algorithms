//
// Created by Akshansh Gusain on 19/01/22.
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

int height(Node *root) {
    if (root == nullptr) {
        return -1;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}

int heightOptimised(Node *root, int &ans) {
    if (root == nullptr) {
        return -1;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        ans = max(ans, leftHeight + rightHeight + 1);

        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}

int diameter(Node *root) {
    // Find Out max of left-height and right-height for every node
    // max(For every node - max(left-height, right-height))
    // Max diameter is going to be one of the following:

    //  1. Diameter Passes through current node.
    //  2. Diameter DOES NOT pass thought the current Node:
    //      2.1. Diameter of Left Sub Tree.
    //      2.2. Diameter of Right Sub Tree.

    if (root == nullptr) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // call for left and right subtree
    int diameterOfLeftSubTree = diameter(root->left);
    int diameterOfRightSubTree = diameter(root->right);

    return max(
            (leftHeight + rightHeight + 1),
            max(diameterOfLeftSubTree, diameterOfRightSubTree)
            );
}

int diameterOptimised(Node *root) {  //Time: O(N)
    if (root == nullptr) {
        return 0;
    }
    int ans = INT_MIN;
    heightOptimised(root, ans);
    return ans;
}

// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.

int main() {
    /* Constructed binary tree is
            1
            / \
        2     3
        / \
    4     5
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Function Call
    cout << "Diameter of the given binary tree is " <<
         diameterOptimised(root);

    return 0;
}
