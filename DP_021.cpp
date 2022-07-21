//
// Created by Akshansh Gusain on 20/11/21.
//

#include<stdc++.h>

using namespace std;

int lcs(string X, string Y, int m, int n) {
    int t[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 or j == 0) {
                t[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                t[i][j] = 1 + t[i - 1][j - 1];
            } else {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    return t[m][n];
}

int main() {
    string a = "AGGTAB";
    string b = "GXTXAYB";

    int m = a.length();
    int n = b.length();
    cout << "Length of LCS is: " << lcs(a, b, m, n);

    return 0;
}