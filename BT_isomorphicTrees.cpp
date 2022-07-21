//
// Created by Akshansh Gusain on 17/03/21.
//
#include<stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

node *newNode(int data) {
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return (temp);
}

bool isIsomorphic(node* root1, node* root2){
    if(!root1 and !root2)
        return true;
    if(!root1 || !root2)
        return false;
    if(root1->data != root2->data)
        return false;
    bool a = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
    bool b = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
    return a or b;
}

int main() {
    struct node *n1 = newNode(1);
    n1->left        = newNode(2);
    n1->right       = newNode(3);
    n1->left->left  = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left  = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);

    struct node *n2 = newNode(1);
    n2->left         = newNode(3);
    n2->right        = newNode(2);
    n2->right->left   = newNode(4);
    n2->right->right   = newNode(5);
    n2->left->right   = newNode(6);
    n2->right->right->left = newNode(8);
    n2->right->right->right = newNode(7);

    if (isIsomorphic(n1, n2) == true)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
