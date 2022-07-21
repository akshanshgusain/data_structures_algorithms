//
// Created by Akshansh Gusain on 12/03/21.
//
#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
};

// A utility function to create
// a new tree node
Node *newNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return (node);
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << "\t" << root->data;
        inorder(root->right);
    }
}

void solve(Node* root, Node* &head, Node* &prev, int &flag){
        if(!root){
            return;
        }
        solve(root->left, head, prev, flag);
        if(flag==0){
            flag = 1;
            head = root;
            prev = root;
        }else{
            prev->right = root;
            prev->right->left = prev;
            prev = prev->right;
        }
        solve(root->right, head, prev, flag);
}

Node *bToDLL(Node *root) {
    Node *head = nullptr;
    Node *prev = nullptr;
    int flag = 0;
    solve(root, head, prev, flag);
    return head;
}

void printList(Node *root) {
    while (root != nullptr) {
        cout << "\t" << root->data;
        root = root->right;
    }
}

int main() {
    Node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    cout << "\n\t\tInorder Tree Traversal\n\n";
    inorder(root);

    Node *head = bToDLL(root);

    cout << "\n\n\t\tDLL Traversal\n\n";
    printList(head);
    return 0;
}