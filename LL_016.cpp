//
// Created by Akshansh Gusain on 16/10/21.
//
#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    explicit Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

void push(Node *&head_ref, int data) {
    Node *ptr1 = new Node(data);
    Node *temp = head_ref;
    ptr1->next = head_ref;

    if (head_ref != nullptr) {
        while (temp->next != head_ref) {
            temp = temp->next;
        }
        temp->next = ptr1;
    } else
        ptr1->next = ptr1;

    head_ref = ptr1;
}


void print(Node *head) {
    Node *temp = head;
    if (head != nullptr) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}

bool isCircular(Node *&head) {
    // An empty linked list is circular
    if (head == nullptr)
        return true;

    // Next of head
    Node *node = head->next;

    // This loop would stop in both cases (1) If
    // Circular (2) Not circular
    while (node != nullptr && node != head)
        node = node->next;

    // If loop stopped because of circular
    // condition
    return (node == head);
}

int main() {

    Node *head = nullptr;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);

    print(head);
    isCircular(head)? cout<<endl<<"YES"<<endl : cout<<endl<<"NO"<<endl;
    return 0;
}