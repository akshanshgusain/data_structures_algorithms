//
// Created by Akshansh Gusain on 02/06/21.
//
#include<stdc++.h>
using namespace std;
int dp[1001][1001];

int solve(int i, int j, string s){
    if(i>j)
        return 0;
    if(i==j)
        return 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i] == s[j]){
        return dp[i][j] = solve(i+1, j, s) + solve(i, j-1,s) + 1;
    }else{
        return dp[i][j] = solve(i+1, j, s) + solve(i, j-1,s) - solve(i+1,j-1,s);
    }
}
int main(){
    memset(dp, -1, sizeof dp);
    string s = "aab";
    int n = s.length();

    cout<<solve(0,n-1,s);
    return 0;
}
