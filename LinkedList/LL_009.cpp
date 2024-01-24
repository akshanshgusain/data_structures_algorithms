//
// Created by Akshansh Gusain on 14/10/21.
//
/*
The main focus in this question is on the digit 9 which creates all the changes otherwise for other digits we have
 to just increment their value by 1 but if we change the node’s value with the value 9 it makes a carry which then
 has to be passed through the linked list.

// Find the last node in the linked list which is not equal to 9. Now there are three cases:

1. If there is no such node i.e. the value of every node is 9 then the new linked list will contain all 0s and a single
1 inserted at the head of the linked list.

2. If the rightmost node which is not equal to 9 is the last node in the linked list then add 1 to this node and return
 the head of the linked list.

3. If the node is other than the last node i.e. every node after it is equal to 9 then add 1 to the current node and
 change all the nodes after it to 0.*/

#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    explicit Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void push(Node *&head, int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void print(Node *node) {
    while (node != nullptr) {
        if (node->next != nullptr) {
            cout << node->data << "->";
        } else {
            cout << node->data;
        }

        node = node->next;
    }
    cout << endl;
}

Node *addOne(Node *&head) {

    /// Store the last node which is not 9
    Node *last = nullptr;
    Node *cur = head;

    while (cur->next != nullptr) {
        if (cur->data != 9) {
            last = cur;
        }
        cur = cur->next;
    }

    ///If last node is not 9, simply add 1 to it and return
    if (cur->data != 9) {
        cur->data++;
        return head;
    }

    ///IF last == null, that means we did not find and element with is not 9
    if (last == nullptr) {
        last = new Node(0);
        last->next = head;
        head = last;
    }

    // For cases when the rightmost node which is not equal to 9 is not the last node in the linked list
    last->data++;
    last = last->next;

    while (last != nullptr) {
        last->data = 0;
        last = last->next;
    }

    return head;
}

int main() {
    Node *head = nullptr;

    push(head, 9);
    push(head, 9);
    push(head, 9);
    push(head, 9);

    cout << "Original list is : ";
    print(head);

    head = addOne(head);

    cout << "Resultant list is : ";
    print(head);

    return 0;
}