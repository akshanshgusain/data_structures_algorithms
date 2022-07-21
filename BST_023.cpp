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

void printLL(Node *parent) {
    Node *curr = parent;
    while (curr != nullptr)
        cout << curr->data << " ", curr = curr->right;
}

void inorder(Node *curr, Node *&prev) {
    if(curr == nullptr){
        return;
    }
    inorder(curr->left, prev);
    prev->left = nullptr;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}

Node *flatten(Node *root) {
    Node *dummy = new Node(-1);
    Node *prev = dummy;

    inorder(root, prev);

    prev->left = nullptr;
    prev->right = nullptr;
    Node *result = dummy->right;

    delete dummy;
    return result;
}

int main() {
    Node *root = nullptr;
    root = insertInBST(root, 5);
    insertInBST(root, 3);
    insertInBST(root, 7);
    insertInBST(root, 2);
    insertInBST(root, 4);
    insertInBST(root, 6);
    insertInBST(root, 8);

    printLL(flatten(root));
    return 0;
}
