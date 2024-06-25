//
// Created by Akshansh Gusain on 21/12/21.
//

#include<stdc++.h>

using namespace std;

int lcs(string X, string Y, int m, int n) {
    int T[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 or j == 0) {
                T[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1] and i != j) {
                T[i][j] = 1 + T[i - 1][j - 1];
            } else {
                T[i][j] = max(T[i - 1][j], T[i][j - 1]);
            }
        }
    }

    return T[m][n];
}

int main() {
    string a = "AABEBCDD";
    const string& b = a;

    int m = a.length();
    int n = b.length();
    cout << "Length of Longest Repeating Sub Sequence is: " << lcs(a, b, m, n);

    return 0;
}