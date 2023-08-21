//
// Created by Akshansh Gusain on 19/08/21.
//

#include<stdc++.h>

using namespace std;

// Time: O(N^2), Space: O(N^2)
bool solve(string str, string pattern) {
    int n = str.length();
    int m = pattern.length();

    bool dp[m + 1][n + 1];

    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == m and j == n) {
                dp[i][j] = true;
            } else if (i == m) {
                dp[i][j] = false;
            } else if (j == n) {
                if (pattern[i] == '*') {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = false;
                }
            } else {
                if (pattern[i] == '?') {
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (pattern[i] == '*') {
                    dp[i][j] = dp[i + 1][j] or dp[i][j + 1];
                } else if (pattern[i] == str[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
    }

//    for(int i = 0 ;i <= m ; i++){
//        for(int j = 0; j <= n; j++){
//            cout<<dp[i][j]<<"  ";
//        }
//        cout<<endl;
//    }
    return dp[0][0];
}

int main() {
    string str = "adceb";
    string pattern = "*a*b";
    cout<<solve(str,pattern);
    return 0;
}