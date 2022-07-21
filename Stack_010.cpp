//
// Created by Akshansh Gusain on 16/03/22.
//


#include<stdc++.h>

using namespace std;

string reverseString(string input){
    stack<char> stack;

    for(char i : input){
        stack.push(i);
    }
    int i = 0;

    while(!stack.empty()){
        input[i] = stack.top();
        stack.pop();
        i++;

    }
    return input;
}

int main() {
    string expr = "akshansh_gusain";
    cout<<reverseString(expr);
    return 0;
}

