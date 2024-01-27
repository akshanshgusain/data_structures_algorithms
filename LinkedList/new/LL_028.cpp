//
// Created by Akshansh Gusain on 26/01/24.
//
#include "LL_000.cpp"

// multiply two numbers
long multiplyLinkedLists(ListNode *first, ListNode *second) {
    int num1 = 0, num2 = 0;

    // generate numbers from linked lists
    while(first != nullptr or second != nullptr){
        if(first != nullptr){
            num1 = num1*10 + first->val;
            first = first->next;
        }
        if(second != nullptr){
            num2 = num2*10 + second->val;
            second = second->next;
        }
    }
    return (num1 * num2);
}

int main() {
    ListNode *first = nullptr;
    ListNode *second = nullptr;

    // create first list 9->4->6
    push(first, 6);
    push(first, 4);
    push(first, 9);
    printf("First List is: ");
    printList(first);
    cout<<endl;

    // create second list 8->4
    push(second, 4);
    push(second, 8);
    printf("Second List is: ");
    printList(second);
    cout<<endl;

    // Multiply the two lists and see result
    printf("Product List is: \n");
    cout<< multiplyLinkedLists(first, second);

    return 0;
}