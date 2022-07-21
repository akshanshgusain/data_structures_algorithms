//
// Created by Akshansh Gusain on 31/05/21.
//
#include<stdc++.h>
using namespace std;

unsigned long int catalanNumber(int n){

    unsigned long int dp[n+1];
    dp[0] = dp[1] =1;

    for(int i=2; i<= n; i++){
        dp[i] = 0;
        for(int j=0; j<i; j++){
            dp[i] += dp[j] + dp[i-j-1];
        }
    }

    return dp[n];
}

int main(){
    int n = 10;
    cout<<catalanNumber(n);
    return 0;
}
