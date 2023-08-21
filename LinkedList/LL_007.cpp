//
// Created by Akshansh Gusain on 14/10/21.
//
#include<stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    explicit Node(int data){
        this->data = data;
        next = nullptr;
    }
};


void push(Node* &head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

void print(Node* node){
    while(node != nullptr){
        cout<<node->data<<" ->";
        node = node->next;
    }
    cout<<endl;
}

Node* deleteDuplicates(Node* head){
    // Hash to store seen values
    unordered_set<int> seen;

    /* Pick elements one by one */
    Node *curr = head, *newHead = head;
    Node *prev = nullptr;
    while (curr != nullptr)
    {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }

    return newHead;
}

int main(){
    /* The constructed linked list is:
    10->12->11->11->12->11->10*/

    Node *head = nullptr;
    push(head, 10);
    push(head, 11);
    push(head, 12);
    push(head, 11);
    push(head, 11);
    push(head, 12);
    push(head, 10);

    print(head);

    Node* newNode = deleteDuplicates(head);
    print(newNode);

    return 0;
}
