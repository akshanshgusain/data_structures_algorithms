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
        if(node->next != nullptr){
            cout << node->data << "->";
        }else{
            cout << node->data;
        }

        node = node->next;
    }
    cout << endl;
}

void moveToFront(Node* &head){
    if (head == nullptr || (head->next == nullptr)){
        return;
    }

    Node *secLast = nullptr;
    Node *last = head;
    while (last->next != nullptr)
    {
        secLast = last;
        last = last->next;
    }
    secLast->next = nullptr;
    last->next = head;
    head = last;
}

int main() {

    Node *start = nullptr;

    /* The constructed linked list is:
    1->2->3->4->5 */
    push(start, 5);
    push(start, 4);
    push(start, 3);
    push(start, 2);
    push(start, 1);

    cout<<"Linked list before moving last to front\n";
    print(start);

    moveToFront(start);

    cout<<"\nLinked list after removing last to front\n";
    print(start);

    return 0;
}