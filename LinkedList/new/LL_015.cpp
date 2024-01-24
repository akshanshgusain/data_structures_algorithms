//
// Created by Akshansh Gusain on 24/01/24.
//
#include "LL_000.cpp"

void QuickSort(ListNode* &head){
    head = quickSort(head, getTail(head));
}

int main(){
    ListNode *head = nullptr, *end = nullptr;

    push(head, 15);
    push(head, 10);
    push(head, 5);
    push(head, 20);
    push(head, 3);
    push(head, 2);

    printList(head);

    QuickSort(head);

    cout << "Sorted Linked List is: \n";

    printList(head);

    return 0;
}