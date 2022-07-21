//
// Created by Akshansh Gusain on 04/06/21.
//
#include<stdc++.h>

using namespace std;

//int solve(int n) {
//    if (n == 1) {
//        return 0;
//    }
//    if (n == 2) {
//        return 1;
//    }
//
//    return (n-1) * (solve(n-1) + solve(n-2));
//}

//int solve(int n) {
//    int dp[n+1];
//    memset(dp,0,sizeof dp);
//
//    dp[1] = 0;
//    dp[2] = 1;
//
//    for(int i=3; i<= n; i++){
//        dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
//    }
//    return dp[n];
//}

//Space optimised
int solve(int n) {

    int a = 0;
    int b = 1;

    for(int i=3; i<= n; i++){
        int temp = (i-1) * (b+a);
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    cout << solve(4);
    return 0;
}
