//
// Created by Akshansh Gusain on 14/10/21.
//

#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    explicit Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void push(Node *&head, int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void print(Node *node) {
    while (node != nullptr) {
        cout << node->data << "->";
        node = node->next;
    }
    cout << endl;
}


bool detectLoop(Node *head) {
    Node *slow = head, *fast = head;

    // Either fast pointer catches up to slow pointer OR the fast pointer reaches the end of the list
    while (slow and fast and fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

int main() {
    Node *head = nullptr;

    push(head, 20);
    push(head, 4);
    push(head, 15);
    push(head, 10);

    /* Create a loop for testing */
   // head->next->next->next->next = head;
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";

    //print(head);
    return 0;
}