//
// Created by Akshansh Gusain on 20/11/21.
//

//Print the longest common sub sequence
#include<stdc++.h>
using namespace std;



string lcs(string X, string Y, int m, int n){
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
    int start_index = L[m][n];
    char lcs[start_index+1];
    lcs[start_index] = '\0';

    //store from the bottom right corner and one by one store chars in lcs[]
    i = m, j = n;
    while(i > 0 and j > 0){
        // if current char in X[i] == Y[j] then this char is part of LCS
        if(X[i-1] == Y[j-1]){
            lcs[start_index-1] = X[i-1];
            i--, j--, start_index--;
        }
        else if(L[i-1][j] > L[i][j-1]){
            i--;
        }else{
            j--;
        }
    }

    return lcs;
    cout<<"LCS of "<< X <<" and "<<Y<<" is :"<<lcs;

}

int main(){
    string a = "AGGTAB";
    string b = "GXTXAYB";

    int m = a.size();
    int n = b.length();
    cout<<"LCS is: "<<lcs(a,b,m,n);
    return 0;
}
