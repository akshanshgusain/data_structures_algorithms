//
// Created by Akshansh Gusain on 01/07/21.
//
// Print K rotated Array
/*
 * 1. We will first take mod of K by N (K = K % N) because after every N rotations array will become the same as
      the initial array.
 * 2. Now, we will iterate the array from i = 0 to i = N-1 and check,
      If i < K, Print rightmost Kth element (a[N + i -K]). Otherwise,
      Print array after ‘K’ elements (a[i – K]).
 */

#include<stdc++.h>
using namespace std;

void printKRotatedArray(int a1[], int n, int k){
    k = (k%n);

    for(int i= 0; i<n; i++){
        if(i < k){
            cout<< a1[n-k+i] << " ";
        }else{
            cout<< a1[i-k]<< " ";
        }
    }
}

int main() {
    int Array[] = { 1, 2, 3, 4, 5 };
    int N = sizeof(Array) / sizeof(Array[0]);
    int K = 2;
    printKRotatedArray(Array, N, K);
    return 0;
}