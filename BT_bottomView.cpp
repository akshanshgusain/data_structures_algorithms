//
// Created by Akshansh Gusain on 11/03/21.
//Using Queues
#include<stdc++.h>

using namespace std;

struct Node {
    int data; //data of the node
    int hd; //horizontal distance of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key) {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};

void bottomView(Node *root){
    if(root==nullptr){
        return;
    }

    int hd =0;
    map<int, int> m;
    queue<Node *> q;

    root->hd = hd;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        hd = temp->hd;
        //Put the dequeued tree node to TreeMap
        // having key as horizontal distance. Every
        // time we find a node having same horizontal
        // distance we need to replace the data in
        // the map.
        m[hd] = temp->data;

        if(temp-> left != nullptr){
            temp->left->hd = hd-1;
            q.push(temp->left);
        }

        if(temp->right != nullptr){
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }

    // Traverse the map elements using the iterator.
    for (auto & i : m)
        cout << i.second << " ";
}

int main() {
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;
}

