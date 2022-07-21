//
// Created by Akshansh Gusain on 08/03/22.
//
#include<stdc++.h>

using namespace std;
#define MAX 1001

class Stack {
    int top;
    vector<int> s;
public:
    Stack() {
        top = -1;
    }

    bool push(int x) {
        if (top > MAX - 1) {
            cout << "Stack Overflow";
            return false;
        } else {
            this->s.push_back(x);top++;
            cout<<x<<" is pushed to the stack"<<endl;
            return true;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow";
            return -1001;
        } else {
            return s[top--];
        }
    }

    int peek() {
        if (top < 0) {
            cout << "Stack Underflow";
            return -1001;
        } else {
            return s[top];
        }
    }

    bool isEmpty() {
        if (top < 0) {
            return true;
        } else {
            return false;
        };
    }
};

int main() {
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.peek() << " Top Element stack\n";
    cout << s.pop() << " Popped from stack\n";
    //print all elements in stack :
    cout<<"Elements present in stack : ";
    while(!s.isEmpty())
    {
        // print top element in stack
        cout<<s.peek()<<" ";
        // remove top element in stack
        s.pop();
    }
    return 0;
}
