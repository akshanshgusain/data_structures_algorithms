//
// Created by Akshansh Gusain on 03/06/21.
//
#include<stdc++.h>
using namespace std;

bool gameWinner(int x, int y, int n){
    bool dp[n+1];
    dp[0] = false;
    dp[1] = true;

    for(int i =2; i<n ;i++){

        //If 1 can be picked and last one to pick was B
        if(i-1 >=0 and dp[i-1]==false){
            dp[i] = true;
        }
        else if(i-x >=0 and dp[i-x] == false){
            dp[i] = true;
        }
        else if(i-y >=0 and dp[i-x] == false){
            dp[i] = true;
        }else{
            dp[i] = false;
        }
    }

    return dp[n];

}

int main(){

    return 0;
}
