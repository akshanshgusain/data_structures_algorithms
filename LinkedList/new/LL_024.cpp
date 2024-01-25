//
// Created by Akshansh Gusain on 25/01/24.
//
#include "DLL_000.cpp"

// Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list.

struct compare {
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

ListNode* sortKSortedDLL(ListNode* head, int k){
    if(head == nullptr or head->next == nullptr or k <= 0){
        return head;
    }
    priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
    ListNode *sorted = nullptr, *last = nullptr;

    //create min heap of the first k+1 elements
    for(int i= 0; head != nullptr && i<= k; i++){
        minHeap.push(head);
        head = head->next;
    }

    while(!minHeap.empty()){
        if(sorted == nullptr){
            sorted = minHeap.top();
            sorted->prev = nullptr;
            last = sorted;
        }else{
            last->next = minHeap.top();
            minHeap.top()->prev = last;
            last = minHeap.top();
        }
        minHeap.pop();

        // if there are more nodes left in the input list
        if(head != nullptr){
            minHeap.push(head);
            head = head->next;
        }
    }

    last->next = nullptr;
    return sorted;
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

    int k = 2;

    cout << "Original Doubly linked list:\n";
    printList(head);

    head = sortKSortedDLL(head, k);

    cout << "\nDoubly linked list after sorting:\n";
    printList(head);
    // 2<->3<->6<->8<->12<->56
    return 0;
}