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
int idx = 0;
unordered_map<int,int> m;
Node* solve(int pre[], int in[], int lb, int ub){
    if(lb>ub){
        return nullptr;
    }

    Node* res = newNode(pre[idx++]);
    if(lb == ub){
        return res;
    }
    int mid = m[res->data];
    res->left = solve(pre,in,lb,mid-1);
    res->right = solve(pre,in,mid+1,ub);
    return res;
}

Node* buildTree(int in[], int pre[], int n){
    idx= 0;
    m.clear();
    for(int i=0; i<n;i++){
        m[in[i]] = i;
    }
    Node* root = solve(pre, in, 0, n-1);
    return root;
}

int main(){

    int in[] = {3 ,1 ,4 ,0 ,5 ,2};
    int pre[] = {0 ,1 ,3 ,4 ,2 ,5};
    int len = sizeof(in) / sizeof(in[0]);
    Node* root = buildTree(in, pre, len);

    /* Let us test the built tree by
    printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    inorder(root);

    return 0;
}