//
// Created by Akshansh Gusain on 23/09/21.
//
#include<stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    explicit Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void addAtEnd(Node* &head, int data) {
    // Both ways of creating a Node object are fine.
    Node *myNode = new Node(data);
    Node *last = head;

    if (head == nullptr) {
        head = myNode;
        return;
    }
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = myNode;
}

void addAtStart(Node* &head, int data){
    Node *myNode = new Node(data);
    myNode->next = head;
    head = myNode;
}

void printLL(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    Node *head = nullptr;
    addAtEnd(head, 20);
    addAtEnd(head, 30);
    addAtEnd(head, 50);
    addAtEnd(head, 60);
    addAtEnd(head, 40);
    addAtStart(head, 100);
    printLL(head);
    return 0;
}
