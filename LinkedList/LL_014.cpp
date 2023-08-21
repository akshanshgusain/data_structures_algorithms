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

Node *getTail(Node *currHead) {
    while (currHead != nullptr and currHead->next != nullptr) {
            currHead = currHead->next;
    }
    return currHead;
}

Node* partition(Node* head, Node* end, Node* &newHead, Node* &newTail){
    Node* pivot = end;
    Node *prev = nullptr, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list
    // might change which is updated in the newHead and
    // newEnd variables
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the
            // pivot - becomes the new head
            if ((newHead) == nullptr)
                (newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change
            // tail
            if (prev)
                prev->next = cur->next;
            struct Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the
    // current list, pivot becomes the head
    if (newHead == nullptr)
        newHead = pivot;

    // Update newEnd to the current last node
    newTail = tail;

    // Return the pivot node
    return pivot;
}

Node* quickSort_(Node* head, Node* tail){
    if(!head or head == tail){
        return head;
    }
    Node *newHead = nullptr, *newTail = nullptr;

    // Partition the list, newHead and newEnd will be updated by the partition function
    Node *pivot = partition(head , tail, newHead, newTail);

    // If pivot is the smallest element - no need to recur for the left part.
    if(newHead != pivot){
        Node *temp = newHead;
        while(temp->next != pivot){
            temp = temp->next;
        }
        // Recur for the list before pivot
        newHead = quickSort_(newHead, temp);

        // Change next of last node of the left half to pivot
        temp = getTail(newHead);
        temp->next = pivot;
    }

    // Recur for the list after the pivot element
    pivot->next = quickSort_(pivot->next, newTail);
}

void quickSort(Node *&head) {
    head = quickSort_(head, getTail(head));
}

int main() {
    Node *head = nullptr;
    push(head, 5);
    push(head, 20);
    push(head, 4);
    push(head, 3);
    push(head, 30);

    cout << "Linked List before sorting \n";
    print(head);

    quickSort(head);

    cout << "Linked List after sorting \n";
    print(head);

    return 0;
}