//
// Created by Akshansh Gusain on 16/03/22.
//


#include<stdc++.h>
using namespace std;


void sortedInsert(stack<int> &st, int c){
    // Base case: Either stack is empty or newly inserted
    // item is greater than top (more than all existing)
    if(st.empty() or c >st.top()){
        st.push(c);
        return;
    }

    // If top is greater, remove the top item and recur

        int temp = st.top();
        st.pop();
        sortedInsert(st, c);
        st.push(temp);

}

void sortStack( stack<int> &st){

   if(st.empty()){
       return;
   }


       int c = st.top();
       st.pop();

       // Sort remaining stack
       sortStack(st);

       // push the top item back in the sorted stack
       sortedInsert(st, c);

}

int main() {
    stack<int> stack;
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);

    sortStack(stack);

    while(!stack.empty()){
        cout<< stack.top();
        stack.pop();
    }
    return 0;
}

