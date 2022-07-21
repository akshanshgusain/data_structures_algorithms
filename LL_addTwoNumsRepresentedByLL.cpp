//
// Created by Akshansh Gusain on 04/03/21.
//
#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};


Node *newNode(int data) {
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node *addTwoLists(Node *first, Node *second) {
    // res is head node of the resultant list
    Node *res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;

    // while both lists exist
    while (first != NULL || second != NULL) {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // (i) Carry
        // (ii) Next digit of first
        // list (if there is a next digit)
        // (ii) Next digit of second
        // list (if there is a next digit)
        sum = carry + (first ? first->data : 0)
              + (second ? second->data : 0);

        // update carry for next calculation
        carry = (sum >= 10) ? 1 : 0;

        // update sum if it is greater than 10
        sum = sum % 10;

        // Create a new node with sum as data
        temp = newNode(sum);

        // if this is the first node then
        // set it as head of the resultant list
        if (res == NULL)
            res = temp;

            // If this is not the first
            // node then connect it to the rest.
        else
            prev->next = temp;

        // Set prev for next insertion
        prev = temp;

        // Move first and second
        // pointers to next nodes
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }

    if (carry > 0)
        temp->next = newNode(carry);

    // return head of the resultant list
    return res;
}

void push(Node **head_ref, int new_data) {
    Node *new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node *res = NULL;
    Node *first = NULL;
    Node *second = NULL;

    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);

    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    cout << "Second List is ";
    printList(second);

    // Add the two lists and see result
    res = addTwoLists(first, second);
    cout << "Resultant list is ";
    printList(res);

    return 0;
}
