//
// Created by Akshansh Gusain on 26/01/24.
//
#include<stdc++.h>

using namespace std;

class ListNode {
public:
    int data;
    ListNode *next, *random;

    explicit ListNode(int key) {
        data = key;
        next = nullptr;
        random = nullptr;
    }
};

void push(ListNode *&head, int value) {
    auto *temp = new ListNode(value);
    temp->next = head;
    head = temp;
}

void print(ListNode *node) {
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

void printWRandom(ListNode *node) {
    while (node != nullptr) {
        ListNode *random = node->random;
        int randomData = (random != nullptr) ? random->data : -1;
        cout << "N: " << node->data << ", ";
        cout << "Random: " << randomData << "\n";
        node = node->next;
    }
    cout << endl;
}

ListNode* clone(ListNode* &head){
    ListNode *curr = head;
    ListNode *temp = nullptr;

    //Insert additional node after every node of original list
    while (curr != nullptr) {
        temp = curr->next;

        curr->next = new ListNode(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = head;

    // copy random pointers
    while (curr != nullptr) {
        if (curr->next != nullptr) {
            curr->next->random = curr->random ? curr->random->next : curr->random;
            curr = curr->next ? curr->next->next : curr->next;
        }
    }

    ListNode *original = head, *copy = head->next;
    temp = copy;

    // sever the links
    while (original != nullptr and copy != nullptr){
        original->next = original->next? original->next->next: original->next;

        copy->next = copy->next?copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return temp;
}

int main(){
    ListNode *head = nullptr;
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);

    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next->next->next->next;
    head->next->next->next->next->random = head->next;

    cout << "Original linked list\n";
    print(head);
    printWRandom(head);

    ListNode *clonedList = clone(head);
    cout << "Cloned linked list\n";
    print(clonedList);
    printWRandom(clonedList);
    return 0;
}