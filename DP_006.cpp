//
// Created by Akshansh Gusain on 26/10/21.
//
#include<stdc++.h>

using namespace std;
int t[200][200];

bool subsetSum(int arr[], int n, int sum) {
    if (n == 0) {
        return false;
    }
    if (sum == 0) {
        return true;
    }
    if (t[n - 1][sum] != -1) {
        return t[n - 1][sum];
    }

    if (arr[n - 1] > sum) {
        return t[n - 1][sum] = subsetSum(arr, n - 1, sum);
    } else {
        return t[n - 1][sum] = (subsetSum(arr, n - 1, sum) or subsetSum(arr, n - 1, sum - arr[n - 1]));
    }
}

bool equalSumPartition(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    if (sum % 2 != 0) {
        return false;
    } else {
        return subsetSum(arr, n, sum / 2);
    }
}

int main() {
    memset(t, -1, sizeof(t));
    //int arr[] = {1, 5, 11, 5};
    int arr[] = {478, 757, 314, 471, 729, 100, 459, 618};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << equalSumPartition(arr, n);
    return 0;
}
