//
// Created by Akshansh Gusain on 21/02/22.
//
#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right, *next;

    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }

    Node(int key, Node *left, Node *right) {
        data = key;
        this->left = left;
        this->right = right;
        next = nullptr;
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

void inOrder(Node *head) {
    if (head == nullptr) {
        return;
    }
    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}

void inorderSuccessor(Node *head, vector<int> &ordered){
    if(head == nullptr){
        return;
    }
    inorderSuccessor(head->left, ordered);
    ordered.push_back(head->data);
    inorderSuccessor(head->right, ordered);
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
    inOrder(root);
    cout<<endl;
    vector<int> ans;
    inorderSuccessor(root, ans);

    for(int i = 0; i < ans.size()-1; i++){
        cout<<"Next of"<<ans[i]<<" is: "<<ans[i+1]<<endl;
    }

    return 0;
}