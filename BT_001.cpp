//
// Created by Akshansh Gusain on 18/01/22.
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

void printLevelOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {

        Node *node = q.front();//print the front of the queue and remove it
        cout << node->data << " - ";
        q.pop();

        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

int main() {
//    Node *root = newNode(1);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << " Level order traversal of Binary Tree is: \n";
    //1 - 2 - 3 - 4 - 5
    printLevelOrder(root);
    return 0;
}
