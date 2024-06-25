//
// Created by Akshansh Gusain on 26/10/21.
//
#include<stdc++.h>

using namespace std;

int knapsack(int val[], int wt[], int W, int n) {
    int t[n + 1][W + 1];
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 and j == 0) {
                t[i][j] = 0;
            }else if(wt[i] > j){
                t[i][j] = t[i-1][j];
            }else{
                t[i][j] = max(t[i-1][j], val[i-1] + t[i-1][j - wt[i-1]]);
            }
        }
    }

    return t[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(val, wt, W, n);
    return 0;
}