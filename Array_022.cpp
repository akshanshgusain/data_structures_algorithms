//
// Created by Akshansh Gusain on 12/07/21.
//

// Time : O(N), Space:O(N)

// The idea is to iterate through the array and for every element arr[i], calculate the sum of elements from 0 to i
// If the current sum has been seen before, then there is a zero-sum array.
// Hashing is used to store the sum values so that we can quickly store sum and find out whether the current
// sum is seen before or not.


#include<stdc++.h>
using namespace std;

bool subArrayExists(vector<int> arr){
    int n = arr.size();
    unordered_set<int> preSum;

    int sum = 0;
    for(int i = 0; i < n ; i++){
        sum += arr[i];

        if(sum ==0 or preSum.find(sum) != preSum.end()){
           return true;
        }
        preSum.insert(sum);
    }
    return false;
}

int main(){
    vector<int> arr = {-3, 2, 3, 1, 6};
    if(subArrayExists(arr)){
        cout<<"Found a subArray with 0 sum";
    }else{
        cout<<"No subArray with 0 sum is found";
    }
    return 0;
}
