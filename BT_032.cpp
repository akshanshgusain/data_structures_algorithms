//
// Created by Akshansh Gusain on 05/02/22.
//
#include<stdc++.h>

using namespace std;

struct Node {
    char data;
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

void printVector(const vector<int>& v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

void printPath(Node *root, vector<int> &path, int k){

    if(root== nullptr){
        return;
    }

    path.push_back(root->data);

    // call for left Sub tree
    printPath(root->left, path, k);

    //call for right Sub tree
    printPath(root->right, path, k);

    int sum = 0;
    for(int i = path.size() -1; i >= 0; i--){
        sum += path[i];
        if(sum == k){
            printVector(path, i);
        }
    }

    path.pop_back(); //backtrack
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    vector<int> path;
    printPath(root, path, k);

    return 0;
}