//
// Created by Akshansh Gusain on 16/05/21.
//
#include<stdc++.h>
using namespace std;

int dp[200][200];

bool equalSumPartitionUtil(int arr[], int n, long sum) {
    if(n == 0 and sum != 0){
        return false;
    }
    if(sum == 0){
        return true;
    }

    if(dp[n-1][sum] != -1){
        return dp[n-1][sum];
    }

    if (arr[n - 1] > sum) {
        return dp[n-1][sum] = equalSumPartitionUtil(arr, n - 1, sum);
    } else {
        return dp[n-1][sum] = equalSumPartitionUtil(arr, n - 1, sum) ||
        equalSumPartitionUtil(arr, n - 1, sum - arr[n - 1]);
    }
}

bool equalSumPartition(int arr[], int n) {
    long sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    if (sum % 2 != 0){
        return false;
    }
    return equalSumPartitionUtil(arr, n, sum/2);
}

int main() {
    memset(dp, -1, sizeof(dp));
    //int arr[] = {1, 5, 11, 5};
    int arr[] = {478, 757, 314, 471, 729, 100, 459, 618};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << equalSumPartition(arr, n);
    return 0;
}
