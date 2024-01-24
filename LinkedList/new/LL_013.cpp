//
// Created by Akshansh Gusain on 23/01/24.
//
#include "LL_000.cpp"


int main(){
    ListNode *head1 = nullptr, *head2 = nullptr;


    push(head1, 750);
    push(head1, 14);
    push(head1, 8);
    push(head1, 15);
    push(head1, 30);
    push(head1, 2);


    push(head2, 750);
    push(head2, 14);
    push(head2, 8);
    push(head2, 2);
    push(head2, 6);

    cout<<getIntersectionNode(head1, head2);
    return 0;
}