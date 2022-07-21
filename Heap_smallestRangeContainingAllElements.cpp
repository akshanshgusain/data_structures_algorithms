//
// Created by Akshansh Gusain on 08/04/21.
//https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

#include<stdc++.h>

using namespace std;

#define d pair<int,pair<int,int>>


vector<int> smallestRange(vector<vector<int>> &nums) {
    int n = nums.size();


    priority_queue<d, vector<d>, greater<d>> pq;
    int end = INT_MIN;
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        pq.push({nums[i][0], {i, 0}});

        end = max(nums[i][0], end);

    }
    int fir;
    int sec;
    while (!pq.empty()) {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();

        if (end - p.first < ans) {
            fir = p.first;
            sec = end;
            ans = end - p.first;
        }

        if (nums[p.second.first].size() - 1 > p.second.second) {
            int idx = p.second.second + 1;
            pq.push({nums[p.second.first][idx], {p.second.first, idx}});
            end = max(end, nums[p.second.first][idx]);

        } else {
            break;
        }


    }
    return {fir, sec};
}


int main() {

    vector<vector<int>>  arr= {
            {4, 7,  9,  12, 15},
            {0, 8,  10, 14, 20},
            {6, 12, 16, 30, 50}
    };

    vector<int> sol  = smallestRange(arr);
    for(auto a:sol){
        cout<<a<<" ";
    }
    return 0;
}