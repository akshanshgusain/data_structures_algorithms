//
// Created by Akshansh Gusain on 04/06/21.
//
#include<stdc++.h>
using namespace std;
int dp[1001][1001];

bool solve(string a, string b, string c, int n, int m, int len){
    if(len == 0){
        return 1;
    }
    if(n+m != len){
        return 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    int x,y;
    x=y=0;
    if(n-1 >= 0 and a[n-1]==c[len-1]){
        x = solve(a,b,c,n-1,m ,len-1);
    }
    if(m-1 >=0 and b[m-1] ==c[len-1]){
        y = solve(a,b,c,n,m-1,len-1);
    }

    return dp[n][m] = x or y;

}
int main(){
    memset(dp, -1,sizeof(dp));
    string a = "XXY";
    string b = "XXZ";
    string c = "XXZXXXY";
    int n = a.length(), m = b.length(), len = c.length();
    cout<< solve(a,b,c,n,m,len);
    return 0;
}

