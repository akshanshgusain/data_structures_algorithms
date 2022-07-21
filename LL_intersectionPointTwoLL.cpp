//
// Created by Akshansh Gusain on 04/03/21.
//
//Method 1: Simply Use two loops
//Method 2: Traverse the first linked list and keep marking visited nodes. Now traverse the second linked list
// , If you see a visited node again then there is an intersection point, return the intersecting node.

//Method 3: (Using difference of node counts)
/*
Get count of the nodes in the first list, let count be c1.
Get count of the nodes in the second list, let count be c2.
Get the difference of counts d = abs(c1 – c2)
Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of
 nodes.
Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is
 done by comparing the address of the nodes).
 */

#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

int getCount(Node *head) {
    Node *current = head;
    int count = 0;

    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

int _getIntesectionNode(int d, Node *head1, Node *head2) {
    Node *current1 = head1;
    Node *current2 = head2;

    for (int i = 0; i < d; i++) {
        if (current1 == nullptr) {
            return -1;
        }
        current1 = current1->next;
    }

    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2) {
            return current1->data;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return -1;
}

int getIntesectionNode(Node* head1, Node* head2)
{
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;

    if (c1 > c2) {
        d = c1 - c2;
        return _getIntesectionNode(d, head1, head2);
    }
    else {
        d = c2 - c1;
        return _getIntesectionNode(d, head2, head1);
    }
}

int main() {
    Node* newNode;

    // Addition of new nodes
    Node* head1 = new Node();
    head1->data = 10;

    Node* head2 = new Node();
    head2->data = 3;

    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;

    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;

    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;

    head1->next->next->next = nullptr;

    cout << "The node of intersection is " << getIntesectionNode(head1, head2);

    return 0;
}