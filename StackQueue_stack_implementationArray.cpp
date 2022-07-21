//
// Created by Akshansh Gusain on 01/04/21.

//Pros: Easy to implement. Memory is saved as pointers are not involved.
//Cons: It is not dynamic. It doesn’t grow and shrink depending on needs at runtime.

#include<stdc++.h>
using namespace std;
#define MAX 100

class Stack{
    int top;
    public:
    int a[MAX];
    Stack(){
        top = -1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x) {
    if(top > MAX-1){
        cout<<"Stack Overflow";
        return false;
    }else{
        a[++top] = x;
        cout<< x << " pushed to stack \n";
        return true;
    }
}

int Stack::pop() {
    if(top<0){
        cout<<"Stack under flow";
        return 0;
    }else{
        return a[top--];
    }
}
int Stack::peek(){
    if(top<0){
        cout<<"Stack under flow";
        return 0;
    }else{
        return a[top];
    }
}

bool Stack::isEmpty() {
    if(top<0){
        return true;
    }else{
        return false;
    }
}

int main(){
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
