//
// Created by Akshansh Gusain on 18/10/21.
//

#include<stdc++.h>

using namespace std;

struct Node {
public:
    char data;
    struct Node *prev;
    struct Node *next;
};

void push(Node *&head, int new_data) {
    Node *newNode = new Node;
    newNode->data = new_data;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}

/* Function to print linked list */
void printList(Node *node) {
    while (node->next != nullptr) {
        cout << node->data << " "
             << "<=>"
             << " ";
        node = node->next;
    }
    cout << node->data;
}

void rotate(Node* &head, int n) {
    if (n == 0){
        return;
    }
    Node *current = head;

    int count = 1;
    while (count < n && current != nullptr) {
        current = current->next;
        count++;
    }
    if (current == nullptr) {
        return;
    }
    struct Node *nthNode = current;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = head;
    head->prev = current;
    head = nthNode->next;
    head->prev = nullptr;
    nthNode->next = nullptr;

}

int main() {
    /* Start with the empty list */
    struct Node *head = nullptr;

    /* Let us create the doubly
      linked list a<->b<->c<->d<->e */
    push(head, 'e');
    push(head, 'd');
    push(head, 'c');
    push(head, 'b');
    push(head, 'a');

    int N = 2;

    cout << "Given linked list \n";
    printList(head);
    rotate(head, N);

    cout << "\nRotated Linked list \n";
    printList(head);

    return 0;
}


