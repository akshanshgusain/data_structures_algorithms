//
// Created by Akshansh Gusain on 21/12/21.
//

#include<stdc++.h>

using namespace std;

vector<char> scs(string X, string Y, int m, int n) {
    int T[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 or j == 0) {
                T[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                T[i][j] = T[i - 1][j - 1] + 1;
            } else {
                T[i][j] = max(T[i - 1][j], T[i][j - 1]);
            }
        }
    }

    // Print SCS
    vector<char> scs;
    i = m, j = n;

    while (i > 0 and j > 0) {
        //if current char in X[i] == Y[j] then this char is part of SCS
        if(X[i-1] == Y[j-1]){
            scs.push_back(X[i-1]);
            i--, j--;
        }else if(T[i-1][j] > T[i][j-1]){
            scs.push_back(X[i-1]);
            i--;
        }else{
            scs.push_back(Y[j-1]);
            j--;
        }
    }
    while(i > 0){
        scs.push_back(X[i-1]);
        i--;
    }

    while( j > 0){
        scs.push_back(Y[j-1]);
        j--;
    }

    return scs;
}


int main() {
    string a = "";
    string b = "gxtxayb";
//    string a = "aggtab";
//    string b = "gxtxayb";

    int m = a.length();
    int n = b.length();

    vector<char> SCS = scs(a, b, m, n);
    reverse(SCS.begin(), SCS.end());
    cout << "Shortest Common Super Sequence is:";
    for (auto i: SCS) {
        cout << i;
    }
    return 0;
}