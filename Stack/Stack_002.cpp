//
// Created by Akshansh Gusain on 08/03/22.
//
#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
public:
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
    Node *root;
public:
    Stack() {
        root = nullptr;
    }

    bool push(int data) {
        if (root == nullptr) {
            root = new Node(data);
            cout << data << " pushed" << endl;
            return true;
        }
        Node *node = new Node(data);
        node->next = root;
        root = node;
        cout << data << " pushed" << endl;
        return true;
    }

    bool isEmpty() {
        return !root;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow";
            return -69;
        } else {
            Node *temp = root;
            root = root->next;
            int popped = temp->data;
            free(temp);
            return popped;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack Underflow";
            return -69;
        } else {
            return root->data;
        }
    }
};


int main() {
    Stack stk = Stack();
    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << stk.pop() << " popped from the stack" << endl;
    cout << "Top element is: " << stk.peek() << endl;
    cout << "Elements present in stack : ";
    while (!stk.isEmpty()) {
        // print top element in stack
        cout << stk.peek() << " ";
        // remove top element in stack
        stk.pop();
    }
    return 0;
}
