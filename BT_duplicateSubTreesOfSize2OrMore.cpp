//
// Created by Akshansh Gusain on 16/03/21.
//

#include<stdc++.h>

using namespace std;

const string MARKER = "$";

struct Node {
    char key;
    Node *left, *right;
};

Node *newNode(char key) {
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

unordered_map<string, int> m;

string solve(Node *root) {
    if (!root) {
        return MARKER;
    }
    string s = "";

    if (!root->right and !root->left) {
        s = to_string(root->key);
        return s;
    }
    s = s + to_string(root->key);
    s = s + solve(root->left);
    s = s + solve(root->right);
    m[s]++;
    return s;
}

bool dupSub(Node *root){
    m.clear();
    solve(root);
    for(auto x:m){
        if(x.second >= 2){
            return true;
        }
    }
    return false;
}

int main() {
    Node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('B');
    root->right->right->right = newNode('E');
    root->right->right->left = newNode('D');

    if(dupSub(root)){
        cout << " Yes ";
    }else{
        cout << " No ";
    }


    return 0;
}
