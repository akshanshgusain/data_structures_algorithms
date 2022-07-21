//
// Created by Akshansh Gusain on 16/03/21.
//
#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node *getNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

vector<int> solve(Node* root){
    if(!root){
        return {0,0};
    }
    vector<int> a = solve(root->right);
    vector<int> b = solve(root->left);
    if(a[0]>b[0]){
        return {a[0]+1, a[1]+root->data};
    }
    if(a[0]<b[0]){
        return {b[0]+1, b[1]+root->data};
    }else{
        return {a[0]+1, max(a[1],b[1])+root->data};
    }

}

int sumOfLongestPath(Node* root){
    vector<int> ans = solve(root);
    return ans[1];
}
int main() {
    Node* root = getNode(4);         /*        4        */
    root->left = getNode(2);         /*       / \       */
    root->right = getNode(5);        /*      2   5      */
    root->left->left = getNode(7);   /*     / \ / \     */
    root->left->right = getNode(1);  /*    7  1 2  3    */
    root->right->left = getNode(2);  /*      /          */
    root->right->right = getNode(3); /*     6           */
    root->left->right->left = getNode(6);

    cout<< sumOfLongestPath(root);
    return 0;
}

