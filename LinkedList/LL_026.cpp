//
// Created by Akshansh Gusain on 18/10/21.
//

#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *down;
    Node *right;

    explicit Node(int data) {
        this->data = data;
        down = nullptr;
        right = nullptr;
    }
};

void push(Node *&head, int data) {
    Node *newNode = new Node(data);
    newNode->down = head;
    head = newNode;
}

void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->down;
    }
}

Node* merge(Node* a, Node* b){
    if(a == nullptr){
        return b;
    }
    if(b == nullptr){
        return a;
    }

    Node *result;
    if(a->data <= b->data){
        result = a;
        result->down = merge(a->down, b);
    }else{
        result = b;
        result->down = merge(a, b->down);
    }
    result-> right = nullptr;
    return result;
}

Node* flatten(Node* head){
        if(head == nullptr or head->right == nullptr){
            return head;
        }
        return merge(head, flatten(head->right));
}

int main() {
    Node* head = nullptr;
    push(head, 30);
    push(head, 8);
    push(head, 7);
    push(head, 5);

    push(head->right, 20);
    push(head->right, 10);

    push(head->right->right, 50);
    push(head->right->right, 22);
    push(head->right->right, 19);

    push(head->right->right->right, 45);
    push(head->right->right->right, 40);
    push(head->right->right->right, 35);
    push(head->right->right->right, 20);

    head = flatten(head);

    printList(head);
    return 0;
}