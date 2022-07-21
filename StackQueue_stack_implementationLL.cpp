//
// Created by Akshansh Gusain on 01/04/21.
//
#include<stdc++.h>
using namespace std;

class StackNode{
public:
    int data;
    StackNode* next;
};

StackNode* newNode(int data){
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = nullptr;
    return stackNode;
}

int isEmpty(StackNode* root){
    return !root;
}

void push(StackNode** root, int data){
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout<<data<<" pushed to stack \n";
}

int pop(StackNode** root){
    if(isEmpty(*root)){
        return INT_MIN;
    }
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
}

int peek(StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main(){
    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    cout << pop(&root) << " popped from stack\n";

    cout << "Top element is " << peek(root) << endl;

    cout<<"Elements present in stack : ";
    //print all elements in stack :
    while(!isEmpty(root))
    {
        // print top element in stack
        cout<<peek(root)<<" ";
        // remove top element in stack
        pop(&root);
    }
    return 0;
}
