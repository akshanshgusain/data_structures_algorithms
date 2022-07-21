//
// Created by Akshansh Gusain on 08/03/21.

//Using Min Heap O(nlogK) time and O(k)space

#include<stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data)
{
    auto* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void printList(struct Node* head)
{
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

// 'compare' function used to build up the priority queue
struct compare {
    bool operator()(
            struct Node* a, struct Node* b)
    {
        return a->data > b->data;
    }
};

struct Node* mergeKSortedLists(struct Node* arr[], int k){
    // priority_queue 'pq' implemented
    // as min heap with the
    // help of 'compare' function
    priority_queue<Node*, vector<Node*>, compare> pq;

    // push the head nodes of all
    // the k lists in 'pq'
    for (int i = 0; i < k; i++)
        if (arr[i] != NULL)
            pq.push(arr[i]);

    // Handles the case when k = 0
    // or lists have no elements in them
    if (pq.empty())
        return NULL;

    struct Node *dummy = newNode(0);
    struct Node *last = dummy;

    // loop till 'pq' is not empty
    while (!pq.empty()) {

        // get the top element of 'pq'
        struct Node* curr = pq.top();
        pq.pop();

        // add the top element of 'pq'
        // to the resultant merged list
        last->next = curr;
        last = last->next;

        // check if there is a node
        // next to the 'top' node
        // in the list of which 'top'
        // node is a member
        if (curr->next != NULL)
            // push the next node of top node in 'pq'
            pq.push(curr->next);
    }

    // address of head node of the required merged list
    return dummy->next;
}

int main(){
    int k = 3; // Number of linked lists
    int n = 4; // Number of elements in each list

    // an array of pointers storing the head nodes
    // of the linked lists
    Node* arr[k];

    // creating k = 3 sorted lists
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    // merge the k sorted lists
    struct Node* head = mergeKSortedLists(arr, k);

    // print the merged list
    printList(head);

    return 0;
}