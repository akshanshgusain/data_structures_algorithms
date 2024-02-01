//
// Created by Akshansh Gusain on 26/01/24.
//
#include "LL_000.cpp"

void segregateEvenOdd(ListNode *&head) {
    ListNode *curr = head, *prev = nullptr, *end = head;

    // get pointer to the last node
    while (end->next != nullptr) {
        end = end->next;
    }

    ListNode *newEnd = end;

    // consider all the odd nodes before the first even node
    // push them at the end of list
    while (curr->val % 2 != 0 and curr != end) {
        newEnd->next = curr;
        curr = curr->next;
        newEnd->next->next = nullptr;
        newEnd = newEnd->next;
    }

    // found an even node
    if (curr->val % 2 == 0) {
        /* Change the head pointer to
       point to first even node */
        head = curr;

        /* now current points to
        the first even node */
        while (curr != end) {
            if ((curr->val) % 2 == 0) {
                prev = curr;
                curr = curr->next;
            } else {
                /* break the link between
                prev and current */
                prev->next = curr->next;

                /* Make next of curr as NULL */
                curr->next = nullptr;

                /* Move curr to end */
                newEnd->next = curr;

                /* make curr as new end of list */
                newEnd = curr;

                /* Update current pointer to
                next of the moved node */
                curr = prev->next;
            }
        }
    }

        /* We must have prev set before executing
       lines following this statement */
    else prev = curr;

    /* If there are more than 1 odd nodes
    and end of original list is odd then
    move this node to end to maintain
    same order of odd numbers in modified list */
    if (newEnd != end && (end->val) % 2 != 0) {
        prev->next = end->next;
        end->next = nullptr;
        newEnd->next = end;
    }


}

int main() {
    ListNode *head = nullptr;

    /* Let us create a sample linked list as following
    0->2->4->6->8->10->11 */

    push(head, 11);
    push(head, 2);
    push(head, 10);
    push(head, 6);
    push(head, 8);
    push(head, 3);
    push(head, 0);

    cout << "Original Linked list ";
    printList(head);

    segregateEvenOdd(head);

    cout << "\nModified Linked list ";
    printList(head);

    return 0;
}