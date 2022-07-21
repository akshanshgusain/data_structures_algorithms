//
// Created by Akshansh Gusain on 05/03/21.
//
#include<stdc++.h>
using namespace std;

class Node{
public:
    Node* next;
    int data;
};

Node* push(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

bool isCircular(Node *head){
    // An empty linked list is circular
    if (head == NULL)
        return true;

    // Next of head
    Node *node = head->next;

    // This loop would stop in both cases (1) If
    // Circular (2) Not circular
    while (node != nullptr && node != head)
        node = node->next;

    // If loop stopped because of circular
    // condition
    return (node == head);
}

int main(){
    Node* head = nullptr;
    head = push(1);
    head->next = push(2);
    head->next->next = push(3);
    head->next->next->next = push(4);

    //printList(head);
    isCircular(head)? cout << "Yes\n" :
    cout << "No\n" ;

    head->next->next->next->next = head;

    isCircular(head)? cout << "Yes\n" :
    cout << "No\n" ;
    return 0;
}
