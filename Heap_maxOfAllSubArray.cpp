//
// Created by Akshansh Gusain on 07/04/21.
//
#include<stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    priority_queue<pair<int,int>> heap;

    vector<int> ans;

    for(int i =0; i< nums.size(); i++){
        // (i - k) Window size
        while(!heap.empty() and heap.top().second <= (i-k)){
            heap.pop();
        }
        heap.push(make_pair(nums[i], i));

        if(i >= k-1){
            ans.push_back(heap.top().first);
        }
    }
    return ans;
}

int main(){
    vector<int> a = { 12, 1, 78, 90, 57, 89, 56 };
    int k = 3;
     vector<int> ans = maxSlidingWindow(a, k);
     for(auto t : ans){
         cout<<t<<" ";
     }
    return 0;
}
