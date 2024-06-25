//
// Created by Akshansh Gusain on 20/11/21.
//

#include<stdc++.h>
using namespace std;
int t[100][100];

int lcs(string a, string b, int m, int n){
    if( m==0 or n==0){
        return 0;
    }
    if(t[n-1][m-1] != -1){
        return t[n-1][m-1];
    }
    if(a[m-1] == b[n-1]){
        return  t[n-1][m-1] = 1 + lcs(a,b,m-1,n-1);
    }else{
        return t[n-1][m-1] = max(lcs(a,b, m-1, n), lcs(a,b,m, n-1));
    }
}

int main(){
    memset(t , -1, sizeof t);
    string a = "AGGTAB";
    string b = "GXTXAYB";

    int m = a.length();
    int n = b.length();
    cout<<"Length of LCS is: "<<lcs(a,b,m,n);

    return 0;
}
