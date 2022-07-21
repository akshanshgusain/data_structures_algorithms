//
// Created by Akshansh Gusain on 16/03/22.
//


#include<stdc++.h>

using namespace std;


bool areBracketsBalanced(string expr) {
    stack<char> stack;
    char X;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{') {
            // Push the element in the stack
            stack.push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (stack.empty())
            return false;

        switch (expr[i]) {
            case ')':

                // Store the top element in a
                X = stack.top();
                stack.pop();
                if (X == '{' || X == '[')
                    return false;
                break;

            case '}':

                // Store the top element in b
                X = stack.top();
                stack.pop();
                if (X == '(' || X == '[')
                    return false;
                break;

            case ']':

                // Store the top element in c
                X = stack.top();
                stack.pop();
                if (X == '(' || X == '{')
                    return false;
                break;
        }
    }
}

int main() {
    string expr = "{()}[]";

    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}

