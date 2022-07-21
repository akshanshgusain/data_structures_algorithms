//
// Created by Akshansh Gusain on 02/06/21.
//Minimum removal from a array to make Max - Min <= K
#include<stdc++.h>
using namespace std;
int dp[1001][1001];

int solve(vector<int> a, int i, int j, int k){
    if(i >= j){
        return 0;
    }
    if((a[j] - a[i]) <= k){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }else{
        return dp[i][j] = 1 + min(solve(a, i+1, j,k), solve(a,i,j-1,k));
    }
}
int main(){
    memset(dp,-1, sizeof dp);
    vector<int> a = {1,3,4,9,10,11,12,17,20};
    int n = a.size();
    int k = 4;
    sort(a.begin(),a.end());

    cout<<solve(a, 0, n-1, k);

    return 0;
}

