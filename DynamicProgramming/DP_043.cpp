//
// Created by Akshansh Gusain on 24/12/21.
//

#include<stdc++.h>
using namespace std;

//int solve(int *arr, int i, int j) {
//
//    if (i >= j) {
//        return 0;
//    }
//    int mini = INT_MAX;
//
//    for (int k = i; k < j; k++) {
//        int tempAns = solve(arr, i, k) +
//                      solve(arr, k + 1, j) +
//                      arr[i - 1] * arr[k] * arr[j];
//        mini = min(mini, tempAns);
//    }
//
//    return mini;
//}
//
//int matrixChainMultiplication(int *p, int n){
//    int i =1, j = n-1;
//    return solve(p, i, j);
//}
//
//int main() {
//    int arr[] = {1, 2, 3, 4};
//    int n = sizeof arr / sizeof arr[0];
//    cout<<"Min Cost of MCM: "<< matrixChainMultiplication(arr, n);
//    return 0;
//}


int T[1000][1000];

int solve(int *arr, int i, int j) {

    if (i >= j) {
        return 0;
    }
    if(T[i][j] != -1){
        return T[i][j];
    }

    T[i][j] = INT_MAX;
    
    for (int k = i; k < j; k++) {
        T[i][j] = min(T[i][j], solve(arr, i, k) +
                      solve(arr, k + 1, j) +
                      arr[i - 1] * arr[k] * arr[j]);

    }

    return T[i][j];
}

int matrixChainMultiplication(int *p, int n){
    int i =1, j = n-1;
    return solve(p, i, j);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof arr / sizeof arr[0];
    memset(T,-1, sizeof T);
    cout<<"Min Cost of MCM: "<< matrixChainMultiplication(arr, n);
    return 0;
}