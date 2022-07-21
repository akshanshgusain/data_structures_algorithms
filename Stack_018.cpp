#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int x) {
        Node *temp;
        temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    int pop() {
        if (top != nullptr) {
            Node *temp = top;
            top = top->next;
            int b = temp->data;
            delete temp;
            return b;
        } else {
            cout << "Stack is empty: \n";
        }
    }

    void display() {
        Node *Temp = top;
        while (Temp != nullptr) {
            cout << Temp->data << endl;
            Temp = Temp->next;
        }
    }

    void insertBottom(Stack &A, int t) {

        Node *temp = this->top;

        if (top == nullptr) {
            A.push(t);  // if stack is empty insert the element
        } else {
            int x = A.pop(); //Popping all elements
            insertBottom(A, t);  //Inserting the given elements
            A.push(x);  // Pushing all the popped elements
        }
    }
};


int main() {
    int a;
    Stack ST;
    char Ch;
    ST.push(4);
    ST.push(3);
    ST.push(2);
    ST.push(1);
    ST.insertBottom(ST, 6);
    ST.disp();
    return 0;
    return 0;
}