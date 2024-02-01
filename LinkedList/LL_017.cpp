//
// Created by Akshansh Gusain on 24/01/24.
//
#include "LL_000.cpp"

bool isCircular(ListNode *&head) {
    if (!head || !head->next) {
        return false; // An empty list or a list with only one node is not circular
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast) {
            return true; // Meeting point found, the list is circular
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}

int main() {
    ListNode *head = nullptr;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);

    // Make the list circular (connect the last node to the second node)
    makeCircular(head);

    printCircularList(head);

    isCircular(head) ? cout << endl << "YES" << endl : cout << endl << "NO" << endl;
    return 0;
}