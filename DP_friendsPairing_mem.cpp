//
// Created by Akshansh Gusain on 31/05/21.
//
#include<stdc++.h>
using namespace std;
int dp[100];

int countFriendPair(int n){
    if(n <= 2){
        return dp[n] = n;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    //if paired with itself + if paired with rest of the remaining elements
    return dp[n] = 1 * countFriendPair(n-1) + (n-1)* countFriendPair(n-2);
}

int main(){
    memset(dp,-1,sizeof dp);
    int n = 4;
    cout << countFriendPair(n) << endl;
    return 0;
}