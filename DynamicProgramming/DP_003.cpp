//
// Created by Akshansh Gusain on 23/01/24.
//

#include<bits/stdc++.h>

using namespace std;

int knapsackMem(vector<int> &val, vector<int> &wt, int W, int n, vector<vector<int>> &dp) {
    if (W == 0 or n == 0) {
        return 0;
    }

    if (dp[W][n] != -1) {
        return dp[W][n];
    }

    // If weight of the nth element is greater than the capacity of the bag then this item cant be included
    if (wt[n - 1] > W) {
        return dp[W][n] = knapsackMem(val, wt, W, n - 1, dp);
    } else {
        return dp[W][n] = max(
                knapsackMem(val, wt, W, n - 1, dp),
                val[n - 1] + knapsackMem(val, wt, W - wt[n - 1], n - 1, dp)
        );
    }
}

int knapsack(vector<int> &val, vector<int> &wt, int W, int n) {
    vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
    int i,j;

    for(i = 0; i <= W; i++){
        for(j = 0; j <= n; j++){
            if(i == 0 or j == 0){
                dp[i][j] = 0;
            }else if(wt[j-1] > i){ // cant pick this item
                dp[i][j] = dp[i][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1], val[j-1] + dp[i-wt[j-1]][j-1]);
            }
        }
    }

   return dp[W][n];
}


int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    vector<vector<int>> dp(W + 1, vector<int>(val.size() + 1, -1));

    cout << knapsackMem(val, wt, W, val.size(), dp)<<endl; //220
    cout << knapsack(val, wt, W, val.size()); //220
    return 0;
}