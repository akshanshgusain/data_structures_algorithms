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

void reverseBFS(Node *root) {
    if(root == nullptr){
        cout<<"Empty Tree";
        return;
    }

    stack<Node *> stack;
    queue<Node *> queue;

    queue.push(root);

    while(!queue.empty()){
        Node* top = queue.front();
        stack.push(top);
        queue.pop();

        if(top->left != nullptr){
            queue.push(top->left);
        }

        if(top->right != nullptr){
            queue.push(top->right);
        }
    }

    while(!stack.empty()){
        cout<<stack.top()->data<<" ";
        stack.pop();
    }
}

int main() {
//    Node *root = newNode(1); // Stack Storage
    Node *root = new Node(1); // Heap Storage
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Reverse Breadth First Traversal"<<endl;
    reverseBFS(root);
    return 0;
}

