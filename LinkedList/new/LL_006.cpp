//
// Created by Akshansh Gusain on 17/01/24.
//
#include "LL_000.cpp"


ListNode *detectStartOfLoop(ListNode *&head) {
    // detect loop
    if (head == nullptr) {
        return nullptr;
    }
    ListNode *slow = head, *fast = head;

    while (fast->next != nullptr and fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            break;
        }
    }

    // 2. If loop exist,
    // start slow from head and fast from meeting point
    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


int main() {
    ListNode *head = nullptr;
    push(head, 50);
    push(head, 20);
    push(head, 15);
    push(head, 04);
    push(head, 10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    ListNode *res = detectStartOfLoop(head);
    if (res == nullptr)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->val;
    return 0;
}

