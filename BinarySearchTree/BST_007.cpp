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

Node *findLCA(Node *root, int n1, int n2){
    // base cases
    if(root == nullptr){
        return new Node(-1);
    }

    if(root->data > n1 and root->data > n2){
        return findLCA(root->left, n1, n2);
    }
    if(root->data < n1 and root->data < n2){
        return findLCA(root->right, n1, n2);
    }
    return root;
}

int main() {
    Node *root = nullptr;
    root = insertInBST(root, 20);
    insertInBST(root, 8);
    insertInBST(root, 22);
    insertInBST(root, 4);
    insertInBST(root, 12);
    insertInBST(root, 10);
    insertInBST(root, 14);
    inOrder(root);cout<<endl;

    int n1 = 4, n2 = 14;
    Node *LCA = findLCA(root, n1, n2);
    cout<<"LCA of "<<n1<<" and "<<n2<<" is :"<<LCA->data<<endl;

    return 0;
}