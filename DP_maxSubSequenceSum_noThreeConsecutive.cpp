//
// Created by Akshansh Gusain on 01/06/21.
//
#include<stdc++.h>

using namespace std;
int dp[200];

int max3C(int *arr, int n) {
    if (n == -1) {
        return 0;
    }
    if (n == 0) {
        return arr[0];
    }
    if (n == 1) {
        return arr[0] + arr[1];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = max(max(max3C(arr, n - 1), arr[n] + max3C(arr, n - 2)), arr[n] + arr[n - 1] + max3C(arr, n - 3));
}

int main() {
    memset(dp,-1,sizeof dp);
    int arr[] = {100, 1000, 100, 1000, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << max3C(arr, n);
    return 0;
}
