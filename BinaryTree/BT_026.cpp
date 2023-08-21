//
// Created by Akshansh Gusain on 02/02/22.
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

// The idea is to serialize subtrees as strings and store the strings in hash table. Once we find a serialized tree
// (which is not a leaf) already existing in hash-table, we return true.

string serializeTree(Node *root, unordered_set<string> &subTree) {
    string serialised = "";
    if (root == nullptr) {
        return serialised + '$';
    }

    string LST = serializeTree(root->left, subTree);
    if (LST == serialised) {
        return "";
    }
    string RST = serializeTree(root->right, subTree);
    if (RST == serialised) {
        return "";
    }

    serialised = serialised + root->data + LST + RST;

    if (serialised.length() > 3 and subTree.find(serialised) != subTree.end()) {
        return "";
    }
    subTree.insert(serialised);
    return serialised;
}

int main() {
    Node *root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('B');
    root->right->right->right = new Node('E');
    root->right->right->left = new Node('D');
//    root->right->right->left->right = new Node('T');

    //Hash
    unordered_set<string> subTrees;
    string serializedTree = serializeTree(root, subTrees);
    if (serializedTree == "") {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;

}