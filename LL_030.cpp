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

Node *clone(Node *&head) {
    Node *originalCurrent = head;
    Node *cloneCurrent = nullptr;

    unordered_map<Node *, Node *> map;

    while (originalCurrent != nullptr) {
        cloneCurrent = new Node(originalCurrent->data);
        map[originalCurrent] = cloneCurrent;
        originalCurrent = originalCurrent->next;
    }
    originalCurrent = head;

    while (originalCurrent != nullptr) {
        cloneCurrent = map[originalCurrent];
        cloneCurrent->next = map[originalCurrent->next];
        cloneCurrent->random = map[originalCurrent->random];
        originalCurrent = originalCurrent->next;
    }

    return map[head];
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