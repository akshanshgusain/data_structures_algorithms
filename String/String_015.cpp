//
// Created by Akshansh Gusain on 06/08/21.
//
#include <stdc++.h>

using ll = long long;
using namespace std;

bool areBracketsBalanced(string expr) {
    stack<char> s;
    char ch;

    for (char & i : expr) {
        if (i == '{' or i == '[' or i == '(') {
            s.push(i);
            continue;
        }

        if (s.empty()) {
            return false;
        }

        switch (i) {
            case '}':
                ch = s.top();
                s.pop();
                if(ch == '(' or ch =='[')
                    return false;
                break;
            case ']':
                ch = s.top();
                s.pop();
                if(ch == '(' or ch =='{')
                    return false;
                break;
            case ')':
                ch = s.top();
                s.pop();
                if(ch == '{' or ch =='[')
                    return false;
        }
    }

    return (s.empty());
}

int main() {

    string expr = "{()}[]{";

    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;

}