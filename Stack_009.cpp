//
// Created by Akshansh Gusain on 16/03/22.
//


#include<stdc++.h>

using namespace std;


bool areBracketsBalanced(string expr) {
    stack<char> stack;
    char X;
    for (char i : expr) {
        if (i == '(' || i == '['
            || i == '{') {
            // Push the element in the stack
            stack.push(i);
            continue;
        }

        // IF current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (stack.empty()) {
            return false;
        }

        switch (i) {
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

    if (stack.empty()) {
        return true;
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

