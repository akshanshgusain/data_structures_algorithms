//
// Created by Akshansh Gusain on 02/02/22.
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

bool areMirror(Node *A, Node *B) {
    if (A == nullptr and B == nullptr) {
        return true;
    }

    if (A == nullptr or B == nullptr) {
        return false;
    }

    return (A->data == B->data) and areMirror(A->left, B->right) and areMirror(A->right, B->left);
}

int main() {
    Node *A = new Node(1);
    Node *B = new Node(1);
    A->left = new Node(2);
    A->right = new Node(3);
    A->left->left = new Node(4);
    A->left->right = new Node(5);

    B->left = new Node(3);
    B->right = new Node(2);
    B->right->left = new Node(5);
    B->right->right = new Node(4);

    areMirror(A, B) ? cout << "Yes" : cout << "No";
    return 0;

}