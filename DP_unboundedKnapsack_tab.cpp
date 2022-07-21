//
// Created by Akshansh Gusain on 18/05/21.
//

//Another variation of this problem is Rod-Cutting Problem
#include<stdc++.h>
using namespace std;

int knapSack(int val[],int wt[], int W, int n){
    int i, j;
    int dp[n+1][W+1];

    for(i = 0; i<= n ;i++){
        for(j =0; j<= W;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }

            if(wt[n-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], val[i] + dp[i][j-wt[i-1]] );
            }
        }
    }

    return dp[n][W];
}

int main(){
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(val, wt , W, n);
    return 0;
}
