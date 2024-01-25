//
// Created by Akshansh Gusain on 25/01/24.
//
#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode *prev;

    explicit ListNode(int key) {
        val = key;
        next = nullptr;
        prev = nullptr;
    }
};

void printList(ListNode *node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
}

void push(ListNode *&head, int key) {
    auto *newNode = new ListNode(key);
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}