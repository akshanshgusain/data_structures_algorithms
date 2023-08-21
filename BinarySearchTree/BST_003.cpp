//
// Created by Akshansh Gusain on 17/02/22.
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

    __attribute__((unused)) Node(int key, Node *left, Node *right) {
        data = key;
        this->left = left;
        this->right = right;
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

Node *findMin(Node *root){
    Node *current = root;
    while(current != nullptr and current->left!= nullptr){
        current = current->left;
    }
    return current;
}

Node *findMax(Node *root){
    Node *current = root;
    while(current != nullptr and current->right!= nullptr){
        current = current->right;
    }
    return current;
}

Node *findMin2(Node *root){
    if(root->left == nullptr){
        return root;
    }
    return findMin2(root->left);
}

int main() {
    /* Let us create following BST
            50
         /      \
        30      70
     /    \    /   \
    20    40  60    80 */

    Node *root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);

    cout<<findMin2(root)->data<<endl;
    cout<<findMax(root)->data<<endl;

    return 0;
}