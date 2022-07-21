//
// Created by Akshansh Gusain on 21/10/21.
//
//
// Created by Akshansh Gusain on 08/03/21.
//
#include <stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    explicit Node(int data) {
        this->data = data;
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

/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(Node* head, int n)
{
    int len = 0, i;
    Node* temp = head;

    // count the number of nodes in Linked List
    while (temp != nullptr) {
        temp = temp->next;
        len++;
    }

    // check if value of n is not
    // more than length of the linked list
    if (len < n)
        return;

    temp = head;

    // get the (len-n+1)th node from the beginning
    for (i = 1; i < len - n + 1; i++)
        temp = temp->next;

    cout << temp->data;

}



// Driver Code
int main()
{
    /* Start with the empty list */
    Node* head = nullptr;

    // create linked 35->15->4->20
    push(head, 20);
    push(head, 4);
    push(head, 15);
    push(head, 35);

    printNthFromLast(head, 4);
    return 0;
}


