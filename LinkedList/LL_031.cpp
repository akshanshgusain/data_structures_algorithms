//
// Created by Akshansh Gusain on 26/01/24.
//

#include "LL_000.cpp"

void printNthFromLast(ListNode *head, int n) {
    int len = 0, i;
    ListNode *temp = head;

    // count the number of nodes in Linked List
    while (temp != nullptr) {
        temp = temp->next;
        len++;
    }

    // check if value of n is not
    // more than length of the linked list
    if (len < n){
        return;
    }

    temp = head;

    // get the (len-n+1)th node from the beginning
    for (i = 1; i < len - n + 1; i++){
        temp = temp->next;
    }
    cout << temp->val;
}


int main() {
    ListNode *head = nullptr;

    // create linked 35->15->4->20
    push(head, 20);
    push(head, 4);
    push(head, 15);
    push(head, 35);

    printNthFromLast(head, 3);
    return 0;
}