//
// Created by Akshansh Gusain on 29/05/21.
//
#include<stdc++.h>
using namespace std;

int eggDrop(int e, int f)
{
    /* A 2D table where entry
    dp[i][j] will represent
    minimum number of trials needed for
    i eggs and j floors. */
    int dp[e + 1][f + 1];
    int res;
    int i, j, x;

    // We need one trial for one floor and 0
    // trials for 0 floors
    for (i = 1; i <= e; i++) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    // We always need j trials for one egg
    // and j floors.
    for (j = 1; j <= f; j++)
        dp[1][j] = j;

    // Fill rest of the entries in table using
    // optimal substructure property
    for (i = 2; i <= e; i++) {
        for (j = 2; j <= f; j++) {
            dp[i][j] = INT_MAX;
            for (x = 1; x <= j; x++) {
                res = 1 + max(
                        dp[i - 1][x - 1],
                        dp[i][j - x]);
                if (res < dp[i][j])
                    dp[i][j] = res;
            }
        }
    }

    // dp[e][f] holds the result
    return dp[e][f];
}


int main(){
    int n = 2, k = 36;
    printf("\nMinimum number of trials "
           "in worst case with %d eggs and "
           "%d floors is %d \n",
           n, k, eggDrop(n, k)); //8
    return 0;
}

