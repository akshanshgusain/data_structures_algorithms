//
// Created by Akshansh Gusain on 21/10/21.
//
#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next, *random;

    explicit Node(int key) {
        data = key;
        next = nullptr;
        random = nullptr;
    }
};

void push(Node *&head, int value) {
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;
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

void printWRandom(Node *node) {
    while (node != nullptr) {
        Node *random = node->random;
        int randomData = (random != nullptr) ? random->data : -1;
        cout << "N: " << node->data << ", ";
        cout << "Random: " << randomData << "\n";
        node = node->next;
    }
    cout << endl;
}

Node *clone(Node *head) {
    Node *curr = head;
    Node *temp = nullptr;

    //Insert additional node after every node of original list
    while (curr != nullptr) {
        temp = curr->next;

        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = head;

    while (curr != nullptr) {
        if (curr->next != nullptr) {
            curr->next->random = curr->random ? curr->random->next : curr->random;
            curr = curr->next ? curr->next->next : curr->next;
        }
    }
    Node *original = head, *copy = head->next;
    temp = copy;

    while (original != nullptr and copy != nullptr){
        original->next = original->next? original->next->next: original->next;

        copy->next = copy->next?copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return temp;
}


int main() {
    Node *head = nullptr;
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);

    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next->next->next->next;
    head->next->next->next->next->random = head->next;
    cout << "Original linked list\n";
    print(head);
    printWRandom(head);

    Node *clonedList = clone(head);
    cout << "Cloned linked list\n";
    print(clonedList);
    printWRandom(clonedList);


    return 0;
}

/*
Original linked list
1->2->3->4->5
N: 1, Random: 3
N: 2, Random: 4
N: 3, Random: 5
N: 4, Random: -1
N: 5, Random: 2

Cloned linked list
1->2->3->4->5
N: 1, Random: 3
N: 2, Random: 4
N: 3, Random: 5
N: 4, Random: -1
N: 5, Random: 2


 */