//
// Created by Akshansh Gusain on 17/01/24.
//
#include "LL_000.cpp"

ListNode* reverseInGroup(ListNode* &head, int groupSize){
    if(head == nullptr){
        return nullptr;
    }

    // 1. reverse first k nodes
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    int count = 0;
    while(curr != nullptr and count < groupSize){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // 2. recursively call for rest of the list
    if(next != nullptr){ // remaining list is not null
        head->next = reverseInGroup(next, groupSize);
    }

    // prev is the new head of the list
    return prev;
}

int main() {
    ListNode* head = nullptr;
    push(head, 9);
    push(head, 8);
    push(head, 7);
    push(head, 6);
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);
    printList(head);

    auto* node2 = reverseInGroup(head, 3);
    cout<<endl;

    printList(node2);
    return 0;
}