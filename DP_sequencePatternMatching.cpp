//
// Created by Akshansh Gusain on 26/05/21.
//

#include<stdc++.h>
using namespace std;

int lcs(string X, string Y, int m, int n){
    int dp[m+1][n+1];
    int i,j;

    for(i = 0; i<= m; i++){
        for(j =0; j<= n; j++){
            if(i==0 or j==0){
                dp[i][j] = 0;
            }
            else if(X[i-1] == Y[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}
int main(){
    string a = "AXY";
    string b = "ADXCPY";
    int m = a.length();
    int n = b.length();
    int len_lcs = lcs(a,b,m,n);
    if(m == len_lcs){
        cout<<"Pattern Found";
    }else{
        cout<<"Pattern Not Found";
    }
    return 0;
}
