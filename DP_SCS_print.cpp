//
// Created by Akshansh Gusain on 24/05/21.
//
#include<stdc++.h>
using namespace std;

vector<char> lcs(string X, string Y, int m, int n){
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    //Print LCS
    vector<char> lcs;
    //lcs[start_index] = '\0';

    //store from the bottom right corner and one by one store chars in lcs[]
    i = m, j = n;
    while(i > 0 and j > 0){
        // if current char in X[i] == Y[j] then this char is part of LCS
        if(X[i-1] == Y[j-1]){
            lcs.push_back( X[i-1]);
            i--, j--;
        }
        else if(L[i-1][j] > L[i][j-1]){
            lcs.push_back(X[i-1]);
            i--;
        }else{
            lcs.push_back(Y[j-1]);
            j--;
        }
    }
    while(i > 0){
        lcs.push_back(X[i-1]);
        i--;
    }
    while(j > 0){
        lcs.push_back(Y[j-1]);
        j--;
    }

    return lcs;


}

int main(){
    string a = "AGGTAB";
    string b = "GXTXAYB";

    int m = a.length();
    int n = b.length();
    vector<char> LCS = lcs(a,b,m,n);
    reverse(LCS.begin(), LCS.end());
    cout<<"LCS is: ";
    for(auto i: LCS){
        cout<<i;
    }
    return 0;
}
