//
// Created by Akshansh Gusain on 24/05/21.
//
#include<stdc++.h>

using namespace std;


int lcs(string X, string Y, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;
    int result = 0;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
                result = max(result, L[i][j]);
            } else
                L[i][j] = 0;
        }
    }

    return result;
}

int main() {
    string a = "OldSite:GeeksforGeeks.org";
    string b = "NewSite:GeeksQuiz.com";

    int m = a.length();
    int n = b.length();
    cout << "Length of LCS is: " << lcs(a, b, m, n);
    return 0;
}
