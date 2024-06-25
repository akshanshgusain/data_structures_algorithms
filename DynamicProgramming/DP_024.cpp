//
// Created by Akshansh Gusain on 20/11/21.
//

#include<stdc++.h>

using namespace std;

int longestCommonSubSequence(string X, string Y, int m, int n) {
    int dp[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int shortestSuperSequence(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    int lcs = longestCommonSubSequence(X, Y, m, n);
    int p= m - lcs;
    int q= n - lcs;
    return (lcs + p + q);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    cout << "Length of the shortest supersequence is "
         << shortestSuperSequence(X, Y) << endl;
    return 0;
}