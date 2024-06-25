//
// Created by Akshansh Gusain on 14/01/22.
//
// https://www.youtube.com/watch?v=79g3LJoQk_U

#include<stdc++.h>

using namespace std;
int T[1001][1000];

bool solution1(string s1, string s2, string s3, int i, int j) {

    if (s1.length() + s2.length() != s3.length()) {
        return T[i][j] = false;
    }

    if (i == s1.length() and j == s2.length()) {
        return T[i][j] = true;
    }

    if (T[i][j] != -1) {
        return T[i][j];
    }

    // k = i+j
    if (i < s1.length() and s1[i] == s3[i + j]) {
        bool f1 = solution1(s1, s2, s3, i + 1, j);
        if (f1) {
            return T[i][j] = true;
        }
    }

    if (j < s2.length() and s2[j] == s3[i + j]) {
        bool f2 = solution1(s1, s2, s3, i, j + 1);
        if (f2) {
            return T[i][j] = true;
        }
    }
    return T[i][j] = false;
}

// Tabulation
bool solution2(string s1, string s2, string s3, int i, int j) {
    int dp[s1.length() + 1][s2.length() + 1];

    for (int i = 0; i < s1.length()+1; i++) {
        for (int j = 0; j < s2.length()+1; j++) {
            if (i == 0 and j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                dp[i][j] = s2[j - 1] == s3[i + j - 1]? dp[i][j - 1] : false;
            } else if (j == 0) {
                dp[i][j] = s1[i - 1] == s3[i + j - 1]? dp[i-1][j] : false;
            } else {
                if(s1[i-1] == s3[i+j-1]){
                    dp[i][j] = dp[i-1][j];
                }
                if(!dp[i][j] and s2[j-1] == s3[i+j-1]){
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    return dp[s1.length()][s2.length()];
}


int main() {
    memset(T, -1, sizeof T);
    string str1 = "aabcc";
    string str2 = "dbbca";
    string str3 = "aadbbcbcac";

    //cout << solution1(str1, str2, str3, 0, 0);
    cout << solution2(str1, str2, str3, 0, 0);
}
