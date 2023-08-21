//
// Created by Akshansh Gusain on 15/10/21.
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

void push(Node *&head, int val) {
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void reverseLL(Node* &head) {
    Node *previous, *next, *current;
    current = head;
    previous = next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;
}

void print(Node *node) {
    while (node != nullptr) {
        cout << node->data;
        if (node->next != nullptr) {
            cout << "->";
        }
        node = node->next;
    }
    cout << endl;
}

Node *addTwoNumbers(Node* &num1, Node* &num2) {
    Node *result = nullptr;
    Node *temp = nullptr, *prev = nullptr;
    int carry = 0, sum = 0;
    while (num1 != nullptr or num2 != nullptr) {
        sum = carry + (num1?num1->data : 0) + (num2 ? num2->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        temp = new Node(sum);

        if(result == nullptr){
            result = temp;
        }else{
            prev->next = temp;
        }

        prev = temp;

        if(num1){
            num1 = num1->next;
        }
        if(num2){
            num2 = num2->next;
        }
    }
    if(carry>0){
        temp->next = new Node(carry);
    }
    return result;
}

int main() {
    Node *first = nullptr, *second = nullptr;

    // create first list 7->5->9->4->6
    // first number 64957
    push(first, 6);
    push(first, 4);
    push(first, 9);
    push(first, 5);
    push(first, 7);

    printf("First List is ");
    print(first);

    // create second list 8->4
    // second number 48
    push(second, 8);
    push(second, 4);
    cout << "Second List is ";
    print(second);

    Node *resultant = addTwoNumbers(first, second);
    cout << "Resultant List: " << endl;
    print(resultant);

    return 0;
}