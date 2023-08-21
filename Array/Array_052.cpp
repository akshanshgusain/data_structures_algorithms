//
// Created by Akshansh Gusain on 19/01/22.
//

#include<stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {8,1,2,2,3};

    int n = nums.size();
    vector<int> ans;
    int i;
    int bucket[101] = {0};
    for(auto it: nums){
        bucket[it]++;
    }

    for(i = 1 ; i < 100; i++){
        bucket[i] += bucket[i-1];
    }

    for(i = 0; i < n; i++){
        if(nums[i] == 0){
            ans.push_back(0);
        }else{
            ans.push_back(bucket[nums[i]-1]);
        }
    }
    //return ans; //[4,0,1,1,3]
    return 0;
}