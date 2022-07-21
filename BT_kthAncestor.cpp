//
// Created by Akshansh Gusain on 17/03/21.
//

#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

Node *newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* kthAncestorDFS(Node* root, int node, int &k){
    if(!root)
        return nullptr;
    if(root->data == node || kthAncestorDFS(root->left,node, k)
    || (kthAncestorDFS(root->right,node,k))){
        if(k>0){
            k--;
        }else if(k == 0){
            cout<<"Kth ancestor is: "<<root->data<<endl;
            return nullptr;
        }
        return root;
    }
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;

    // print kth ancestor of given node
    Node* parent = kthAncestorDFS(root,node,k);

    // check if parent is not NULL, it means
    // there is no Kth ancestor of the node
    if (parent)
        cout << "-1";
    return 0;
}