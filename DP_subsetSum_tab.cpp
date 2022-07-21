//
// Created by Akshansh Gusain on 13/05/21.
//
#include<stdc++.h>
using namespace std;



bool isSubsetSum(int arr[], int sum, int n){

    int i,j;
    bool dp[n+1][sum+1];

    for(j = 0; j <= sum; j++){
        dp[0][j] = false;
    }

    for(i = 0; i <= n; i++){
        dp[i][0] = true;
    }


    for(i = 1; i <= n ;i ++){
        for(j = 1; j <= sum ; j++){
            if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            }
        }
    }

    return dp[n][sum];
}

int main(){
    //int arr[] = { 3, 34, 4, 12, 5, 2 };
    int arr[] = {1, 5, 3, 7, 4};
    //int sum = 9;
    int sum = 12;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isSubsetSum(arr, sum, n))
        cout<<"Found a subset with given sum";
    else
        cout<<"No subset with given sum";
    return 0;
}