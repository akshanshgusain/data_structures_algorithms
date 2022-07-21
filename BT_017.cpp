//
// Created by Akshansh Gusain on 25/01/22.
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

void diagonalTraversal_(Node *root, int diagonal, map<int, vector<int>> &diagonalMap) {
    if (root == nullptr) {
        return;
    }

    diagonalMap[diagonal].push_back(root->data);

    if (root->left != nullptr) {
        diagonalTraversal_(root->left, diagonal + 1 ,diagonalMap);
    }
    if (root->right != nullptr) {
        diagonalTraversal_(root->right, diagonal  ,diagonalMap);
    }

}

void diagonalTraversal(Node *root) {
    // <DiagonalDistance, vector<Node at tha diagonal>>
    map<int, vector<int>> diagonalMap;

    int diagonal = 0;
    diagonalTraversal_(root, diagonal, diagonalMap);

    cout<<"Diagonal Traversal of the binary tree: "<<endl;
    for(auto diagonal : diagonalMap){
        for(auto node: diagonal.second){
            cout<<node<<" ";
        }
        cout<<endl;
    }
}

int main() {
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);


    diagonalTraversal(root);
    //Diagonal Traversal of binary tree :
    //8 10 14
    //3 6 7 13
    //1 4
    return 0;
}