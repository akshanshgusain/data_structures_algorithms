//
// Created by Akshansh Gusain on 25/01/24.
//
#include "LL_000.cpp"

struct compare{
    bool operator()(
            struct ListNode* a, struct ListNode* b)
    {
        return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    int k = lists.size();
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;

    // push heads of all the lists
    for(int i = 0 ; i < k; i ++){
        if(lists[i] != nullptr){
            pq.push(lists[i]);
        }
    }

    // Handles the case when k = 0
    if (pq.empty()){
        return nullptr;
    }

    auto *result = new ListNode(0);
    auto *curr = result;

    while(!pq.empty()){
        auto *top = pq.top();
        pq.pop();

        // add top of the pq to the resultant list
        curr->next = top;
        curr = curr->next;

        // add curr->next to the queue
        if(top->next != nullptr){
            pq.push(top->next);
        }
    }
        return result->next;
}

int main() {
    ListNode *head1 = nullptr, *head2 = nullptr, *head3 = nullptr;
    push(head1, 7);
    push(head1, 5);
    push(head1, 3);
    push(head1, 1);

    push(head2, 8);
    push(head2, 6);
    push(head2, 4);
    push(head2, 2);

    push(head3, 11);
    push(head3, 10);
    push(head3, 9);
    push(head3, 0);

    vector<ListNode *> lists = {head1, head2, head3};

    auto head4 = mergeKLists(lists);

    printList(head4);


    return 0;
}