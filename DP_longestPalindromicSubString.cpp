//
// Created by Akshansh Gusain on 02/06/21.
//
#include<stdc++.h>
using namespace std;

string longestPalSubString(string str){
    int n = str.length();
    int i, j, maxLength = 0;

    bool dp[n][n];
    memset(dp, 0, sizeof dp);

    //All sub strings of length 1 are palindrome
    for(i =0; i<n; i++){
        dp[i][i] = str[i];
    }
    maxLength=1;
    //check for all the substrings of length 2
    int start = 0;
    for(i = 0; i< n-1; i++){
        if(str[i] == str[i+1]){
            dp[i][i+1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    //Check for all length more than 2
    for(int k = 3; k<=n; k++){
        for(int i=0; i < n-k+1; i++){
            j = i + k - 1;

            if(dp[i+1][j-1] and str[i] == str[j]){
                dp[i][j] = 1;
                if(k > maxLength){
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    return str.substr(start,maxLength);
}

int main(){
    //string str = "forgeeksskeegfor";
    string str = "aaaabbaa";
    cout<<longestPalSubString(str);
    return 0;
}
