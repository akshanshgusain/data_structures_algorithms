//
// Created by Akshansh Gusain on 17/03/21.
//
#include<stdc++.h>

using namespace std;

struct Node {
    struct Node *left, *right;
    int data;
};

// Utility function to create a new tree Node
Node *newNode(int key) {
    Node *temp = new Node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

Node* lca(Node* root, int a, int b){
    if(!root){
        return nullptr;
    }
    if(root->data==a or root->data==b)
        return root;
    Node* l = lca(root->left,a,b);
    Node* r = lca(root->right,a,b);

    if(l and r)
        return root;
    if(l)
        return l;
    return r;
}

int solve(Node* root, int val){
    if(!root)
        return 0;
    if(root->data == val)
        return 1;
    int a = solve(root->left, val);
    int b = solve(root->right, val);

    if(!a and !b)
        return 0;
    else
        return a+b+1;
}

int findDistance(Node* node, int a, int b){
    Node* LCA = lca(node,a,b);
    int x = solve(LCA, a);
    int y = solve(LCA, b);
    return x+y-2;
}
int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}
