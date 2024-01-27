//
// Created by Akshansh Gusain on 25/01/24.
//
#include "DLL_000.cpp"

void rotate(ListNode* &head, int times){
    if(head == nullptr or head->next == nullptr or times <= 0){
        return;
    }

    ListNode *curr = head;
    int count = 1;

    while(count < times and curr != nullptr){
        curr = curr->next;
        count++;
    }

    if(curr == nullptr){
        return;
    }

    ListNode* nthNode = curr;

    while(curr->next != nullptr){
        curr = curr->next;
    }

    curr->next = head;
    head->prev = curr;
    head = nthNode->next;
    head->prev = nullptr;
    nthNode->next = nullptr;
}

int main(){
    ListNode *head = nullptr;

    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    push(head, 8);
    push(head, 56);
    push(head, 12);
    push(head, 2);
    push(head, 6);
    push(head, 3);

    int N = 2; //times

    cout << "Given linked list \n";
    printList(head);

    rotate(head, N);

    cout << "\nRotated Linked list \n";
    printList(head);
    return 0;
}