//
// Created by Akshansh Gusain on 07/03/21.
//
#include<stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next, *prev;
};

Node* getNode(int data)
{
    // allocate space
    Node* new_node = (Node*)malloc(sizeof(Node));

    // put in the data
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

void push(Node** head_ref, Node* new_node)
{
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    // move the head to point to the new node
    (*head_ref) = new_node;
}

void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
Node* revListInGroupOfGivenSize(Node* head, int k){
    Node *current = head;
    Node* next = nullptr;
    Node* newHead = nullptr;
    int count = 0;

    while(current != nullptr && count<k){
        next = current->next;
        push(&newHead, current);
        current = next;
        count++;
    }

    if(next != nullptr){
        head->next = revListInGroupOfGivenSize(next, k);
        head->next->prev = head;
    }
    return newHead;
}


int main(){
    Node* head = NULL;

    // Create doubly linked: 10<->8<->4<->2
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));

    int k = 2;

    cout << "Original list: ";
    printList(head);

    head = revListInGroupOfGivenSize(head, k);

    cout << "\nModified list: ";
    printList(head);

    return 0;
}

