//
// Created by Akshansh Gusain on 16/03/22.
//


#include<stdc++.h>

using namespace std;

//https://leetcode.com/problems/next-greater-element-ii/

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> stack;
    vector<int> res(n,-1);
    for(int i =0 ; i < n*2; ++i){
        while( !stack.empty() and nums[stack.top()] < nums[i%n]){
            res[stack.top()] = nums[i%n];
            stack.pop();
        }
        stack.push(i%n);
    }

    return res;
}

int main() {
    string expr = "akshansh_gusain";
    vector<int> input = {1,2,3,4,3};
    // 2 3 4 -1 4
    vector<int> result = nextGreaterElements(input);

    for(auto it: result){
        cout<<it<<" ";
    }cout<<endl;

    return 0;
}

