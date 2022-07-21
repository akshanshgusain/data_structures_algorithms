//
// Created by Akshansh Gusain on 28/01/22.
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


void printInOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr) {
        printInOrder(root->left);
    }
    cout << root->data << " ";

    if (root->right != nullptr) {
        printInOrder(root->right);
    }
}

//int search(char arr[], int strt, int end, char value) {
//    int i;
//    for (i = strt; i <= end; i++) {
//        if (arr[i] == value)
//            return i;
//    }
//}
//
//Node *buildTree(char inorder[], char preorder[], int inorderStart, int inorderEnd) {
//
//    static int preIndex = 0;
//    if(inorderStart > inorderEnd){
//        return nullptr;
//    }
//
//    //Pick current node from Preorder traversal using preIndex and increment preIndex
//    Node *newNode = new Node(preorder[preIndex]);
//    preIndex++;
//
//    if(inorderStart == inorderEnd){
//        return newNode;
//    }
//
//    int inIndex = search(inorder, inorderStart, inorderEnd, newNode->data);
//    newNode->left = buildTree(inorder, preorder, inorderStart, inIndex - 1);
//    newNode->right = buildTree(inorder, preorder, inIndex + 1, inorderEnd);
//
//    return newNode;
//}
//
//int main() {
//    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
//    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
//    int len = sizeof(in) / sizeof(in[0]);
//
//    Node *root = buildTree(in, pre, 0, len - 1);
//
//    cout << "Inorder traversal of the constructed tree is \n";
//    printInOrder(root); //D B E A F C
//    return 0;
//}


///----- OPTIMISED:
int search(char arr[], int strt, int end, char value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
}

Node *buildTree(char inorder[], char preorder[], int inorderStart, int inorderEnd, unordered_map<char, int> &map) {

    static int preIndex = 0;
    if (inorderStart > inorderEnd) {
        return nullptr;
    }

    //Pick current node from Preorder traversal using preIndex and increment preIndex
    char currentItem = preorder[preIndex];
    Node *newNode = new Node(currentItem);
    preIndex++;

    if (inorderStart == inorderEnd) {
        return newNode;
    }

    int inIndex = map[currentItem];
    newNode->left = buildTree(inorder, preorder, inorderStart, inIndex - 1, map);
    newNode->right = buildTree(inorder, preorder, inIndex + 1, inorderEnd, map);

    return newNode;
}

int main() {
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);

    unordered_map<char, int> map;
    for (int i = 0; i < len; i++) {
        map[in[i]] = i;
    }
    Node *root = buildTree(in, pre, 0, len - 1, map);

    cout << "Inorder traversal of the constructed tree is \n";
    printInOrder(root); //D B E A F C
    return 0;
}