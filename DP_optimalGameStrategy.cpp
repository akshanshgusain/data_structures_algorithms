//
// Created by Akshansh Gusain on 04/06/21.
//
#include<stdc++.h>
using namespace std;
int dp[1001][1001];

int solve(vector<int> arr, int i, int j){
   if(i > j){
       return 0;
   }
   if(dp[i][j] != -1){
       return dp[i][j];
   }else{
       return dp[i][j] = max( arr[i]+ min(solve(arr, i+2, j), solve(arr, i+1, j-1)),
                              arr[j] + min(solve(arr,i,j-2), solve(arr,i+1, j-1)));
   }
}

int main(){
    memset(dp, -1, sizeof(dp));
    vector<int> arr = { 8, 15, 3, 7 };
    int n = arr.size();
    cout<<solve(arr, 0, n-1);
    return 0;
}
