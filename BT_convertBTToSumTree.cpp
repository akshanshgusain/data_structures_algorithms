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

int solve(Node* root){
    if(!root){
        return 0;
    }
    int a = solve(root->left);
    int b = solve(root->right);
    int x = root->data;
    root->data = a+b;
    return a+b+x;
}

void toSumTree(Node *root){
    solve(root);
}

int main(){
    Node *root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    cout<<"Inorder Traversal of the original tree is: \n";
    inorder(root);

    toSumTree(root);

    // Print inorder traversal of the converted
    // tree to test result of toSumTree()
    cout<<endl;
    cout<<"Inorder Traversal of the resultant tree is: \n";
    inorder(root);

    return 0;
}
