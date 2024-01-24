//
// Created by Akshansh Gusain on 18/01/24.
//
#include "LL_000.cpp"

ListNode *reverse(ListNode *&head) {
    if(head == nullptr or head->next == nullptr){
        return head;
    }

    ListNode *prev = nullptr, *curr = head, * next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode * addTwoNumbers(ListNode* &first, ListNode* &second){
    first = reverse(first);
    second = reverse(second);

    ListNode *result = nullptr;
    ListNode *temp = nullptr, *prev = nullptr;
    int carry = 0, sum =0;

    while(first != nullptr or second != nullptr){
        sum = carry + (first?first->val :0) + (second?second->val:0);
        carry = (sum >=10)?1:0;
        sum = sum % 10;

        temp = new ListNode(sum);

        if(result == nullptr){
            result = temp;
        }else{
            prev->next = temp;
        }

        prev = temp;

        if(first != nullptr){
            first = first->next;
        }
        if(second != nullptr){
            second = second->next;
        }
    }

    // if carry is remaining, create a new ndoe
    if(carry > 0){
        prev->next = new ListNode(carry);
    }

    return reverse(result);
}

int main() {
    ListNode *first = nullptr, *second = nullptr;

    // create first list 7->5->9->4->6
    // first number 64957
    push(first, 6);
    push(first, 4);
    push(first, 9);
    push(first, 5);
    push(first, 7);

    printf("First List is ");
    printList(first);

    // create second list 8->4
    // second number 48
    push(second, 8);
    push(second, 4);
    cout << "Second List is ";
    printList(second);

    ListNode *resultant = addTwoNumbers(first, second);
    cout << "Resultant List: " << endl;
    printList(resultant);
    return 0;
}