//
// Created by Akshansh Gusain on 03/07/21.
//
//Greedy Approach,  time: O(N)

#include<stdc++.h>
using namespace std;

int maxJumps(vector<int> arr){
    int n = arr.size();
    //jumps and steps are not the same
    int maxReachableIndex, jumps, stepsPossible;

    maxReachableIndex = arr[0];
    jumps = 1;
    stepsPossible = arr[0];

    for(int i=1; i<n ; i++){
        if(i == n-1){
            return jumps;
        }
        maxReachableIndex = max(maxReachableIndex, i+arr[i]);
        stepsPossible--;

        if(stepsPossible == 0){
            jumps++;
            if(i >= maxReachableIndex){
                return -1;
            }
            stepsPossible = maxReachableIndex - i;
        }
    }

}

int main(){
    vector<int> arr = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 }; //3
    cout<<maxJumps(arr);
    return 0;
}