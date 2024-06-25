//
// Created by Akshansh Gusain on 21/12/21.
//

#include<stdc++.h>
using namespace std;

int lcs(string X, string Y, string Z, int m, int n, int o ){
    int T[m+1][n+1][o+1];
    int i, j, k;

    for(i = 0; i <= m; i++){
        for(j = 0; j <= n; j++){
            for(k =0; k <= o; k++){
                if(i == 0 or j ==0 or k == 0){
                    T[i][j][k] = 0;
                }else if( X[i-1] == Y[j-1] and X[i-1] == Z[k-1] and Y[j-1]==Z[k-1]){
                    T[i][j][k] = 1 + T[i-1][j-1][k-1];
                }else{
                    T[i][j][k] = max(max(T[i-1][j][k], T[i][j-1][k]), T[i][j][k-1]);
                }
            }
        }
    }
    return T[m][n][o];
}


int main(){
    string X = "AGGT12";
    string Y = "12TXAYB";
    string Z = "12XBA";

    int m = X.length();
    int n = Y.length();
    int o = Z.length();

    cout << "Length of LCS is " << lcs(X, Y, Z, m, n, o);
    return 0;
}