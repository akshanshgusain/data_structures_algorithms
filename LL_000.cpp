//
// Created by Akshansh Gusain on 23/04/23.
//
#include<bits/stdc++.h>

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

void addAtEnd(Node **head, int data) {

    // Both ways of creating a Node object are fine.
    Node *myNode = new Node(data);

    Node *last = *head;

    if (*head == nullptr) {
        *head = myNode;
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = myNode;
}

void printLL(Node *head) {

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


void reverseLL(Node **head) {
    Node *prev, *curr, *next;
    curr = *head;
    prev = next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev; // reverse the pointer
        prev = curr; // forward prev ptr
        curr = next; // forward curr ptr

    }

    *head = prev;
}

Node* reverseR(Node* &head){
    // base case
    if(head->next == nullptr and head == nullptr){
        return head;
    }
    // Recursive leap of faith
    Node *rest = reverseR(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

int main() {
    Node *head = nullptr;
    addAtEnd(&head, 20);
    addAtEnd(&head, 30);
    addAtEnd(&head, 40);
    addAtEnd(&head, 50);
    addAtEnd(&head, 60);
    printLL(head);
    reverseLL(&head);
    printLL(head);

//    int k = 8;
//    int *kPtr = &k;
//    cout<<"Pointer: "<<kPtr <<endl;
//    cout<<"Pointer's Address: "<< &kPtr<<endl;
//
//    addAtEnd2(kPtr);

//    cout<<k<<endl;
//    cout<<&k<<endl;
//    cout<<kPtr<<endl;
//    cout<<*kPtr<<endl;

    return 0;
}