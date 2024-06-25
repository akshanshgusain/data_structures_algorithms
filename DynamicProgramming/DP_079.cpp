//
// Created by Akshansh Gusain on 05/01/22.
//
//https://www.geeksforgeeks.org/edit-distance-dp-5/
// Time: O(MN), Space: O(MN)
#include<stdc++.h>
using namespace std;

int editDistance(string s1, string s2, int n, int m, vector<vector<int>> &dp) {

    // If any string is empty,
    // return the remaining characters of other string

    if (n == 0) return m;

    if (m == 0) return n;


    // To check if the recursive tree
    // for given n & m has already been executed

    if (dp[n][m] != -1){
        return dp[n][m];
    }


    // If characters are equal, execute
    // recursive function for n-1, m-1

    if (s1[n - 1] == s2[m - 1]) {
        if (dp[n - 1][m - 1] == -1) {
            return dp[n][m] = editDistance(s1, s2, n - 1, m - 1, dp);
        } else
            return dp[n][m] = dp[n - 1][m - 1];
    }


        // If characters are nt equal, we need to

        // find the minimum cost out of all 3 operations.

    else {
        int m1, m2, m3;        // temp variables

        if (dp[n - 1][m] != -1) {
            m1 = dp[n - 1][m];
        } else {
            m1 = editDistance(s1, s2, n - 1, m, dp); // remove Operation
        }

        if (dp[n][m - 1] != -1) {
            m2 = dp[n][m - 1];
        } else {
            m2 = editDistance(s1, s2, n, m - 1, dp); // insert Operation
        }

        if (dp[n - 1][m - 1] != -1) {
            m3 = dp[n - 1][m - 1];
        } else {
            m3 = editDistance(s1, s2, n - 1, m - 1, dp); // replace Operation
        }
        return dp[n][m] = 1 + min(m1, min(m2, m3));
    }

}


// Driver program
int main() {

    string str1 = "voldemort";
    string str2 = "dumbledore";

    int n = str1.length(), m = str2.length();
    vector<vector<int>> T(n + 1, vector<int>(m + 1, -1));

    cout << editDistance(str1, str2, n, m, T);
    return 0;
}