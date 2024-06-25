//
// Created by Akshansh Gusain on 26/10/21.
//

#include<stdc++.h>

using namespace std;
int t[100][100];

bool isSubsetSum(int arr[], int sum, int n) {
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
        return t[n - 1][sum] = isSubsetSum(arr, sum, n - 1);
    } else {
        return t[n - 1][sum] = isSubsetSum(arr, sum, n - 1) or isSubsetSum(arr, sum - arr[n - 1], n - 1);
    }
}


int main() {
    memset(t, -1, sizeof(t));
    //int arr[] = { 3, 34, 4, 12, 5, 2 };
    int arr[] = {1, 5, 3, 7, 4};
    //int sum = 9;
    int sum = 12;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isSubsetSum(arr, sum, n))
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}