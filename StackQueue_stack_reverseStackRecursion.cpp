//
// Created by Akshansh Gusain on 03/04/21.
//Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S:
//isEmpty(S)
//push(S)
//pop(S)

//The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty. When the stack becomes empty,
// insert all held items one by one at the bottom of the stack.


#include<stdc++.h>

using namespace std;

stack<char> st;
string ns;

char insertBottom(char x) {
    if (st.size() == 0) {
        st.push(x);
    } else {
        char a = st.top();
        st.pop();
        insertBottom(x);
        st.push(a);
    }
}

char reverse() {
    if (st.size() > 0) {
        // Hold all items in Function
        // Call Stack until we
        // reach end of the stack
        char x = st.top();
        st.pop();
        reverse();


        // Insert all the items held
        // in Function Call Stack
        // one by one from the bottom
        // to top. Every item is
        // inserted at the bottom
        insertBottom(x);
    }
}

int main() {
    // push elements into
    // the stack
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');

    cout << "Original Stack" << endl;

    // print the elements
    // of original stack
    cout << "1" << " " << "2" << " "
         << "3" << " " << "4"
         << endl;

    // function to reverse
    // the stack
    reverse();
    cout << "Reversed Stack"
         << endl;

    // storing values of reversed
    // stack into a string for display
    while (!st.empty()) {
        char p = st.top();
        st.pop();
        ns += p;
    }

    //display of reversed stack
    cout << ns[3] << " " << ns[2] << " "
         << ns[1] << " " << ns[0] << endl;
    return 0;
}
