//
// Created by Akshansh Gusain on 22/12/21.
//


#include<stdc++.h>

using namespace std;

int lis(const int arr[], int n) {
    int T[n + 1];
    for (int i = 1; i <= n; i++) {
        T[i] = INT_MAX;
    }
    T[0] = INT_MIN;

    for (int i = 0; i < n; i++) {
        // upper1 = std::upper_bound(v.begin(), v.end(), 35);
        // int idx = upper1 - v.begin();
        int idx = upper_bound(T, T + n + 1, arr[i]) - T;
        if (arr[i] > T[idx - 1] and arr[i] < T[idx]) {
            T[idx] = arr[i];
        }
    }

    int ma = 0;
    for(int i=n; i >= 0; i--){
        if(T[i] != INT_MAX){
            ma = i;
            break;
        }
    }
    return ma;

}

int main() {
    int arr[] = {10, 9, 4, 5, 4, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum deletions = " << n - lis(arr, n);
    return 0;
}
