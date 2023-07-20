//
// Created by Akshansh Gusain on 07/02/22.
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


Node *findLCA(Node *root, int n1, int n2) {
    if (root == nullptr) {
        return root;
    }

    if (root->data == n1 or root->data == n2) {
        return root;
    }

    Node *leftLCA = findLCA(root->left, n1, n2);
    Node *rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA != nullptr and rightLCA != nullptr) {
        return root;
    }

    if(leftLCA!= nullptr){
        return leftLCA;
    }else{
        return rightLCA;
    }

}


int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->data;
    cout << "\nLCA(6, 7) = " << findLCA(root, 6, 7)->data;
    cout << "\nLCA(7, 4) = " << findLCA(root, 7, 4)->data;

    return 0;
}