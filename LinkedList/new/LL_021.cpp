//
// Created by Akshansh Gusain on 25/01/24.
//

#include "DLL_000.cpp"


void reverseDLL(ListNode* &head){
    if(head == nullptr or head->next == nullptr){
        return;
    }
    ListNode *curr = head, *prev = nullptr;

    // swap next and prev pointers for all the nodes
    while(curr != nullptr){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }

    // If the list is not empty, update the head
    if (prev != nullptr) {
        head = prev->prev;
    }

}

int main() {
    ListNode *head = nullptr;

    push(head, 2);
    push(head, 4);
    push(head, 8);
    push(head, 10);

    cout << "Original Linked list" << endl;
    printList(head);

    /* Reverse doubly linked list */
    reverseDLL(head);

    cout << "\nReversed Linked list" << endl;
    printList(head);

    return 0;
}
