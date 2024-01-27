//
// Created by Akshansh Gusain on 26/01/24.
//
#include "LL_000.cpp"

// Reverse the linked list.
// Traverse the reversed list and keep track of the maximum value encountered so far.
// If the current node's value is less than the maximum value, delete the node.
// Reverse the modified linked list to obtain the final result.
void reverseList(ListNode *&head) {
    ListNode *curr = head, *prev = nullptr, *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = head;
}

void deleteNodes(ListNode *&head){
    ListNode* current = head, *maxSoFar = head, *temp = nullptr;

    while(current != nullptr and current->next != nullptr){
        if(current->next->val < maxSoFar->val){
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }else{
            current = current->next;
            maxSoFar = current;
        }
    }
}

void deleteLesserNodes(ListNode *&head) {
    reverseList(head);
    deleteNodes(head);
    reverseList(head);
}

int main() {
    ListNode *head = nullptr;

    /* Create following linked list
    12->15->10->11->5->6->2->3 */
    push(head, 3);
    push(head, 2);
    push(head, 6);
    push(head, 5);
    push(head, 11);
    push(head, 10);
    push(head, 15);
    push(head, 12);

    cout << "Given Linked List \n";
    printList(head);

    deleteLesserNodes(head);

    cout << "Modified Linked List \n";
    printList(head);
    return 0;
}