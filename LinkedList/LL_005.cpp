//
// Created by Akshansh Gusain on 14/10/21.
//
//https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
#include<stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    explicit Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void push(Node* &head, int key)
{
    Node* temp = new Node(key);
    temp->next = head;
    head = temp;
}

// A utility function to print a linked list
void printList(Node* head)
{
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* detectStartOfLoop(Node* head){
    if(head == nullptr or head->next == nullptr){
        return nullptr;
    }

    Node *slow= head, *fast = head;

    while( slow and fast and fast->next){
       slow = slow->next;
       fast = fast->next->next;
       if(slow == fast){
           break;
       }
    }

    if (slow != fast)
        return nullptr;

    // If loop exists. Start slow from
    // head and fast from meeting point.
    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


int main(){

    Node* head = nullptr;
    push(head,50);
    push(head,20);
    push(head,15);
    push(head,04);
    push(head,10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    Node* res = detectStartOfLoop(head);
    if (res == nullptr)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->data; //Loop starting node is 15

    return 0;
}
