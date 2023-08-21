//
// Created by Akshansh Gusain on 29/09/21.
//
#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    explicit Node(int val) {
        this->data = val;
        this->next = nullptr;
    }
};

Node* reverse(Node *head, int k){
    if(!head){
        return nullptr;
    }

    Node* current = head;
    Node* next = nullptr;
    Node* prev = nullptr;
    int count = 0;

    /*reverse first k nodes of the linked list */
    while(count < k and current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count ++;
    }

    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if(next!= nullptr){
        head->next = reverse(next , k);
    }

    /* prev is new head of the input list */
    return prev;
}

void push(Node* &head_ref, int new_data) {
    Node *new_node = new Node(new_data);
    new_node->next = (head_ref);
    head_ref = new_node;
}


void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node *head = nullptr;
    push(head, 9);
    push(head, 8);
    push(head, 7);
    push(head, 6);
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);

    printList(head);

    Node *node2 = reverse(head, 3);
    cout<<endl;

    printList(node2);

    return 0;
}
