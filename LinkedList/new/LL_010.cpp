//
// Created by Akshansh Gusain on 17/01/24.
//
#include "LL_000.cpp"

ListNode *reverse(ListNode *&head) {
    if (head == nullptr or head->next == nullptr) {
        return head;
    }
    ListNode *prev = nullptr, *curr = head, *next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode *addOne(ListNode *&head) {
    // 1. reverse the number
    head = reverse(head);

    // 2. Add one to the list
    ListNode *curr = head;
    ListNode *prev;
    int carry = 1, sum = 0;

    while (curr != nullptr) {
        sum = carry + curr->val;
        carry = sum >= 10 ? 1 : 0;
        sum = sum % 10;
        curr->val = sum;
        // Move head and second pointers to next nodes
        prev = curr;
        curr = curr->next;
    }

    // if some carry is still there, add a new node to
    // result list.
    if (carry > 0){
        prev->next = new ListNode(carry);
    }

    // 3. reverse the resultant
    return reverse(head);
}

int main() {
    ListNode *head = nullptr;

    push(head, 9);
    push(head, 9);
    push(head, 9);
    push(head, 9);

    cout << "Original list is : ";
    printList(head);

    head = addOne(head);

    cout << "Resultant list is : ";
    printList(head);
    return 0;
}