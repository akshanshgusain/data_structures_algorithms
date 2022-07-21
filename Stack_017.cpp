//
// Created by Akshansh Gusain on 16/03/22.
//


#include<stdc++.h>

using namespace std;

int evaluatePostfix(char *exp) {
    stack<char> stack;
    int i;

    for (i = 0; exp[i]; i++) {
        //if the character is blank space then continue
        if (exp[i] == ' ')continue;

            // If the scanned character is an
            // operand (number here),extract the full number
            // Push it to the stack.

        else if (isdigit(exp[i])) {
            int num = 0;

            //extract full number
            while (isdigit(exp[i])) {
                num = num * 10 + (int) (exp[i] - '0');
                i++;
            }
            i--;

            //push the element in the stack
            stack.push(num);

        }
            // If the scanned character is an operator, pop two
            // elements from stack apply the operator
        else {
            int val1 = stack.top();
            stack.pop();
            int val2 = stack.top();
            stack.pop();

            switch (exp[i]) {
                case '+':
                    stack.push(val1 + val2);
                    break;
                case '-':

                    stack.push(val1 - val2);
                    break;
                case '*':

                    stack.push(val1 * val2);
                    break;
                case '/':

                    stack.push(val1 / val2);
                    break;

            }
        }
    }

    return stack.top();
}

int main() {
    char exp[] = "100 200 + 2 / 5 * 7 +";
    cout << evaluatePostfix(exp);
    return 0;
}

