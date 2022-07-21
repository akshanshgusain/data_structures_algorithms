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


void preOrder(Node *node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void buildArray(Node *root, vector<int> &arr) {
    if (root == nullptr) {
        return;
    }
    buildArray(root->left, arr);
    arr.push_back(root->data);
    buildArray(root->right, arr);
}

Node *BSTFromSortedArray(vector<int> &arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = BSTFromSortedArray(arr, start, mid - 1);
    root->right = BSTFromSortedArray(arr, mid + 1, end);

    return root;
}

Node *buildTree(Node *root) {
    vector<int> sortedArray;
    buildArray(root, sortedArray);

    return BSTFromSortedArray(sortedArray, 0, sortedArray.size() - 1);
}

/*
1. Traverse given BST in inorder and store result in an array. This step takes O(n) time.
 Note that this array would be sorted as inorder traversal of BST always produces sorted sequence.
2. Build a balanced BST from the above created sorted array using the recursive approach discussed here.
 This step also takes O(n) time as we traverse every element exactly once and processing an element takes
 O(1) time.


 * */
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
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);

    root = buildTree(root);

    printf("Preorder traversal of balanced "
           "BST is : \n");
    preOrder(root);
    return 0;
}
