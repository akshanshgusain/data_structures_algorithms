//
// Created by Akshansh Gusain on 17/01/24.
//
#include "LL_000.cpp"

ListNode* deleteDuplicates(ListNode* &head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // store seen vales
    unordered_set<int> seen;
    seen.insert(head->val);

    ListNode *curr = head;

    while(curr->next != nullptr){
       if(seen.find(curr->next->val) != seen.end()){
           ListNode *duplicate = curr->next;
           curr->next = curr->next->next;
           delete duplicate;
       }else{
           seen.insert(curr->next->val);
           curr = curr->next;
       }
    }

    return head;
}

int main(){
    ListNode *head = nullptr;
    push(head, 10);
    push(head, 11);
    push(head, 12);
    push(head, 11);
    push(head, 11);
    push(head, 12);
    push(head, 10);

    printList(head);
    ListNode* newNode = deleteDuplicates(head);
    cout<<endl;
    printList(newNode);
    return 0;
}