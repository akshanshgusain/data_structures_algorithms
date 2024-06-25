//
// Created by Akshansh Gusain on 01/11/21.
//
#include<stdc++.h>

using namespace std;

int countSubsetSum(int *arr, int sum, int n) {
    int t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) {
        t[i][0] = 1;
    }
    for (int j = 1; j <= sum; j++) {
        t[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if(arr[i-1] > j){
                t[i][j] = t[i-1][j];
            }else{
                t[i][j] = t[i-1][j] + t[i-1][j - arr[i-1]];
            }
        }
    }

    return t[n][sum];
}

int main() {
    int arr[] = {1, 5, 3, 7, 4};
    //int sum = 9;
    int sum = 12;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countSubsetSum(arr, sum, n);
    return 0;
}
