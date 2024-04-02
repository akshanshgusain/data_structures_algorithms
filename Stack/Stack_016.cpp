//
// Created by Akshansh Gusain on 16/03/22.
//


#include<stdc++.h>

using namespace std;


// Function to find precedence of
// operators.
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to perform arithmetic operations.
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            return a / b;
    }
}

// Function that returns value of
// expression after evaluation.

// Shunting Yard Algorithm
int evaluate(string token) {

    // stack to store integer values.
    stack<int> values;

    // stack to store operators.
    stack<char> operators;

    for (int i = 0; i < token.length(); i++) {

        // If Current char is a white space
        if (token[i] == ' ') {
            continue;
        }

            // If current char is an opening brace, push it to 'operators'
        else if (token[i] == '(') {
            operators.push(token[i]);
        }

            // If current char is a number push it to value stack
        else if (isdigit(token[i])) {
            int val = 0;

            // There may be more than one digit in number.
            while (i < token.length() && isdigit(token[i])) {
                val = (val * 10) + (token[i] - '0');
                i++;
            }

            values.push(val);
            // right now the i points to the character next to the digit, since the for loop also increases
            // the i, we would skip one token position; we need to
            // decrease the value of i by 1 to correct the offset.
            i--;
        }
            // Closing brace encountered, solve
            // entire brace.
        else if (token[i] == ')') {
            while (!operators.empty() and operators.top() != '(') {

                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = operators.top();
                operators.pop();

                values.push(applyOp(val1, val2, op));
            }

            // pop opening brace.
            if (!operators.empty()) {
                operators.pop();
            }

        } else {
            // If current token is an operator

            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while (!operators.empty() && precedence(operators.top())
                                         >= precedence(token[i])) {

                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = operators.top();
                operators.pop();

                values.push(applyOp(val1, val2, op));
            }
            // Push current token to 'ops'.
            operators.push(token[i]);
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.

    // Simple postfix evaluation
    while (!operators.empty()) {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = operators.top();
        operators.pop();

        values.push(applyOp(val1, val2, op));
    }
    // Top of 'values' contains result, return it.
    return values.top();
}

int main() {
    cout << evaluate("10 + 2 * 6") << "\n";
    cout << evaluate("100 * 2 + 12") << "\n";
    cout << evaluate("100 * ( 2 + 12 )") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14");

    return 0;
}

