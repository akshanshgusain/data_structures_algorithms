//
// Created by Akshansh Gusain on 24/01/24.
//
#include "LL_000.cpp"

void splitList(ListNode* &head, ListNode* &head1, ListNode* &head2){
    if (!head || !head->next) {
        return; // An empty list or a list with only one node is not circular
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while(fast->next != head and fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }

    // if there are even number of elements, move the fast pointer 1 step forward
    // fast pointer need to be pointed to the head
    if(fast->next->next == head){
        fast = fast->next;
    }

    // set head1 as head of first half of the list
    head1 = head;

    // set head2 as the head of second half of the list
    head2 = slow->next;

    // break the circular link
    fast->next = slow->next;
    slow->next = head;
}

int main(){
    ListNode *head = nullptr, *head1 = nullptr, *head2 = nullptr;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 5);
    push(head, 4);
    push(head, 6);

    makeCircular(head);

    printCircularList(head);
//    Node* middle = findMiddleElement(head);
//
    splitList(head, head1, head2);
    cout<<"First list: "<<endl;
    printCircularList(head1);
    cout<<endl;
    cout<<"Second list: "<<endl;
    printCircularList(head2);

    return 0;
}