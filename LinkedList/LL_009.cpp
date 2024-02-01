//
// Created by Akshansh Gusain on 17/01/24.
//
#include "LL_000.cpp"

void moveToFront(ListNode *&head) {
    if (head == nullptr || (head->next == nullptr)) {
        return;
    }
    ListNode *secLast = nullptr;
    ListNode *last = head;
    while (last->next != nullptr) {
        secLast = last;
        last = last->next;
    }
    secLast->next = nullptr;
    last->next = head;
    head = last;

}

int main() {
    ListNode *start = nullptr;

    /* The constructed linked list is:
    1->2->3->4->5 */
    push(start, 5);
    push(start, 4);
    push(start, 3);
    push(start, 2);
    push(start, 1);

    cout << "Linked list before moving last to front\n";
    printList(start);

    moveToFront(start);

    cout << "\nLinked list after removing last to front\n";
    printList(start);
    return 0;
}