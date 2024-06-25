//
// Created by Akshansh Gusain on 22/12/21.
// https://www.youtube.com/watch?v=qEh5uA8sx8w&t

#include<stdc++.h>

using namespace std;

int lis(const int arr[], int n){
    int T[n];
    for(int i =0; i < n; i++){
        T[i] =1;
    }

    for( int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if(arr[j] < arr[i]){
                T[i] = max(T[i], 1 + T[j]);
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
    int arr[] = {10, 9, 4, 5, 4, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of LIS: " << lis(arr, n);
    return 0;
}
