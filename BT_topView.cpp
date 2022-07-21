//
// Created by Akshansh Gusain on 11/03/21.
//
#include<stdc++.h>

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int hd;
    int data;
};

// function to create a new node
Node *newNode(int key) {
    Node *node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}
void topView(Node* root){
    if (root == NULL)
        return;
    queue<Node*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;

    // push node and horizontal distance to queue
    q.push(root);

    cout << "The top view of the tree is : \n";

    while (q.size()) {
        hd = root->hd;

        // count function returns 1 if the container
        // contains an element whose key is equivalent
        // to hd, or returns zero otherwise.
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }

    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }
}

int main() {
/* Create following Binary Tree
            1
        / \
        2 3
        \
            4
            \
            5
            \
                6*/
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary "
            "Tree\n";
    topView(root);

    return 0;
}

