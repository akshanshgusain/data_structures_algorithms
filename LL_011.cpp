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

Node* findIntersection(Node* head1, Node* head2){
    Node* intersection = nullptr;

    while(head1!= nullptr and head2!=nullptr){
        if(head1->data == head2->data){
            push(intersection, head1->data);
            head2 = head2->next;
            head1 = head1->next;
        }else if(head1->data > head2->data){
            head2 = head2->next;
        }else{
            head1 = head1->next;
        }
    }

    return intersection;
}

int main(){
    Node *head1 = nullptr, *head2 = nullptr;

    push(head1, 8);
    push(head1, 6);
    push(head1, 6);
    push(head1, 4);
    push(head1, 2);
    push(head1, 1);

    push(head2, 6);
    push(head2, 4);
    push(head2, 2);
    push(head2, 0);

    Node *intersection = findIntersection(head1, head2);
    print(intersection);
}