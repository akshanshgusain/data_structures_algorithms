//
// Created by Akshansh Gusain on 25/05/21.
//

#include<stdc++.h>

using namespace std;

int lcs(string str1, string str2, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (str1.at(i - 1) == str2.at(j - 1))
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

int lps(string a) {
    int n = a.length();
    string b = a;
    reverse(b.begin(), b.end());
    int len = lcs(a, b, n, b.length());
    return len;
}

int main() {
    //string a = "agbcba";
    string a = "forgeeksskeegfor";
    cout<<lps(a);
    return 0;
}