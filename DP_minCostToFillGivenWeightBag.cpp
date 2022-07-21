//
// Created by Akshansh Gusain on 02/06/21.
//
#include<stdc++.h>
using namespace std;
int dp[1001][1001];

int solve(vector<int> arr, int N, int W){
        if(N==-1 and W==0){
            return 0;
        }
        if(N == -1){
            return 1e9;
        }
        if(dp[N][W] != -1){
            return dp[N][W];
        }
        if((N+1) > W or arr[N] == -1){
            return dp[N][W] = solve(arr, N-1, W);
        }
        else{
            return dp[N][W] = min(solve(arr, N-1, W),
                                  arr[N] + solve(arr, N, W - (N+1)));
        }
}

int main(){
    memset(dp, -1, sizeof dp);
    int N = 5;
    int W = 5;
    vector<int> arr = {20,10,4,50,100};
    cout<<solve(arr,N,W);
    return 0;
}
