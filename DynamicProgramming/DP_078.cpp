//
// Created by Akshansh Gusain on 05/01/22.
//
#include<stdc++.h>

using namespace std;

int T[1001][1001];

int countPS(string str, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return T[i][j] = 1;
    } else if (str[i] == str[j]) {
        return T[i][j] = 1 + countPS(str, i + 1, j) + countPS(str, i, j - 1);
    } else {
        return T[i][j] = countPS(str, i + 1, j) + countPS(str, i, j - 1) - countPS(str, i + 1, j - 1);
    }
}

int main() {
    memset(T, -1, sizeof T);
    string str = "abcb";
    int n = str.size();
    cout << "Total palindromic subsequence are : "
         << countPS(str, 0, n - 1) << endl;
    return 0;
}
