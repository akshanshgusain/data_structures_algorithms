//
// Created by Akshansh Gusain on 10/03/21.
//
//Using queues

#include<stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

void reverseLevelOrder(Node *root){
    if(root == nullptr){
        return;
    }

    stack<Node *> s;
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){

        root = q.front();
        q.pop();
        s.push(root);

        /* Enqueue right child */
        if (root->right)
            q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT

        /* Enqueue left child */
        if (root->left)
            q.push(root->left);
    }

    // Now pop all items from stack one by one and print them
    while (!s.empty())
    {
        root = s.top();
        cout << root->data << " ";
        s.pop();
    }

}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    cout<<" Level order traversal of Binary Tree is: \n";
    reverseLevelOrder(root);
    return 0;
}

