//
// Created by Akshansh Gusain on 26/10/21.
//

#include<stdc++.h>

using namespace std;
int t[100][100];

int countSubsetSum(int arr[], int sum, int n) {
    if (n == 0) {
        return 0;
    }
    if (sum == 0) {
        return 1;
    }
    if (t[n - 1][sum] != -1) {
        return t[n - 1][sum];
    }

    if (arr[n - 1] > sum) {
        return t[n - 1][sum] = countSubsetSum(arr, sum, n - 1);
    } else {
        return t[n - 1][sum] = countSubsetSum(arr, sum, n - 1) + countSubsetSum(arr, sum - arr[n - 1], n - 1);
    }
}


int main() {
    memset(t, -1, sizeof(t));
    //int arr[] = { 3, 34, 4, 12, 5, 2 };
    int arr[] = {1, 5, 3, 7, 4};
    //int sum = 9;
    int sum = 12;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<countSubsetSum(arr, sum, n);
    return 0;
}