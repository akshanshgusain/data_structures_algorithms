//
// Created by Akshansh Gusain on 28/09/21.
//
#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void addAtEnd(Node** head, int data) {
    Node *node = new Node(data);
    Node *last = *head;

    if (*head == nullptr) {
        *head = node;
        return;
    }
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = node;
}

void printLL(Node *start) {
    while (start != nullptr) {
        cout << start->data << " ";
        start = start->next;
    }
    cout << endl;
}

// Iterative
void reverseLL(Node** head) {
    Node *previous, *next, *current;
    current = *head;
    previous = next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = previous; // reverse the ptr
        previous = current; // forward prev ptr
        current = next; // forward curr ptr
    }

    *head = previous;
}

Node* reverseR(Node* &head){

    if(head == nullptr or head->next == nullptr){
        return head;
    }

    Node *rest = reverseR(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

int main() {
    Node* head = nullptr;
    addAtEnd(&head, 20);
    addAtEnd(&head, 30);
    addAtEnd(&head, 40);
    addAtEnd(&head, 50);

    printLL(head);
//    Node *newHead = reverseR(head);
//    printLL(newHead);
    reverseLL(&head);
    printLL(head);

    return 0;
}
