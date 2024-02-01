//
// Created by Akshansh Gusain on 16/01/24.
//
#include "LL_000.cpp"

ListNode* reverseIter(ListNode* &head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* reverseRecur(ListNode* &head){
    if(head == nullptr or head->next == nullptr){
        return head;
    }

    // reverse the remaining list
    ListNode* restReversed = reverseRecur(head->next);

    // adjust the pointers to reverse the current node
    head->next->next = head;
    head->next = nullptr;

    return restReversed;
}

int main() {
    ListNode *head = nullptr;
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

    auto *node2 = reverseRecur(head);
    cout<<endl;

    printList(node2);
    return 0;
}