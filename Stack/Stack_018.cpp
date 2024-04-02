#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

// Recursion
//class Stack{
//private:
//    Node *top;
//
//public:
//    Stack() {
//        top = nullptr;
//    }
//
//    void push(int x) {
//        Node *temp = new Node;
//        temp->data = x;
//        temp->next = top;
//        top = temp;
//    }
//
//    int pop() {
//        if (top != nullptr) {
//            Node *temp = top;
//            top = top->next;
//            int b = temp->data;
//            delete temp;
//            return b;
//        } else {
//            cout << "Stack is empty: \n";
//        }
//    }
//
//    void display() {
//        Node *Temp = top;
//        while (Temp != nullptr) {
//            cout << Temp->data << endl;
//            Temp = Temp->next;
//        }
//    }
//
    void insertBottom(stack<int> &A, int t) {
        if (A.empty()) {
            A.push(t);  // if stack is empty insert the element
        } else {
            int x = A.top();
            A.pop(); //Popping all elements
            insertBottom(A, t);  //Inserting the given elements
            A.push(x);  // Pushing all the popped elements
        }
    }
//};
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
    ST.push(1);
//    ST.insertBottom(ST, 6);
    ST.insertAtBottom(6);
    ST.display();
    return 0;
}