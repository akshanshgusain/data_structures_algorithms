//
// Created by Akshansh Gusain on 21/02/22.
//
#include<stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right, *next;

    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }

    __attribute__((unused)) Node(int key, Node *left, Node *right) {
        data = key;
        this->left = left;
        this->right = right;
        next = nullptr;
    }
};

Node *insertInBST(Node *head, int key) {
    if (head == nullptr) {
        return new Node(key);
    }

    if (key < head->data) {
        head->left = insertInBST(head->left, key);
    } else if (key > head->data) {
        head->right = insertInBST(head->right, key);
    }

    return head;
}


int countPairs(Node *root1, Node *root2, int X) {
    if (root1 == nullptr or root2 == nullptr) {
        return 0;
    }

    stack<Node *> st1, st2;
    Node *top1, *top2;

    int count = 0;

    // Loop will break when either of two traversals gets completed
    while (true) {
        // to find next node in inorder
        // traversal of BST 1
        while (root1 != nullptr) {
            st1.push(root1);
            root1 = root1->left;
        }

        // Similarly, to find next node in REVERSE
        // inorder traversal of BST 2
        while (root2 != NULL) {
            st2.push(root2);
            root2 = root2->right;
        }

        // if either gets empty then corresponding
        // tree traversal is completed
        if (st1.empty() || st2.empty()) {
            break;
        }
        top1 = st1.top();
        top2 = st2.top();

        // if the sum of the nodes is equal to 'X'
        if ((top1->data + top2->data) == X) {
            // increment count
            count++;

            // pop nodes from the respective stacks
            st1.pop();
            st2.pop();

            // insert next possible node in the
            // respective stacks
            root1 = top1->right;
            root2 = top2->left;
        }

            // move to next possible node in the
            // inorder traversal of BST 1
        else if ((top1->data + top2->data) < X) {
            st1.pop();
            root1 = top1->right;
        }

            // move to next possible node in the
            // reverse inorder traversal of BST 2
        else {
            st2.pop();
            root2 = top2->left;
        }
    }
    return count;
}



// 1. Traverse BST 1 from smallest value to node to largest.
// 2. Traverse BST 2 from largest value node to smallest.
// 3 . Sum up the corresponding node’s value from both the BSTs at a particular instance of traversals.
//      - If sum == x, then increment count.
//      - If x > sum, then move to the inorder successor of the current node of BST 1.
//      - else move to the inorder predecessor of the current node of BST 2
// Perform these operations until either of the two traversals gets completed.


int main() {
    Node *root = nullptr;
    root = insertInBST(root, 5);
    insertInBST(root, 3);
    insertInBST(root, 7);
    insertInBST(root, 2);
    insertInBST(root, 4);
    insertInBST(root, 6);
    insertInBST(root, 8);

    Node *root2 = nullptr;
    root2 = insertInBST(root2, 10);
    root2 = insertInBST(root2, 6);
    root2 = insertInBST(root2, 15);
    root2 = insertInBST(root2, 3);
    root2 = insertInBST(root2, 8);
    root2 = insertInBST(root2, 11);
    root2 = insertInBST(root2, 18);

    int X = 6;
    cout << "Pairs = " << countPairs(root, root2, X);

    return 0;
}
