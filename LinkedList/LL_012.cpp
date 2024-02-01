//
// Created by Akshansh Gusain on 18/01/24.
//
#include "LL_000.cpp"

ListNode* findIntersection(ListNode* &head1, ListNode* &head2){
   ListNode* intersection = nullptr;

   while(head1 != nullptr and head2 != nullptr){
       if(head1->val == head2->val){
           push(intersection, head1->val);
           head1 = head1->next;
           head2 = head2->next;
       }else if(head1->val > head2->val){
           head2 = head2->next;
       }else{
           head1 = head1->next;
       }
   }

   return intersection;
}


int main(){
    ListNode *head1 = nullptr, *head2 = nullptr;

    push(head1, 8);
    push(head1, 6);
    push(head1, 6);
    push(head1, 4);
    push(head1, 2);
    push(head1, 1);

    push(head2, 6);
    push(head2, 4);
    push(head2, 2);
    push(head2, 0);

    ListNode *intersection = findIntersection(head1, head2);
    printList(intersection);
}