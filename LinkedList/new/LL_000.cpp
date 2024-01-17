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