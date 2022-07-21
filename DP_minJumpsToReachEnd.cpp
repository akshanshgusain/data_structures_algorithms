//
// Created by Akshansh Gusain on 01/06/21.
//
// Similar to LIS
#include<stdc++.h>
using namespace std;
//dp[i] will contain min. jumps from start to ith position

int minJumps(vector<int> arr){
    int n = arr.size();
    int dp[n];
    for(int i =0; i<n;i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for(int i = 1 ;i < n; i++){
        for(int j = 0; j < i ; j++){
            if(dp[j] != INT_MAX and (arr[j]+j >= i)){
                if(dp[j] + 1 < dp[i]){
                    dp[i] = dp[j]+1;
                }
            }
        }
    }
    if(dp[n-1] != INT_MAX) {
        return dp[n-1];
    }
    else{
        return -1;
    }

}


int main(){
    vector<int> arr = {1, 3, 6, 1, 0, 9 };
    cout<<"Mini. number of jumps to reach end is: "<< minJumps(arr);
    return 0;
}

