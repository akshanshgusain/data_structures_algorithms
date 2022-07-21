//
// Created by Akshansh Gusain on 22/12/21.
//

#include<stdc++.h>

using namespace std;

int lcs(string X, string Y, int m, int n) {
    int T[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if( i == 0 or j == 0){
                T[i][j] = 0;
            }else if(X[i-1] == Y[j-1]){
                T[i][j] = 1 + T[i-1][j-1];
            }else{
                T[i][j] = max(T[i-1][j], T[i][j-1]);
            }
        }
    }
    return T[m][n];
}


int longestPalindromicSubsequence(string a) {
    int n = a.length();
    string b = a;
    reverse(b.begin(), b.end());
    return lcs(a, b, n, b.length());
}

int main() {
    string a = "forgeeksskeegfor";
    cout<<longestPalindromicSubsequence(a);
    return 0;
}
