#include<bits/stdc++.h>

using namespace std;


struct Node {
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;
    Node *bottom;
public:
    Stack() {
        top = bottom = nullptr;
    }

    void push(int value) {
        Node *temp = new Node();
        temp->data = value;
        temp->next = top;
        if (top == nullptr) {
            //first assignment
            bottom = temp;
        }
        top = temp;
    }

    int pop() {
        if (top != nullptr) {
            Node *temp = top;
            top = top->next;
            int poppedValue = temp->data;
            delete temp;
            return poppedValue;
        }else{
            cout<<"stack underflow"<<endl;
            return INT_MIN;
        }
    }

    void insertAtBottom(int value){
        if(bottom == nullptr){
            // first node
            push(value);
            return;
        }

        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        bottom->next = temp;
        bottom = bottom->next;
    }

    void display() {
        Node *Temp = top;
        while (Temp != nullptr) {
            cout << Temp->data << endl;
            Temp = Temp->next;
        }
    }
};

int main() {

    Stack ST;

    ST.push(4);
    ST.push(3);
    ST.push(2);
    ST.insertAtBottom( 7);
    ST.push(1);
    ST.insertAtBottom( 6);
    ST.display();

    return 0;
}