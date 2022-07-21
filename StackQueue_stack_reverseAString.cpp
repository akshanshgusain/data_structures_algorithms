//
// Created by Akshansh Gusain on 02/04/21.
//
#include<stdc++.h>
using namespace std;

string reverseString(string s){
    stack<char> stack;

    for(int i =0; i<s.length(); i++){
        stack.push(s[i]);
    }

    string reversedString ="";
    char X;
    for(int i =0; i<s.length(); i++){
        reversedString = reversedString + stack.top();
        stack.pop();
    }
    return reversedString;
}

int main(){
    string s = "Akshansh Gusain";
    cout<<reverseString(s);
    return 0;
}
