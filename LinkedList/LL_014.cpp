//
// Created by Akshansh Gusain on 23/01/24.
//
#include "LL_000.cpp"

void SplitList(ListNode* &head, ListNode* &A, ListNode* &B){
    ListNode *slow = head, *fast = head->next;

    while(fast != nullptr and fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    A = head;
    B = slow->next;
    slow->next = nullptr; // Break the list into two halves
}

ListNode* Merge(ListNode* &left, ListNode* &right){
    if(left == nullptr){
        return right;
    }else if(right == nullptr){
        return left;
    }

    ListNode* result = nullptr;

    if (left->val <= right->val) {
        result = left;
        result->next = Merge(left->next, right);
    } else {
        result = right;
        result->next = Merge(left, right->next);
    }

    return result;
}

void MergeSort(ListNode* &head){
    if (head == nullptr or head->next == nullptr) {
        return;
    }

    ListNode *leftHead = nullptr, *rightHead = nullptr;

    // split the list into 2 halves
    SplitList(head, leftHead, rightHead);

    // recursively sort each half
    MergeSort(leftHead);
    MergeSort(rightHead);

    // merge the sorted halves
    head = Merge(leftHead,rightHead);
}

int main(){
    ListNode *head = nullptr;

    push(head, 15);
    push(head, 10);
    push(head, 5);
    push(head, 20);
    push(head, 3);
    push(head, 2);

    printList(head);

    MergeSort(head);

    cout << "Sorted Linked List is: \n";

    printList(head);
    return 0;
}