//
// Created by Akshansh Gusain on 18/10/21.
//

#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    explicit Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

void push(Node* &head_ref, int new_data) {
    // allocate node
    Node* newNode = new Node(new_data);
    newNode->data = new_data;
    newNode->prev = nullptr;
    newNode->next = head_ref;

    if (head_ref != nullptr){
        head_ref->prev = newNode;
    }

    head_ref = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(Node *head) {
    // if list is empty
    if (head == nullptr)
        cout << "Doubly Linked list empty";

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

struct compare {
    bool operator()(struct Node *p1, struct Node *p2) {
        return p1->data > p2->data;
    }
};

Node* sortKSortedDLL(Node *head, int k) {
    if(head == nullptr){
        return head;
    }

    // min Heap
    priority_queue<Node*, vector<Node*>, compare> pq;
    Node* newHead = nullptr, *last = nullptr;

    //create min heap of the first k+1 elements
    for(int i= 0; head != nullptr && i<= k; i++){
        pq.push(head);
        head = head->next;
    }

    while(!pq.empty()){
        if(newHead == nullptr){
            newHead = pq.top();
            newHead->prev = nullptr;
            last = newHead;
        }
        else{
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
        pq.pop();

        // if there are more nodes left in the input list
        if(head != nullptr){
            pq.push(head);
            head = head->next;
        }
    }
    last->next = nullptr;
    return newHead;
}


int main() {

    struct Node *head = nullptr;

    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    push(head, 8);
    push(head, 56);
    push(head, 12);
    push(head, 2);
    push(head, 6);
    push(head, 3);

    int k = 2;

    cout << "Original Doubly linked list:\n";
    printList(head);

    head = sortKSortedDLL(head, k);

    cout << "\nDoubly linked list after sorting:\n";
    printList(head);
    // 2<->3<->6<->8<->12<->56
    return 0;
}

