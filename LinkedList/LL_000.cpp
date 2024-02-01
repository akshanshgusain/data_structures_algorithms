//
// Created by Akshansh Gusain on 17/01/24.
//

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    explicit ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode *next) {
        val = x;
        this->next = next;
    }
};

void push(ListNode *&head, int data) {
    auto *newNode = new ListNode();
    newNode->val = data;
    newNode->next = head;
    head = newNode;
}

void printList(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}

void makeCircular(ListNode* &head){
    // Make the list circular (connect the last node to the second node)
    ListNode *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head;
}

void printCircularList(ListNode *head) {
    ListNode *temp = head;

    // If linked list is not empty
    if (head != nullptr) {

        // Print nodes till we reach first node again
        do {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);
    }
}