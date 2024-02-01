//
// Created by Akshansh Gusain on 24/01/24.
//
#include "LL_000.cpp"

ListNode *findMiddleElement(ListNode *&head) {
    ListNode *slow = head, *fast = head->next;

    while (fast != nullptr and fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main() {
    ListNode *head = nullptr;

    push(head, 15);
    push(head, 10);
    push(head, 5);
    push(head, 20);
    push(head, 23);
    push(head, 3);
    push(head, 2);
    push(head, 2);

    printList(head);

    cout << "Middle Element: " << findMiddleElement(head)->val;
    return 0;
}