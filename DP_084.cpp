//
// Created by Akshansh Gusain on 07/01/22.
//
//https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/

// Greedy Won't work here because: check out this case:->
// 8, 15, 3, 7 : The user collects maximum value as 22(7 + 15)
/*
1. …….User chooses 8.
…….Opponent chooses 15.
…….User chooses 7.
…….Opponent chooses 3.
Total value collected by user is 15(8 + 7)

2. …….User chooses 7.
…….Opponent chooses 8.
…….User chooses 15.
…….Opponent chooses 3.
Total value collected by user is 22(7 + 15)
 */

/*
 F(i, j) represents the maximum value the user
can collect from i'th coin to j'th coin.

F(i, j) = Max(Vi + min(F(i+2, j), F(i+1, j-1) ),
              Vj + min(F(i+1, j-1), F(i, j-2) ))
As user wants to maximise the number of coins.

Base Cases
    F(i, j) = Vi           If j == i
    F(i, j) = max(Vi, Vj)  If j == i + 1
 */
#include<stdc++.h>

using namespace std;
int dp[1001][1001];

int solve(int arr[], int i, int j) {

    if (i > j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    } else {
        return dp[i][j] = max(arr[i] + min(solve(arr, i + 2, j), solve(arr, i + 1, j - 1)),
                              arr[j] + min(solve(arr, i, j - 2), solve(arr, i + 1, j - 1)));
    }

}

int main() {
    memset(dp, -1, sizeof(dp));
    int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout << solve(arr1, 0, n-1);
    return 0;
}