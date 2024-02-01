//
// Created by Akshansh Gusain on 17/01/24.
//
#include "LL_000.cpp"

ListNode* deleteDuplicates(ListNode* &head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode *curr = head;

    while(curr->next != nullptr){
        if(curr->val == curr->next->val){
            curr->next = curr->next->next;
        }else{
            curr = curr->next;
        }
    }
    return head;
}

int main(){
    ListNode *head = nullptr;
    push(head, 5);
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 3);
    push(head, 2);
    push(head, 1);

    printList(head);

    ListNode* newNode = deleteDuplicates(head);
    cout<<endl;
    printList(newNode);
    return 0;
}