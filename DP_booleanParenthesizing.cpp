//
// Created by Akshansh Gusain on 28/05/21.
//
#include<stdc++.h>

using namespace std;
int dp[100][100][2];

int parenthesis_count(string s,int i,int j,int isTrue) {
    // Base Condition
    if (i > j)
        return false;
    if (i == j) {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2) {
        int leftF, leftT, rightT, rightF;
        if (dp[i][k - 1][1] == -1) {
            leftT = parenthesis_count(s, i, k - 1, 1);
        } // Count no. of T in left partition
        else {
            leftT = dp[i][k - 1][1];
        }

        if (dp[k + 1][j][1] == -1) {
            rightT = parenthesis_count(s, k + 1, j, 1);
        } // Count no. of T in right partition
        else {
            rightT = dp[k + 1][j][1];
        }

        if (dp[i][k - 1][0] == -1) {
            // Count no. of F in left partition
            leftF = parenthesis_count(s, i, k - 1, 0);
        } else {
            leftF = dp[i][k - 1][0];
        }

        if (dp[k + 1][j][0] == -1) {
            // Count no. of F in right partition
            rightF = parenthesis_count(s, k + 1, j, 0);
        } else {
            rightF = dp[k + 1][j][0];
        }

        if (s[k] == '&') {
            if (isTrue == 1)
                ans += leftT * rightT;
            else
                ans += leftF * rightF + leftT * rightF
                       + leftF * rightT;
        } else if (s[k] == '|') {
            if (isTrue == 1)
                ans += leftT * rightT + leftT * rightF
                       + leftF * rightT;
            else
                ans = ans + leftF * rightF;
        } else if (s[k] == '^') {
            if (isTrue == 1)
                ans = ans + leftF * rightT + leftT * rightF;
            else
                ans = ans + leftT * rightT + leftF * rightF;
        }
        dp[i][j][isTrue] = ans;
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    string expression = "T|T&F^T"; //4
    cout << parenthesis_count(expression, 0, expression.length() - 1, true);
    return 0;
}
