//
// Created by Akshansh Gusain on 16/03/22.
//


#include<stdc++.h>

using namespace std;

// https://leetcode.com/problems/next-greater-element-i/


vector<int> nextGreaterElements(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> map;
    stack<int> st;


    for (int i = 0; i < nums2.size(); i++) {
        while (!st.empty() and nums2[i] > st.top()) {
            map[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++) {
        if (map.find(nums1[i]) == map.end()) {
            ans.push_back(-1);
        } else {
            ans.push_back(map[nums1[i]]);
        }
    }
    return ans;
}

int main() {
    string expr = "akshansh_gusain";
    vector<int> input1 = {4, 1, 2};
    vector<int> input2 = {1, 3, 4, 2};
    vector<int> result = nextGreaterElements(input1, input2);

    for (auto it: result) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

