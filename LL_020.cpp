//
// Created by Akshansh Gusain on 18/10/21.
//
#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    explicit Node(int key) {
        data = key;
        next = nullptr;
        prev = nullptr;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

void push(Node *&head, int key) {
    Node *newNode = new Node(key);
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}

Node* reverseList(Node *head) {
    Node *temp = nullptr;

    while (head != nullptr) {

        temp = head->prev;
        head->prev = head->next;
        head->next = temp;

        head = head->next;
    }
    if (temp != nullptr)
        return temp->prev;
    else {
        cout<<"NULL";
        return nullptr;
    }
}

void reverse(Node **head_ref)
{
    Node *temp = NULL;
    Node *current = *head_ref;

    /* swap next and prev for all nodes of
    doubly linked list */
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    /* Before changing the head, check for the cases like empty
        list and list with only one node */
    if(temp != NULL )
        *head_ref = temp->prev;
}

int main() {
    Node *head = nullptr;
    push(head, 2);
    push(head, 4);
    push(head, 8);
    push(head, 10);

    cout << "Original Linked list" << endl;
    printList(head);

    /* Reverse doubly linked list */
    Node *rNode = reverseList(head);
    reverse(&head);

    cout << "\nReversed Linked list" << endl;
    printList(head);
    return 0;
}
