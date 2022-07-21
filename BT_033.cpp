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

void printPath(Node *root, vector<int> &path, int k, int SUM_SO_FAR){

    if(root== nullptr){
        return;
    }

    SUM_SO_FAR += root->data;
    path.push_back(root->data);

    if(SUM_SO_FAR == k){
        printVector(path, 0);
    }

    printPath(root->left, path, k, SUM_SO_FAR);
    printPath(root->right, path, k, SUM_SO_FAR);


    // Remove last element from path
    // and move back to parent
    path.pop_back();
}

int main() {
//    Node *root = new Node(1);
//    root->left = new Node(3);
//    root->left->left = new Node(2);
//    root->left->right = new Node(1);
//    root->left->right->left = new Node(1);
//    root->right = new Node(-1);
//    root->right->left = new Node(4);
//    root->right->left->left = new Node(1);
//    root->right->left->right = new Node(2);
//    root->right->right = new Node(5);
//    root->right->right->right = new Node(2);
//
//    int k = 5;
    Node *root = new Node(10);
    root->left = new Node(28);
    root->right = new Node(13);

    root->right->left = new Node(14);
    root->right->right = new Node(15);

    root->right->left->left = new Node(21);
    root->right->left->right = new Node(22);
    root->right->right->left = new Node(23);
    root->right->right->right = new Node(24);

    int k = 38;

    vector<int> path;
    int SUM_SO_FAR = 0;
    printPath(root, path, k, SUM_SO_FAR);

    return 0;
}