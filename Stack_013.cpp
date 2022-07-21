//
// Created by Akshansh Gusain on 16/03/22.
//


#include<stdc++.h>

using namespace std;

//https://leetcode.com/problems/next-greater-element-ii/

vector<int> nextGreaterElements(vector<int>& A) {
    int n = A.size();
    vector<int> stack, res(n, -1);
    for (int i = 0; i < n * 2; ++i) {
        while (stack.size() && A[stack.back()] < A[i % n]) {
            res[stack.back()] = A[i % n];
            stack.pop_back();
        }
        stack.push_back(i % n);
    }
    return res;
}

int main() {
    string expr = "akshansh_gusain";
    vector<int> input = {11, 13, 21, 3, 22, 7};
    vector<int> result = nextGreaterElements(input);

    for(auto it: result){
        cout<<it<<" ";
    }cout<<endl;

    return 0;
}

