//
// Created by Akshansh Gusain on 21/10/21.
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
// Multiply contents of two linked lists
long multiplyTwoLists (Node* first, Node* second)
{
    int num1 = 0, num2 = 0;

    // Generate numbers from linked lists
    while (first || second)
    {
        if (first)
        {
            num1 = num1*10 + first->data;
            first = first->next;
        }
        if (second)
        {
            num2 = num2*10 + second->data;
            second = second->next;
        }
    }

    // Return multiplication of
    // two numbers
    return num1*num2;
}


// Driver program to test above function
int main()
{
    Node* first = nullptr;
    Node* second = nullptr;

    // create first list 9->4->6
    push(first, 6);
    push(first, 4);
    push(first, 9);
    printf("First List is: ");
    print(first);

    // create second list 8->4
    push(second, 4);
    push(second, 8);
    printf("Second List is: ");
    print(second);

    // Multiply the two lists and see result
    cout<<"Result is: ";
    cout<< multiplyTwoLists(first, second);

    return 0;
}
