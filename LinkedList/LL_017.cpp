//
// Created by Akshansh Gusain on 16/10/21.
//
#include<stdc++.h>

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

void push(Node* &head_ref, int data) {
    Node *ptr1 = new Node(data);
    Node *temp = head_ref;
    ptr1->next = head_ref;

    if (head_ref != nullptr) {
        while (temp->next != head_ref) {
            temp = temp->next;
        }
        temp->next = ptr1;
    } else
        ptr1->next = ptr1;

    head_ref = ptr1;
}


void print(Node *head) {
    Node *temp = head;
    if (head != nullptr) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}

Node* findMiddleElement(Node* &head){
    Node* slow = head, *fast = head->next;
    while(fast!= head){
        fast = fast->next;
        if(fast!= head){
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

void splitList(Node* &head, Node* &head2){
    Node* slow = head, *fast = head->next;
    while(fast->next!= head){
        fast = fast->next;
        if(fast->next!= head){
            fast = fast->next;
            slow = slow->next;
        }
    }

    head2 = slow->next;
    fast->next = head2;
    slow->next = head;


}

int main() {

    Node *head = nullptr, *head2 = nullptr;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 5);
    push(head, 4);

    print(head);
//    Node* middle = findMiddleElement(head);
//
    splitList(head, head2);
    cout<<"First list: "<<endl;
    print(head);
    cout<<endl;
    cout<<"Second list: "<<endl;
    print(head2);

    return 0;
}