//
// Created by Akshansh Gusain on 22/12/21.
//

#include<stdc++.h>

using namespace std;

int lis(const int arr[], int n) {
    int T[n];

    for (int i = 0; i < n; i++) {
        T[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                T[i] = max(T[i], 1 + T[j]);
            }
        }
    }



    // Find LDS
    int T2[n];
    for (int i = 0; i < n; i++) {
        T2[i] = 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (arr[i] > arr[j]) {
                T2[i] = max(T2[i], T2[j] + 1);
            }
        }
    }

    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxi = max(T[i] + T2[i] - 1, maxi);
    }

    return maxi;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of Longest Bitonic Subsequence: " << lis(arr, n);
    return 0;
}