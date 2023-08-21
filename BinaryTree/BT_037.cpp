//
// Created by Akshansh Gusain on 09/02/22.
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


// Run a inorder - traversal
string findAllDuplicates(Node *root, unordered_map<string, int> &map) {
    if (root == nullptr) {
        return "";
    }
    string str = "(";
    str += findAllDuplicates(root->left, map);
    str += to_string(root->data);
    str += findAllDuplicates(root->right, map);
    str += ")";
    // Subtree already present (Note that we use
    // unordered_map instead of unordered_set
    // because we want to print multiple duplicates
    // only once, consider example of 4 in above
    // subtree, it should be printed only once.
    if(map[str] == 1){
        cout<<root->data<<" ";
    }
    map[str]++;

    return str;
}


int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(2);
    root->right->left->left = new Node(4);
    root->right->right = new Node(4);
    unordered_map<string, int> hashMap;
    findAllDuplicates(root, hashMap);
    return 0;
}