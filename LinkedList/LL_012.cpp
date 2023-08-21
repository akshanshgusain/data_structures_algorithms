//
// Created by Akshansh Gusain on 15/10/21.
//

#include<stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    explicit Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

void push(Node *&head, int val) {
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void reverseLL(Node* &head) {
    Node *previous, *next, *current;
    current = head;
    previous = next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;
}

void print(Node *node) {
    while (node != nullptr) {
        cout << node->data;
        if (node->next != nullptr) {
            cout << "->";
        }
        node = node->next;
    }
    cout << endl;
}

int getCount(Node *head) {
    Node *current = head;
    int count = 0;

    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

int _getIntersectionNode(int d, Node *head1, Node *head2) {
    Node *current1 = head1;
    Node *current2 = head2;

    for (int i = 0; i < d; i++) {
        if (current1 == nullptr) {
            return -34;
        }
        current1 = current1->next;
    }

    while (current1 != NULL && current2 != NULL) {

        if (current1->data == current2->data) {
            return current1->data;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return -35;
}

int getIntersectionNode(Node* head1, Node* head2)
{
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d = 0;

    if (c1 > c2) {
        d = c1 - c2;
        return _getIntersectionNode(d, head1, head2);
    }
    else {
        d = c2 - c1;
        return _getIntersectionNode(d, head2, head1);
    }
}

int main(){
    Node *head1 = nullptr, *head2 = nullptr;


    push(head1, 750);
    push(head1, 14);
    push(head1, 8);
    push(head1, 15);
    push(head1, 30);
    push(head1, 2);


    push(head2, 750);
    push(head2, 14);
    push(head2, 8);
    push(head2, 2);
    push(head2, 6);

    cout<<getIntersectionNode(head1, head2);
    return 0;
}