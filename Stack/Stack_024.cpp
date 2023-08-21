//
// Created by Akshansh Gusain on 16/03/22.
//
//https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/
//https://www.youtube.com/watch?v=aMPXhEdpXFA

#include<stdc++.h>

using namespace std;

bool checkRedundancy(string str) {
    stack<char> st;

    for (auto it: str) {

        if (it == ')') {

            // since the expression is balanced,
            // if we find an opening bracket right before a closing bracket
            // that means, it is an extra.
            if (st.top() == '(') {
                return true;
            } else {

                while (st.top() != '(') {
                    st.pop();
                    // pop till you find next opening bracket
                }
                st.pop(); // need to pop opening bracket
            }
        } else {
            st.push(it);
        }
    }

    return false;
}

void findRedundant(string &str) {
    bool ans = checkRedundancy(str);
    if (ans) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

int main() {
    string str = "((a+b))";
    findRedundant(str);

    str = "(a+(b)/c)";
    findRedundant(str);

    str = "(a+b*(c-d))";
    findRedundant(str);
    return 0;
}

