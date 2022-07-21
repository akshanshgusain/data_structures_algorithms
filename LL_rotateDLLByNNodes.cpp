//
// Created by Akshansh Gusain on 07/03/21.
//
#include<stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =  new Node;
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

/* Function to print linked list */
void printList(struct Node* node)
{
    while (node->next != NULL) {
        cout << node->data << " "
             << "<=>"
             << " ";
        node = node->next;
    }
    cout << node->data;
}

void rotate(struct Node** head, int n){
       if(n==0)
           return;
       struct Node* current = *head;

       int count = 1;
       while(count < n && current != nullptr){
           current = current->next;
           count++;
       }
       if(current == nullptr){
           return;
       }
       struct Node* nthNode = current;
       while(current->next !=nullptr){
           current = current->next;
       }

       current->next = *head;
    (*head)->prev = current;
    *head = nthNode->next;
    (*head)->prev = nullptr;
    nthNode->next = nullptr;

}
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    /* Let us create the doubly
      linked list a<->b<->c<->d<->e */
    push(&head, 'e');
    push(&head, 'd');
    push(&head, 'c');
    push(&head, 'b');
    push(&head, 'a');

    int N = 2;

    cout << "Given linked list \n";
    printList(head);
    rotate(&head, N);

    cout << "\nRotated Linked list \n";
    printList(head);

    return 0;
}

