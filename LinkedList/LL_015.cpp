//
// Created by Akshansh Gusain on 16/10/21.
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

int findMiddleElement(Node* &head){
    Node* slow = head, *fast = head->next;
    while(fast!= nullptr){
        fast = fast->next;
        if(fast!= nullptr){
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow->data;
}

int main(){
    Node *head = nullptr;

    push(head, 15);
    push(head, 10);
    push(head, 5);
    push(head, 20);
    push(head, 23);
    push(head, 3);
    push(head, 2);

    print(head);

    cout<<"Middle Element: "<< findMiddleElement(head);
    return 0;
}