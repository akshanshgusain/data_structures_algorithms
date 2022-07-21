//
// Created by Akshansh Gusain on 27/05/21.
//
#include<stdc++.h>

using namespace std;
int dp[100][100];

bool isPalindrome(string String, int i, int j) {
    while (i < j) {
        if (String[i] != String[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int minPalPartion(string String, int i, int j) {
    if (i >= j || isPalindrome(String, i, j))
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX, count;
    for (int k = i; k < j; k++) {
        count = minPalPartion(String, i, k) +
                minPalPartion(String, k + 1, j) + 1;

        ans = min(ans, count);
    }
    return dp[i][j] = ans;
}

// Driver code
int main() {
    memset(dp,-1, sizeof dp);
   string str = "ababbbabbababa";
    //string str = "nitin";
    cout << "Min cuts needed for " <<
         "Palindrome Partitioning is " <<
         minPalPartion(str, 0, str.length() - 1) << endl;
    return 0;
}
