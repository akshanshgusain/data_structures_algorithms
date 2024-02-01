//
// Created by Akshansh Gusain on 25/01/24.
//
#include "DLL_000.cpp"

// function to count pairs whose sum equal to given 'value'
int countPairs(ListNode * first, ListNode *second, int value) {
    int count = 0;

    // The loop terminates when either of two pointers
    // become NULL, or they cross each other (second->next
    // == first), or they become same (first == second)
    while (first != nullptr && second != nullptr &&
           first != second && second->next != first) {

        // pair found
        if ((first->val + second->val) == value) {

            // increment count
            count++;

            // move first in forward direction
            first = first->next;

            // move second in backward direction
            second = second->prev;
        }

            // if sum is greater than 'value'
            // move second in backward direction
        else if ((first->val + second->val) > value)
            second = second->prev;

            // else move first in forward direction
        else
            first = first->next;
    }

    // required count of pairs
    return count;
}

// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int countTriplets(ListNode *&head, int x) {
    // if list is empty
    if (head == nullptr) {
        return 0;
    }


    ListNode *current, *first, *last;
    int count = 0;

    // get pointer to the last node of
    // the doubly linked list
    last = head;
    while (last->next != nullptr)
        last = last->next;

    // traversing the doubly linked list
    for (current = head; current != nullptr; current = current->next) {

        // for each current node
        first = current->next;

        // count pairs with sum(x - current->data) in the range
        // first to last and add it to the 'count' of triplets
        count += countPairs(first, last, x - current->val);
    }

    // required count of triplets
    return count;
}

int main() {
    ListNode *head = nullptr;

    // insert values in sorted order
    push(head, 9);
    push(head, 8);
    push(head, 6);
    push(head, 5);
    push(head, 4);
    push(head, 2);
    push(head, 1);

    int x = 17;

    cout << "Count = "
         << countTriplets(head, x);
    return 0;
}