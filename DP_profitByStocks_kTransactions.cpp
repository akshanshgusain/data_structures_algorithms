//
// Created by Akshansh Gusain on 04/06/21.
//
#include<stdc++.h>
using namespace std;

int maxProfit(vector<int> prices, int n, int k){
    int dp[k+1][n+1];
    int i,j;
    for( i = 0; i<=k; i++){
        dp[i][0] = 0;
    }
    for(i=0; i <=n ;i++){
        dp[0][i] = 0;
    }

    for(i =1; i<= k; i++){
        for(j= 1; j<n; j++){
            int maxTH = INT_MIN;

            for(int m = 0; m<j; m++){
                maxTH = max( maxTH, prices[j]- prices[m] + dp[i-1][m]);
            }
            dp[i][j] = max(maxTH, dp[i][j-1]);
        }
    }
    return dp[k][n-1];
}

int main(){
    int k =2;
    vector<int> prices = { 10, 22, 5, 75, 65, 80 };
    int n = prices.size();
    cout<<"Max profit: "<<maxProfit(prices,n, k);
    return 0;
}
