//
// Created by Akshansh Gusain on 21/02/22.
//
//
// Created by Akshansh Gusain on 17/02/22.
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
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}


Node *sortedArrayToBST(vector<int> arr, int start, int end) {
    // Base case
    if(start > end){
        return nullptr;
    }
    // 1. Get the Middle of the array and make it root.
    int mid = (start + end)/2;
    Node *root = new Node (arr[mid]);

    // 2. Recursively construct the left subtree and right subtree
    root->left = sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}

/*

1) Get the Middle of the array and make it root.
2) Recursively do same for left half and right half.
      a) Get the middle of left half and make it left child of the root
          created in step 1.
      b) Get the middle of right half and make it right child of the
          root created in step 1.
 */

int main() {
    vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7};
    Node *root = sortedArrayToBST(sortedArray, 0, sortedArray.size()-1);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);
    return 0;
}

