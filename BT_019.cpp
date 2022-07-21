//
// Created by Akshansh Gusain on 25/01/22.
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

//https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/
// Time: O(N)

// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
void binaryTree2DoubleLinkedList(Node *root, Node **head){
    if(root == nullptr){
        return;
    }

    static Node *previous = nullptr;
    binaryTree2DoubleLinkedList(root->left, head);

    if(previous == nullptr){
        *head = root;
    }else{
        root->left = previous;
        previous->right = root;
    }
    previous = root;

    binaryTree2DoubleLinkedList(root->right, head);
}

void printList(Node *node)
{
    while (node!=nullptr)
    {
        cout << node->data << " ";
        node = node->right;
    }
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    // Convert to DLL
    Node *head = nullptr;
    binaryTree2DoubleLinkedList(root, &head);

    // Print the converted list
    printList(head); // 25 12 30 10 36 15
    return 0;
}
