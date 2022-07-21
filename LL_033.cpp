//
// Created by Akshansh Gusain on 21/10/21.
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

void reverseList(Node* &head){
    Node *curr = head, *prev = nullptr, *next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void _deleteLesserNodes(Node* &head){
    Node* current = head, *maxSoFar = head, *temp = nullptr;
    while(current != nullptr and current->next != nullptr){
        if(current->next->data < maxSoFar->data){
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }else{
            current = current->next;
            maxSoFar = current;
        }
    }

}

void deleteLesserNodes(Node* &head){
    reverseList(head);
    _deleteLesserNodes(head);
    reverseList(head);
}





int main(){
    Node *head = nullptr;

    /* Create following linked list
    12->15->10->11->5->6->2->3 */
    push(head, 3);
    push(head, 2);
    push(head, 6);
    push(head, 5);
    push(head, 11);
    push(head, 10);
    push(head, 15);
    push(head, 12);

    cout << "Given Linked List \n";
    print(head);

    deleteLesserNodes(head);

    cout << "Modified Linked List \n";
    print(head);
    return 0;
}