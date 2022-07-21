//
// Created by Akshansh Gusain on 12/03/21.
//
#include<stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node *newNode(int data) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}
void printLeaves(struct node* root){
    if(!root)
        return;

    printLeaves(root->left);

    if(!(root->left) && !(root->right)){
        cout<<root->data<<" ";
    }

    printLeaves(root->right);
}

void printLeftBoundary(struct node* root){
    if(!root)
        return;

    if(root->left){
        //we have to print top-down, that means first print then call
        cout<<root->data<<" ";
        printLeftBoundary(root->left);
    }else if(root->right){
        cout<<root->data<<" ";
        printLeftBoundary(root->right);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}



void printRightBoundary(struct node* root){
    if(!root){
        return;
    }
    if(root->right){
        printRightBoundary(root->right);
        cout<<root->data<<" ";
    }else if(root->left){
        printRightBoundary(root->left);
        cout<<root->data<<" ";
    }

}


void printBoundary(struct node* root){
        if(!root)
            return;
        cout<<root->data<<" ";
        printLeftBoundary(root->left);
        printLeaves(root->left);
        printLeaves(root->right);
        printRightBoundary(root->right);
}

int main() {
    struct node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    printBoundary(root);
    return 0;
}
