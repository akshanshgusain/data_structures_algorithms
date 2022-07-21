//
// Created by Akshansh Gusain on 07/03/21.
//
//Using min heap;
#include<stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node =
            (struct Node*)malloc(sizeof(struct Node));

    // put in the data
    new_node->data = new_data;

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

// Function to print nodes in a given doubly linked list
void printList(struct Node* head)
{
    // if list is empty
    if (head == nullptr)
        cout << "Doubly Linked list empty";

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
struct compare {
    bool operator()(struct Node* p1, struct Node* p2)
    {
        return p1->data > p2->data;
    }
};

struct Node* sortAKSortedDLL(struct Node* head, int k){

    if(head == nullptr){
        return head;
    }
    //priority queue implemented as min heap with the help of 'compare' function
    priority_queue<Node*, vector<Node*>, compare> pq;

    struct Node* newHead = nullptr, *last;

    //create min heap of the first k+1 elements
    for(int i= 0; head != nullptr && i<= k; i++){
        pq.push(head);
        head = head->next;
    }
    //loop till pk is empty
    while(!pq.empty()){
        if(newHead == nullptr){
            newHead = pq.top();
            newHead->prev = nullptr;
            last = newHead;
        }
        else{
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
        pq.pop();

        // if there are more nodes left in the input list
        if(head != nullptr){
            pq.push(head);
            head = head->next;
        }
    }

    last->next = nullptr;
    return newHead;
}



int main(){

    struct Node* head = NULL;

    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);

    int k = 2;

    cout << "Original Doubly linked list:n";
    printList(head);

    head = sortAKSortedDLL(head, k);

    cout << "\nDoubly linked list after sorting:n";
    printList(head);

    return 0;
}

