//
// Created by Akshansh Gusain on 17/01/24.
//
#include "LL_000.cpp"

bool detectLoop(ListNode *&head) {
    if (head == nullptr) {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while(fast->next != nullptr and fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            return true;
        }
    }

    return false;
}

int main() {
    ListNode *head = nullptr;

    push(head, 20);
    push(head, 4);
    push(head, 15);
    push(head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
}