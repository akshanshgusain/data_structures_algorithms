//
// Created by Akshansh Gusain on 16/03/21.
//
#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data  = data;
    node->left  =  node->right  = NULL;
    return(node);
}
int mirror(Node* a, Node* b){
    if(a== nullptr && b== nullptr){
        return true;
    }
    if(a== nullptr || b== nullptr){
        return false;
    }
    return a->data == b->data && mirror(a->left, b->right) && mirror(a->right, b->left);
}

int main() {
    Node *a = newNode(1);
    Node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left  = newNode(4);
    a->left->right = newNode(5);

    b->left = newNode(3);
    b->right = newNode(2);
    b->right->left = newNode(5);
    b->right->right = newNode(4);

    mirror(a, b)? cout << "Yes" : cout << "No";
    return 0;
}
