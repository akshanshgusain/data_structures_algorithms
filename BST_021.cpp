//
// Created by Akshansh Gusain on 22/02/22.
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

    explicit Node(int key) {
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

/* Helper Functions */
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

vector<int> getInOrder(Node *root) {
    vector<int> inorder;
    Node *curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            inorder.push_back(curr->data);
            curr = curr->right;
        } else {
            Node *prev = curr->left;
            while (prev->right and prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

vector<int> getPreOrder(Node *root) {
    vector<int> inorder;
    Node *curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            inorder.push_back(curr->data);
            curr = curr->right;
        } else {
            Node *prev = curr->left;
            while (prev->right and prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = curr;
                inorder.push_back(curr->data);
                curr = curr->left;
            } else {
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }

    return inorder;
}

/* Helper Functions */

//We can check if the given preorder traversal is valid or not for a BST without using stack.
// The idea is to use the similar concept of “Building a BST using narrowing bound algorithm”.
// We will recursively visit all nodes, but we will not build the nodes. In the end, if the
// complete array is not traversed, then that means that array can not represent the preorder
// traversal of any binary tree.

void buildBST(vector<int> preorder, int n, int &preIndex, int max, int min) {
    if (preIndex >= n) {
        return;
    }

    if (min <= preorder[preIndex] and preorder[preIndex] <= max) {
        int rootData = preorder[preIndex];
        preIndex++;

        buildBST(preorder, n, preIndex, min, rootData);
        buildBST(preorder, n, preIndex, rootData, max);
    }
}

bool canRepresentBST(vector<int> preorder) {
    int max = INT_MAX;
    int min = INT_MIN;
    int preIndex = 0;
    int n = preorder.size();
    return preIndex == n;
}


int main() {
    Node *root = nullptr;
    root = insertInBST(root, 10);
    insertInBST(root, 5);
    insertInBST(root, 50);
    insertInBST(root, 1);
    insertInBST(root, 40);
    insertInBST(root, 100);

    vector<int> preorder2 = {5, 3, 4, 1, 6, 10};
    if (canRepresentBST(preorder2))
        cout << "\npreorder2 can represent BST";
    else
        cout << "\npreorder2 can not represent BST";
    return 0;
}
