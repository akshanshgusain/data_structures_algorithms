//
// Created by Akshansh Gusain on 26/01/24.
//
#include "LL_000.cpp"

void dutchFlag(ListNode* &head){
    vector<int> count(3, 0);
    ListNode* curr = head;

    // count 0s,1s and 2s
    while (curr != nullptr){
        count[curr->val] += 1;
        curr = curr->next;
    }

    curr = head; // reset head
    int i = 0;

    /* Let say count[0] = n1, count[1] = n2 and count[2] = n3
    * now start traversing list from head node,
    * 1) fill the list with 0, till n1 > 0
    * 2) fill the list with 1, till n2 > 0
    * 3) fill the list with 2, till n3 > 0 */
    while(curr != nullptr){
        if(count[i] != 0){
           curr->val = i;
           count[i]--;
           curr = curr->next;
        }else{
            i++;
        }
    }
}

int main(){
    ListNode *head = nullptr;

    push(head, 0);
    push(head, 1);
    push(head, 0);
    push(head, 2);
    push(head, 1);
    push(head, 1);
    push(head, 2);
    push(head, 1);
    push(head, 2);

    cout << "Linked List Before Sorting\n";
    printList(head);

    dutchFlag(head);

    cout << "Linked List After Sorting\n";
    printList(head);

    return 0;
}