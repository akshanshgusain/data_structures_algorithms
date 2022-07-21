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

void pairSum(Node *head, int x) {
    // Set two pointers, first to the beginning of DLL
    // and second to the end of DLL.
    Node *first = head;
    Node *second = head;
    while (second->next != nullptr){
        second = second->next;
    }
    // To track if we find a pair or not
    bool found = false;

    // The loop terminates when either of two pointers
    // become NULL, or they cross each other (second->next
    // == first), or they become same (first == second)
    while (first != nullptr && second != nullptr &&
           first != second && second->next != first) {
        // pair found
        if ((first->data + second->data) == x) {
            found = true;
            cout << "(" << first->data << ", "
                 << second->data << ")" << endl;

            // move first in forward direction
            first = first->next;

            // move second in backward direction
            second = second->prev;
        } else {
            if ((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }

    // if pair is not present
    if (!found)
        cout << "No pair found";
}

int main() {
    Node *head = nullptr;
    push(head, 9);
    push(head, 8);
    push(head, 6);
    push(head, 5);
    push(head, 4);
    push(head, 2);
    push(head, 1);
    int x = 7;

    pairSum(head, 7);
    return 0;
}
