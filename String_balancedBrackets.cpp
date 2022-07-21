//
// Created by Akshansh Gusain on 20/01/21.
//
//Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in exp.
//Can be done with stack or 2 pointer technique.

//stack solution

#include<stdc++.h>
using namespace std;

bool areBracketsBalanced(string exp){
     stack<char> s;
     char x;

     for(int i=0; i<exp.length(); i++){
         if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
             s.push(exp[i]);
             continue;
         }

         // if the current element is not and Opening bracket then it must be a closing bracket.
         if(s.empty()){
             return false;
         }

         switch(exp[i]){
             case ')':
                 x= s.top();
                 s.pop();
                 if(x == '{' || x == '['){
                     return false;
                 }
                 break;

             case '}':
                 x= s.top();
                 s.pop();
                 if(x == '(' || x == '['){
                     return false;
                 }
                 break;

             case ']':
                 x= s.top();
                 s.pop();
                 if(x == '{' || x == '('){
                     return false;
                 }
                 break;
         }
     }
     return (s.empty());
}

int main(){

    string expr = "{()}[]";

    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}