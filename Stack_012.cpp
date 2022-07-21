//
// Created by Akshansh Gusain on 16/03/22.
//


#include<stdc++.h>

using namespace std;

void nextGreater(vector<int> &input) {
    stack<int> stack;

    stack.push(input[0]);

    for (int i = 1; i < input.size(); i++) {

        while (!stack.empty() and stack.top() < input[i]) {
            cout << stack.top() << " -->" << input[i]<<endl;
            stack.pop();
        }

        stack.push(input[i]);
    }

    while (!stack.empty()) {
        cout << stack.top() << " -->" << "-1"<<endl;
        stack.pop();
    }
}

int main() {
    string expr = "akshansh_gusain";
    vector<int> input = {11, 13, 21, 3, 22, 7};
    nextGreater(input);
    return 0;
}

