//
// Created by Akshansh Gusain on 16/05/21.
//
#include<stdc++.h>
using namespace std;

int countSubsetSum(int arr[], int sum, int n) {
    int dp[n + 1][sum + 1];
    int i, j;


    for (j = 0; j <= sum; j++) {
        dp[0][j] = 0;
    }

    for (i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= sum; j++) {
            if (arr[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    //int arr[] = { 3, 34, 4, 12, 5, 2 };
    int arr[] = {1, 5, 3, 7, 4};
    //int sum = 9;
    int sum = 12;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countSubsetSum(arr, sum, n);
    return 0;
}
