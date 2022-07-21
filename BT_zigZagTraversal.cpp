//
// Created by Akshansh Gusain on 11/03/21.
// O(n)- time and O(n)- space
#include<stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void zizagtraversal(struct Node* root){
    if(root == nullptr)
        return;

    stack<struct Node*> currentlevel;
    stack<struct Node*> nextlevel;

    currentlevel.push(root);

    bool lefttoright = true;
    while(!currentlevel.empty()){
        struct Node* temp = currentlevel.top();
        currentlevel.pop();

        if(temp){
            cout<<temp->data<<" ";

            //store the data according to current order
            if(lefttoright){
                if(temp->left)
                    nextlevel.push(temp->left);
                if(temp->right)
                    nextlevel.push(temp->right);
            }else{
                if(temp->right)
                    nextlevel.push(temp->right);
                if(temp->left)
                    nextlevel.push(temp->left);
            }
        }
        if(currentlevel.empty()){
            lefttoright = !lefttoright;
            // do-not forget to swap those two stacks at the end of each level(i.e., when current level is empty)
            swap(currentlevel, nextlevel);
        }
    }
}

int main() {

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag Order traversal of binary tree is \n";

    zizagtraversal(root);
    return 0;
}
