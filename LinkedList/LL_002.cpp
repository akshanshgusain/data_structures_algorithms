//
// Created by Akshansh Gusain on 16/01/24.
//
#include "LL_000.cpp"

// delete from a particular position
void deleteFromPosition(ListNode *&head, int position) {
    if (head == nullptr) {
        return;
    }
    ListNode *temp = head;
    if (position == 0) {
        // head needs to be removed
        head = head->next;
        free(temp);
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != nullptr and i < position - 1; i++) {
        temp = temp->next;
    }
    // If position is more than number of nodes
    if (temp == nullptr or temp->next == nullptr) {
        return;
    }

    ListNode *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main() {
    ListNode *head = nullptr;

    push(head, 7);
    push(head, 1);
    push(head, 3);
    push(head, 2);
    push(head, 8);

    cout << "Created Linked List: ";
    printList(head);
    deleteFromPosition(head, 2);
    cout << "\nLinked List after Deletion at position 2: \n";
    printList(head);
    return 0;
}