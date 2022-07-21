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

void printLevelOrder(Node *root){
    if(root == nullptr){
        return;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){

        Node *node = q.front();//print the front of the queue and remove it
        cout<<node->data<<" - ";
        q.pop();

        if(node->left != nullptr){
            q.push(node->left);
        }
        if(node->right != nullptr){
            q.push(node->right);
        }
    }
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<" Level order traversal of Binary Tree is: \n";
    printLevelOrder(root);
    return 0;
}

