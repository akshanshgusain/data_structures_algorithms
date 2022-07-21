//
// Created by Akshansh Gusain on 16/05/21.
//
#include<stdc++.h>
using namespace std;
int dp[200][200];

int countSubsetSum(int arr[], int sum, int n){
    if(n==0 and sum!=0){
        return 0;
    }
    if(sum == 0){
        return 1;
    }

    if(dp[n-1][sum] != -1){
        return dp[n-1][sum];
    }

    if(arr[n-1] > sum){
        return dp[n-1][sum] = countSubsetSum(arr,sum, n-1);
    }else{
        return dp[n-1][sum] = countSubsetSum(arr,sum,n-1)
                + countSubsetSum(arr,sum - arr[n-1], n-1);
    }
}

int main(){
    memset(dp, -1, sizeof(dp));
    //int arr[] = { 3, 34, 4, 12, 5, 2 };
    int arr[] = {1, 5, 3, 7, 4};
    //int sum = 9;
    int sum = 12;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<countSubsetSum(arr, sum, n);
    return 0;
}
