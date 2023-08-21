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

/* A utility function to insert a new node with
   given data in BST and find its successor */
Node *insert(Node *node, int data, Node *&succ) {

    /* If the tree is empty, return a new node */
    if (node == NULL)
        return node = new Node(data);

    // If key is smaller than root's key, go to left
    // subtree and set successor as current node
    if (data < node->data) {
        succ = node;
        node->left = insert(node->left, data, succ);
    }

        // go to right subtree
    else if (data > node->data)
        node->right = insert(node->right, data, succ);
    return node;
}

// Function to replace every element with the
// least greater element on its right
void replace(vector<int> arr) {
    Node *root = nullptr;
    int n = arr.size();
    // start from right to left
    for (int i = n - 1; i >= 0; i--) {
        Node *succ = nullptr;

        // insert current element into BST and
        // find its inorder successor
        root = insert(root, arr[i], succ);

        // replace element by its inorder
        // successor in BST
        if (succ)
            arr[i] = succ->data;
        else // No inorder successor
            arr[i] = -1;
    }
}

int main() {
//    Node *root = nullptr;
//    root = insertInBST(root, 10);
//    insertInBST(root, 5);
//    insertInBST(root, 50);
//    insertInBST(root, 1);
//    insertInBST(root, 40);
//    insertInBST(root, 100);
    vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92,
                       43, 3, 91, 93, 25, 80, 28};
    replace(arr);
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}
