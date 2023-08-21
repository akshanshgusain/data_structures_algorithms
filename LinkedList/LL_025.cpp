//
// Created by Akshansh Gusain on 18/10/21.
//

#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;

    explicit Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

void push(Node *&head, int new_data) {
    Node *newNode = new Node(new_data);
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void pushNode(Node* &head, Node *new_node){
    new_node->prev = nullptr;
    new_node->next = head;

    if (head != nullptr)
        head->prev = new_node;
    head = new_node;
}

void printList(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *revListInGroupOfGivenSize(Node *head, int k) {
    Node *current = head, *next = nullptr, *newHead= nullptr;
    int count = 0;

    while(current != nullptr and count < k){
        next = current->next;
        pushNode(newHead, current);
        current = next;
        count++;
    }
    if(next != nullptr){
        head->next = revListInGroupOfGivenSize(next, k);
        head->next->prev = head;
    }
    return newHead;
}

int main() {
    Node *head = nullptr;
    push(head, 2);
    push(head, 4);
    push(head, 8);
    push(head, 1);
    int k = 2;

    cout << "Original list: ";
    printList(head);

    head = revListInGroupOfGivenSize(head, k);

    cout << "\nModified list: ";
    printList(head);

    return 0;
}