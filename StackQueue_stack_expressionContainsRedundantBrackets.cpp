//
// Created by Akshansh Gusain on 04/04/21.
//Given a string of balanced expression, find if it contains a redundant parenthesis or not.

//If immediate pop hits a open parenthesis ‘(‘, then we have found a duplicate parenthesis. For example, (((a+b))+c) has duplicate brackets around a+b.
// When we reach second “)” after a+b, we have “((” in the stack. Since the top of stack is a opening bracket, we conclude that there are duplicate brackets.

//If immediate pop doesn’t hit any operand(‘*’, ‘+’, ‘/’, ‘-‘) then it indicates the presence of unwanted brackets surrounded by expression. For instance,
// (a)+b contain unwanted () around a thus it is redundant.

#include<stdc++.h>
using namespace std;

bool checkRedundancy(string& str)
{
    // create a stack of characters
    stack<char> st;

    // Iterate through the given expression
    for (auto& ch : str) {

        // if current character is close parenthesis ')'
        if (ch == ')') {
            char top = st.top();
            st.pop();

            // If immediate pop have open parenthesis '('
            // duplicate brackets found
            bool flag = true;

            while (top != '(') {

                // Check for operators in expression
                if (top == '+' || top == '-' ||
                    top == '*' || top == '/')
                    flag = false;

                // Fetch top element of stack
                top = st.top();
                st.pop();
            }

            // If operators not found
            if (flag == true)
                return true;
        }

        else
            st.push(ch); // push open parenthesis '(',
        // operators and operands to stack
    }
    return false;
}

void findRedundant(string& str){
    bool ans = checkRedundancy(str);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main(){

    string str = "((a+b))";
    findRedundant(str);

    str = "(a+(b)/c)";
    findRedundant(str);

    str = "(a+b*(c-d))";
    findRedundant(str);

    return 0;
}
