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

/// O(N^2) Solution :




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

void storeInorder(Node *root, vector<int> &sortedInorder){
    if(root == nullptr){
        return;
    }

    storeInorder(root->left, sortedInorder);
    sortedInorder.push_back(root->data);
    storeInorder(root->right, sortedInorder);
}

void arrayToBST(Node *root, vector<int> sortedInOrder, int &index){
    if(root == nullptr){
        return;
    }

    arrayToBST(root->left, sortedInOrder, index);
    root->data = sortedInOrder[index];
    index++;
    arrayToBST(root->right, sortedInOrder, index);
}

//Node *sortedArrayToBST(vector<int> arr, int start, int end) {
//    // Base case
//    if(start > end){
//        return nullptr;
//    }
//    // 1. Get the Middle of the array and make it root.
//    int mid = (start + end)/2;
//    Node *root = new Node (arr[mid]);
//
//    // 2. Recursively construct the left subtree and right subtree
//    root->left = sortedArrayToBST(arr, start, mid-1);
//    root->right = sortedArrayToBST(arr, mid+1, end);
//
//    return root;
//}

void binaryTreeToBST(Node *root){
    if(root == nullptr){
        return;
    }
    vector<int> sortedInorder;
    // 1 .Store in Array
    storeInorder(root, sortedInorder);
    // 2. Sort the array
    sort(sortedInorder.begin(), sortedInorder.end());
    // 3. Create BST from the sorted array
    int i = 0;
    arrayToBST(root, sortedInorder, i);
}

//Given a Binary Tree, convert it to a Binary Search Tree. The conversion must be done in such a way
// that keeps the original structure of Binary Tree.

int main() {
//    Node *root = nullptr;
//    root = insertInBST(root, 20);
//    insertInBST(root, 8);
//    insertInBST(root, 22);
//    insertInBST(root, 4);
//    insertInBST(root, 12);
//    insertInBST(root, 10);
//    insertInBST(root, 14);
    Node *root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);

    // convert Binary Tree to BST
    binaryTreeToBST(root);

    cout <<"Following is Inorder Traversal of the converted BST:" << endl ;
    inOrder(root);

    //Following is Inorder Traversal of the converted BST:
    //5 10 15 20 30

    return 0;
}
