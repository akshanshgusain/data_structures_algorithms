//
// Created by Akshansh Gusain on 28/12/21.
//

#include<stdc++.h>

using namespace std;
int dp[100][100][2];


int solve(string str, int i, int j, int isTrue) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        if (isTrue) {
            return str[i] == 'T';
        } else {
            return str[i] == 'F';
        }
    }

    if(dp[i][j][isTrue]!= -1){
        return dp[i][j][isTrue];
    }
    int ans = 0;

    for (int k = i + 1; k <= j - 1; k = k + 2) {
        int leftF, leftT, rightT, rightF;

        if(dp[i][k-1][1] == -1){
            leftT = solve(str, i, k - 1, true);
        }else{
            leftT = dp[i][k-1][1];
        }
        if(dp[i][k-1][0] == -1){
            leftF = solve(str, i, k - 1, false);
        }else{
            leftF = dp[i][k-1][0];
        }

        if(dp[k+1][j][1] == -1){
            rightT = solve(str, k + 1, j, true);
        }else{
            rightT = dp[k+1][j][1];
        }
        if(dp[k+1][j][0] == -1){
            rightF = solve(str, k + 1, j, false);
        }else{
            rightF = dp[k+1][j][0];
        }


        if (str[k] == '&') {
            if (isTrue) {
                ans = ans + leftT * rightT;
            } else {
                ans = ans + leftT * rightF + leftF * rightT + leftF * rightF;
            }
        } else if (str[k] == '|') {
            if (isTrue) {
                ans = ans + leftT * rightF + leftF * rightT + leftT * rightT;
            } else {
                ans = ans + leftF * rightF;
            }
        } else if (str[k] == '^') {
            if (isTrue) {
                ans = ans + leftT * rightF + leftF * rightT;
            } else {
                ans = ans + leftT * rightT + leftF * rightF;
            }
        }
        dp[i][j][isTrue] = ans;
    }

    return dp[i][j][isTrue];
}

int main() {
    memset(dp, -1, sizeof dp);
    string expression = "T|T&F^T";
    cout << solve(expression, 0, expression.length() - 1, 1);
    return 0;
}