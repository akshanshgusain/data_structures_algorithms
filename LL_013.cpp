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

void FrontBackSplit(Node *head, Node *&frontRef, Node *&bacRef) {
    Node *slow = head, *fast = head->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    frontRef = head;
    bacRef = slow->next;
    slow->next = nullptr; //break the list

}


Node* SortedMerge(Node* a, Node* b){
    Node* newList = nullptr;

    if(a == nullptr){
        return b;
    }else if(b == nullptr){
        return a;
    }

    if(a->data <= b->data){
        newList = a;
        newList->next = SortedMerge(a->next, b);
    }else{
        newList = b;
        newList->next = SortedMerge(a, b->next);
    }

    return newList;
}

void MergeSort(Node *&head) {

    if (head == nullptr or head->next == nullptr) {
        return;
    }
    Node *a = nullptr, *b = nullptr;

    // Split the List into 2 halves
    FrontBackSplit(head, a, b);

    MergeSort(a);
    MergeSort(b);

    head = SortedMerge(a, b);
}


int main() {
    Node *head = nullptr;

    push(head, 15);
    push(head, 10);
    push(head, 5);
    push(head, 20);
    push(head, 3);
    push(head, 2);

    print(head);

    MergeSort(head);

    cout << "Sorted Linked List is: \n";
    print(head);
    return 0;
}
