//
// Created by Akshansh Gusain on 31/05/21.
//
#include<stdc++.h>
using namespace std;

int countFriendsPair(int n){
    int dp[n+1], i;
    for(i = 0; i<= n; i++){
        if(i <= 2){
            dp[i] = i;
        }else {
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
        }
    }

    return dp[n];
}


int main(){
    int n= 4;
    cout<<"Pairs: "<<countFriendsPair(n)<<endl;
    return 0;
}

