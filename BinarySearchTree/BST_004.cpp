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

    Node(int key, Node *left, Node *right) {
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


void inOrderTraversal(Node *root, Node *key, Node *successor) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left, key, successor);

    if (root->data > key->data and successor->data == -1) {
        successor->data = root->data;
        return;
    }

    inOrderTraversal(root->right, key, successor);
}

Node *inOrderSuccessor(Node *root, Node *n) {
    Node *succ = new Node(-1);
    inOrderTraversal(root, n, succ);
    return succ;
}


void inOrderTraversal2(Node *root, Node *key, Node *successor) {
    if (root == nullptr) {
        return;
    }


    inOrderTraversal2(root->right, key, successor);
    if (root->data < key->data and successor->data == -1) {
        successor->data = root->data;
        return;
    }
    inOrderTraversal2(root->left, key, successor);

}

Node *inOrderPredecessor(Node *root, Node *n) {
    Node *succ = new Node(-1);
    inOrderTraversal2(root, n, succ);
    return succ;
}



int main() {
    Node *root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);

    Node *temp = root->right->left;

    Node *succ = inOrderSuccessor(root, temp);
    if (succ != nullptr)
        cout << "\n Inorder Successor of " << temp->data << " is " << succ->data;
    else
        cout << "\n Inorder Successor doesn't exit";

    Node *pree = inOrderPredecessor(root, temp);
    if (pree != nullptr)
        cout << "\n Inorder Predecessor of " << temp->data << " is " << pree->data;
    else
        cout << "\n Inorder Successor doesn't exit";


//     Inorder Successor of 60 is 70
// Inorder Predecessor of 60 is 50

    return 0;
}