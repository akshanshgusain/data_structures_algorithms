//
// Created by Akshansh Gusain on 04/03/21.
//
/*
The main focus in this question is on the digit 9 which creates all the changes otherwise for other digits we have
 to just increment their value by 1 but if we change the node’s value with the value 9 it makes a carry which then
 has to be passed through the linked list.
Find the last node in the linked list which is not equal to 9. Now there are three cases:

If there is no such node i.e. the value of every node is 9 then the new linked list will contain all 0s and a single
 1 inserted at the head of the linked list.
If the rightmost node which is not equal to 9 is the last node in the linked list then add 1 to this node and return
 the head of the linked list.
If the node is other than the last node i.e. every node after it is equal to 9 then add 1 to the current node and
 change all the nodes after it to 0.*/

#include <stdc++.h>

using namespace std;

/* Linked list node */
class Node {
public:
    int data;
    Node *next;
};

// Function to create a new node
Node *create_Node(int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to print the linked list
void print(Node *head) {

    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//Function to add one to anumber
// represented as linked list
Node* addOne(Node *head) {

// To store the last node in the linked
// list which is not equal to 9
    Node *last = NULL;
    Node *cur = head;

// Iterate till the last node
    while (cur->next != NULL) {

        if (cur->data != 9) {
            last = cur;
        }
        cur = cur->next;
    }

// If last node is not equal to 9
// add 1 to it and return the head
    if (cur->data != 9) {
        cur->data++;
        return
                head;
    }

// If list is of the type 9 -> 9 -> 9 ...
    if (last == NULL) {
        last = new Node();
        last->
                data = 0;
        last->
                next = head;
        head = last;
    }

// For cases when the righmost node which
// is not equal to 9 is not the last
// node in the linked list
    last->data++;
    last = last->next;

    while (last != NULL) {
        last->
                data = 0;
        last = last->next;
    }

    return
            head;
}


/* Driver program to test above function */
int main(void) {
    Node *head = create_Node(1);
    head->next = create_Node(2);
    head->next->next = create_Node(9);
    head->next->next->next = create_Node(9);

    cout << "Original list is : ";
    print(head);

    head = addOne(head);

    cout << "Resultant list is : ";
    print(head);

    return 0;
} 