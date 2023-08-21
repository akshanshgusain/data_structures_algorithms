//
// Created by Akshansh Gusain on 21/10/21.
//

//
// Created by Akshansh Gusain on 08/03/21.

//Using Min Heap O(nlogK) time and O(k)space

#include<stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    explicit Node(int key){
        data = key;
        next = nullptr;
    }
};

void push(Node *&head, int value) {
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;
}

void print(Node *node) {
    while (node != nullptr) {
        if (node->next != nullptr) {
            cout << node->data << "->";
        } else {
            cout << node->data;
        }

        node = node->next;
    }
    cout << endl;
}

// 'compare' function used to build up the priority queue
struct compare {
    bool operator()(
            struct Node* a, struct Node* b)
    {
        return a->data > b->data;
    }
};

struct Node* mergeKSortedLists(vector<Node*> &arr){
    int k = arr.size();
    // priority_queue 'pq' implemented
    // as min heap with the
    // help of 'compare' function
    priority_queue<Node*, vector<Node*>, compare> pq;

    // push the head nodes of all
    // the k lists in 'pq'
    for (int i = 0; i < k; i++){
        if (arr[i] != nullptr){
            pq.push(arr[i]);
            //cout<<arr[i]->data<<endl;
        }

    }

    // Handles the case when k = 0
    // or lists have no elements in them
    if (pq.empty())
        return nullptr;

    Node *dummy = new Node(0);
    Node *last = dummy;

    // loop till 'pq' is not empty
    while (!pq.empty()) {

        // get the top element of 'pq'
        Node* curr = pq.top();
        pq.pop();

        // add the top element of 'pq'
        // to the resultant merged list
        last->next = curr;
        last = last->next;

        // check if there is a node
        // next to the 'top' node
        // in the list of which 'top'
        // node is a member
        if (curr->next != nullptr)
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
    //Node* arr[k];
    vector<Node*> arr;
    Node *head1 = nullptr, *head2 = nullptr, *head3 = nullptr;

    // creating k = 3 sorted lists
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

    arr.push_back(head1);
    arr.push_back(head2);
    arr.push_back(head3);
    // merge the k sorted lists

    Node* head4 = mergeKSortedLists(arr);

    // print the merged list
    print(head4);

    return 0;
}
