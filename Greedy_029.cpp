//
// Created by Akshansh Gusain on 13/09/22.
//
#include<bits/stdc++.h>

using namespace std;


int maxSum(vector<int> &stack1, vector<int> &stack2, vector<int> &stack3, int n1, int n2, int n3) {
    int sum1 = 0, sum2 = 0, sum3 = 0;

    // Finding the initial sum of stack1.
    for (int i = 0; i < n1; i++)
        sum1 += stack1[i];

    // Finding the initial sum of stack2.
    for (int i = 0; i < n2; i++)
        sum2 += stack2[i];

    // Finding the initial sum of stack3.
    for (int i = 0; i < n3; i++)
        sum3 += stack3[i];

    // As given in question, first element is top
    // of stack..
    int top1 = 0, top2 = 0, top3 = 0;
    while (true) {
        // If any stack is empty
        if (top1 == n1 || top2 == n2 || top3 == n3)
            return 0;

        // If sum of all three stack are equal.
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;

        // Finding the stack with maximum sum and
        // removing its top element.
        if (sum1 >= sum2 && sum1 >= sum3)
            sum1 -= stack1[top1++];
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= stack2[top2++];
        else if (sum3 >= sum2 && sum3 >= sum1)
            sum3 -= stack3[top3++];
    }
}

// Driven Program
int main() {
    vector<int> stack1 = {3, 2, 1, 1, 1};
    vector<int> stack2 = {4, 3, 2};
    vector<int> stack3 = {1, 1, 4, 1};


    cout << maxSum(stack1, stack2, stack3, stack1.size(), stack2.size(), stack3.size()) << endl;
    return 0;
}