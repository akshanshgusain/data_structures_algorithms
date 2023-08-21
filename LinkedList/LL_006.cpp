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
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    Node *currentHead = head;

    while(currentHead->next != nullptr){
        if(currentHead->data == currentHead->next->data){
            currentHead->next = currentHead->next->next;
        }else{
            currentHead = currentHead->next;
        }
    }
    return head;
}

int main(){
    Node *head = nullptr;
    push(head, 5);
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 3);
    push(head, 2);
    push(head, 1);

    print(head);

    Node* newNode = deleteDuplicates(head);
    print(newNode);

    return 0;
}