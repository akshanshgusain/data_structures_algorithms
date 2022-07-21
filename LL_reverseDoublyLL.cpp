//
// Created by Akshansh Gusain on 05/03/21.
//Here is a simple method for reversing a Doubly Linked List. All we need to do is swap prev and next pointers for all
// nodes, change prev of the head (or start) and change the head pointer in the end.

#include<stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
};

void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* since we are adding at the beginning,
    prev is always NULL */
    new_node->prev = NULL;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* change prev of head node to new node */
    if((*head_ref) != NULL)
        (*head_ref)->prev = new_node ;

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print nodes in a given doubly linked list
This function is same as printList() of singly linked list */
void printList(Node *node)
{
    while(node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
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
    Node* head = NULL;

    /* Let us create a sorted linked list to test the functions
    Created linked list will be 10->8->4->2 */
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    cout << "Original Linked list" << endl;
    printList(head);

    /* Reverse doubly linked list */
    reverse(&head);

    cout << "\nReversed Linked list" << endl;
    printList(head);


    return 0;
}
