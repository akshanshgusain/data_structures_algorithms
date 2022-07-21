//
// Created by Akshansh Gusain on 16/03/22.
//


#include<stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int t){
    if(st.empty()){
        st.push(t);
    }else{
        int c = st.top();
        st.pop();
        insertAtBottom(st, t);
        st.push(c);
    }
}

void reverseStack( stack<int> &st){

    if(st.empty()){
        return;
    }

    int t = st.top();
    st.pop();
    reverseStack(st);

    insertAtBottom(st, t);
}

int main() {
    stack<int> stack;
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);

    reverseStack(stack);

    while(!stack.empty()){
        cout<< stack.top();
        stack.pop();
    }
    return 0;
}

