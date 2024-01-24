//
// Created by Akshansh Gusain on 13/05/21.
//
#include<stdc++.h>

using namespace std;

int dp[200][200];

int knapSack(int val[], int wt[], int W, int n) {

    if (W == 0 or n == 0) {
        return 0;
    }

    if (dp[W][n] != -1) {
        return dp[W][n];
    }

    //If weight of the nth element is greater than the capacity of the bag then this item cant be included
    if (wt[n - 1] > W) {
        return dp[W][n] = knapSack(val, wt, W, n - 1);
    } else {
        return dp[W][n] = max(knapSack(val, wt, W, n - 1), val[n - 1] +
                                                           knapSack(val, wt, W - wt[n - 1], n - 1));
    }
}


int main() {
    memset(dp, -1, sizeof(dp));
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(val, wt, W, n); //220
    return 0;
}
