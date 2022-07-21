//
// Created by Akshansh Gusain on 12/11/21.
//

//
// Created by Akshansh Gusain on 12/11/21.
//
#include<stdc++.h>
using namespace std;

int minCoins(vector<int> coins, int value){
    int n = coins.size();
    int dp[n+1][value+1];

    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=value;++j)
        {
            if(j==0)
                dp[i][j] = 0;
            else if(i==0)
                dp[i][j] = 1e5;
            else if(coins[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
        }
    }
    return dp[n][value]>1e4 ? -1:dp[n][value];

}

int main(){
    vector<int> coins = {9, 6, 5, 1};
    int value = 11;
    cout<<"Minimum coins required is: "<<minCoins(coins, value);
    return 0;
}
