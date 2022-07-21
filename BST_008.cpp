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

    Node(int key, Node *left, Node *right) {
        data = key;
        this->left = left;
        this->right = right;
        next = nullptr;
    }
};

/// O(N^2) Solution :




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

void inOrder(Node *head) {
    if (head == nullptr) {
        return;
    }
    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}



int main() {
    Node *root = nullptr;
//    root = insertInBST(root, 20);
//    insertInBST(root, 8);
//    insertInBST(root, 22);
//    insertInBST(root, 4);
//    insertInBST(root, 12);
//    insertInBST(root, 10);
//    insertInBST(root, 14);

    vector<int> nodeData = { 10, 5, 1, 7, 40, 50 };
    root = insertInBST(root , nodeData[0]);

    for(auto it = 1; it < nodeData.size(); it++){
        insertInBST(root,nodeData[it]);
    }
    inOrder(root);
    cout<<endl;


    return 0;
}
