//
// Created by Akshansh Gusain on 22/01/22.
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


// // Time: O(N^2)

int heightOfBTree(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    int heightLeftSubTree = heightOfBTree(root->left);
    int heightRightSubTree = heightOfBTree(root->right);

    return 1 + max(heightLeftSubTree, heightRightSubTree);
}

bool isBTreeBalanced(Node *root) {
    if (root == nullptr) {
        return true;
    }
    int heightOfLeftSubTree = heightOfBTree(root->left);
    int heightOfRightSubTree = heightOfBTree(root->right);

    if (abs(heightOfLeftSubTree - heightOfRightSubTree) <= 1
        and isBTreeBalanced(root->left)
        and isBTreeBalanced(root->right)) {
        return true;
    } else {
        return false;
    }
}

// Optimisation
// Time: O(N)
bool isBalanced(Node *root, int *height) {
    int heightOfLeftSubTree = 0, heightOfRightSubTree = 0;

    bool isLSubTreeBalanced = false, isRSubTreeBalanced = false;

    if (root == nullptr) {
        *height = 0;
        return true;
    }

    isLSubTreeBalanced = isBalanced(root->left, &heightOfLeftSubTree);
    isRSubTreeBalanced = isBalanced(root->right, &heightOfRightSubTree);

    *height = (heightOfLeftSubTree > heightOfRightSubTree ? heightOfLeftSubTree : heightOfRightSubTree) + 1;

    /* If difference between heights of left and right
    subtrees is more than 2 then this node is not balanced
    so return 0 */

    if (abs(heightOfLeftSubTree - heightOfRightSubTree) >= 2) {
        return false;
    } else {
        /* If this node is balanced and left and right subtrees
        are balanced then return true */

        return isLSubTreeBalanced && isRSubTreeBalanced;
    }
}


int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);

    if (isBTreeBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}
