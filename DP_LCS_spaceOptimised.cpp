//
// Created by Akshansh Gusain on 26/05/21.
//

#include<stdc++.h>
using namespace std;


int lcs(string &X, string &Y) {
    int m = X.length(), n = Y.length();
    int L[2][n + 1];

    // Binary index, used to index current row and previous row.
    bool bi;

    for (int i = 0; i <= m; i++) {

        // Compute current binary index
        bi = i & 1;

        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[bi][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[bi][j] = L[1 - bi][j - 1] + 1;

            else
                L[bi][j] = max(L[1 - bi][j],L[bi][j - 1]);
        }
    }
    return L[bi][n];
}

// Driver code
int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    cout<<"Length of LCS is"<<endl<< lcs(X, Y);
    return 0;
}