//
// Created by Akshansh Gusain on 24/01/24.
//

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    char val;
    ListNode *next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    explicit ListNode(char x) {
        val = x;
        next = nullptr;
    }

    ListNode(char x, ListNode *next) {
        val = x;
        this->next = next;
    }
};

void push(ListNode *&head, char data) {
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

ListNode *reverseList(ListNode* &head){
    if(head == nullptr or head->next == nullptr){
        return head;
    }

    ListNode *prev = nullptr, *curr = head, *next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 1. Find the middle of the linked list using Floyd's Tortoise and Hare algorithm.
// 2. Reverse the second half of the linked list.
// 3. Compare the first half and the reversed second half to check for symmetry.
bool isPalindrome(ListNode *&head) {
    if (head == nullptr or head->next == nullptr) {
        return true;
    }

    // find the middle of the list
    ListNode *slow = head, *fast = head->next;
    while (fast != nullptr and fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse the second half
    ListNode *secondHalf = reverseList(slow);


    // compare the first and the reversed second half
    ListNode *firstHalf = head;

    while(secondHalf != nullptr){
        if(firstHalf->val != secondHalf->val){
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}


int main() {
    string ip = "abacaba";

    ListNode *head = nullptr;

    for (char i: ip) {
        push(head, i);
    }

    printList(head);
    isPalindrome(head) ? cout << "Palindrome" : cout << "Not a Palindrome";
    cout << endl;


    return 0;
}