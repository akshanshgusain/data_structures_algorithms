//
// Created by Akshansh Gusain on 08/02/24
//


#include<stdc++.h>

using namespace std;

int evaluatePostfix(string exp) {
    stack<int> stack;

    for (int i = 0; i < exp.size(); i++) {
        //if the character is blank space then continue
        if (exp[i] == ' '){
            continue;
        }

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
            cout<<"number found: "<<num<<endl;
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

            // we need to divide larger val from smaller value
            if(val2 > val1){
                swap(val1, val2);
            }

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
    string exp = "100 200 + 2 / 5 * 7 +";
    cout << evaluatePostfix(exp);
    return 0;
}

