//
// Created by Akshansh Gusain on 08/02/24
//
//https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/


#include<stdc++.h>

using namespace std;

int findMaxLen(string input) {
    int n = input.length();

    // Create a stack and push -1 as
    // initial index to it.
    stack<int> stack;
    stack.push(-1);

    // Initialize result
    int result = 0;

    // Traverse all characters of given string
    for (int i = 0; i < n; i++) {
        // If opening bracket, push index of it
        if (input[i] == '(') {
            stack.push(i);
        }
            // If closing bracket, i.e.,str[i] = ')'
        else {
            // Pop the previous opening bracket's index
            if (!stack.empty()) {
                stack.pop();
            }
            // Check if this length formed with base of
            // current valid substring is more than max
            // so far
            if (!stack.empty())
                result = max(result, i - stack.top());

                // If stack is empty. push current index as
                // base for next valid substring (if any)
            else
                stack.push(i);
        }

    }

    return result;
}


int main() {
    string str = "((()()";

    // Function call
    cout << findMaxLen(str) << endl;

    str = "()(()))))";

    // Function call
    cout << findMaxLen(str) << endl;
    return 0;
}

