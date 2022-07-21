//
// Created by Akshansh Gusain on 18/02/22.
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

Node *insertInBST(Node *head, int key) {
    if (head == nullptr) {
        return new Node(key);
    }

    if (key < head->data) {
        head->left = insertInBST(head->left, key);
    } else if (key > head->data) {
        head->right = insertInBST(head->right, key);
    }

    return head;
}

void inorder(Node *root, vector<int> &ans) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

bool checkBST(Node *root) {


    vector<int> inorderTraversal;
    inorder(root, inorderTraversal);

    for(auto it: inorderTraversal){
        cout<<it <<" ";
    }
    cout<<endl;

    for (int i = 1; i < inorderTraversal.size(); i++) {
        if(inorderTraversal[i-1] >= inorderTraversal[i]){
            return false;
        }
    }
    return true;
}

int main() {
    Node *root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);

    cout<<checkBST(root)<<endl;

    Node *root2 = new Node(1);
    root2->left = new Node(10);
    root2->right = new Node(3);
    root2->left->left = new Node(5);
    root2->left->right = new Node(4);

    cout<<checkBST(root2)<<endl;

    return 0;
}