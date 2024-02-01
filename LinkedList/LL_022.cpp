//
// Created by Akshansh Gusain on 25/01/24.
//

#include "DLL_000.cpp"


void pairSum(ListNode* &head, int sum){
    // Set two pointers, first to the beginning of DLL
    // and second to the end of DLL.
    ListNode *first = head;
    ListNode *second = head;
    while (second->next != nullptr){
        second = second->next;
    }
    // To track if we find a pair or not
    bool found = false;

    // The loop terminates when either of two pointers
    // become NULL, or they cross each other (second->next
    // == first), or they become same (first == second)
    while (first != nullptr && second != nullptr &&
           first != second && second->next != first) {
        // pair found
        if ((first->val + second->val) == sum) {
            found = true;
            cout << "(" << first->val << ", "
                 << second->val << ")" << endl;

            // move first in forward direction
            first = first->next;

            // move second in backward direction
            second = second->prev;
        } else {
            if ((first->val + second->val) < sum)
                first = first->next;
            else
                second = second->prev;
        }
    }

    // if pair is not present
    if (!found){
        cout << "No pair found";
    }
}

int main() {
    ListNode *head = nullptr;
    push(head, 9);
    push(head, 8);
    push(head, 6);
    push(head, 5);
    push(head, 4);
    push(head, 2);
    push(head, 1);
    int x = 7;

    pairSum(head, 7);
    return 0;
}