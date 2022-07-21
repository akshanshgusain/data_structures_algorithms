//
// Created by Akshansh Gusain on 22/12/21.
//


#include<stdc++.h>

using namespace std;

int lis(const int arr[], int n) {
    int T[n];
    for(int i =0; i < n; i++){
        T[i] = arr[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if(arr[j] < arr[i]){
                T[i] = max(T[i], arr[i] + T[j]);
            }
        }
    }

    int maxi = INT_MIN;
    for(int i =0; i < n; i++){
        maxi = max(maxi, T[i]);
    }

    return maxi;
}

int main() {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of Longest increasing sum subsequence: " << lis(arr, n);
    return 0;
}
