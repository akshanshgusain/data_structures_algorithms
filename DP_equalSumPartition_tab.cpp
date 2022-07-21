//
// Created by Akshansh Gusain on 16/05/21.
//
#include<stdc++.h>

using namespace std;

bool equalSumPartitionUtil(int arr[], int n, long sum) {
    bool dp[n + 1][sum + 1];
    int i, j;

    for (i = 0; i < n; i++) {
        dp[i][0] = false;
    }
    for (j = 0; j < n; j++) {
        dp[0][j] = true;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= sum; j++) {
            if (arr[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            }
        }
    }

    return dp[n][sum];
}

bool equalSumPartition(int arr[], int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    if (sum % 2 != 0) {
        return false;
    }
    return equalSumPartitionUtil(arr, n, sum / 2);
}

int main() {

    //int arr[] = {1, 5, 11, 5};
    //int arr[] = {478, 757, 314, 471, 729, 100, 459, 618};
    int arr[] = {3, 1, 1, 2, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << equalSumPartition(arr, n);
    return 0;
}
