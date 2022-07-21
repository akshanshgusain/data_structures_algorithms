//
// Created by Akshansh Gusain on 11/08/21.
//
#include<stdc++.h>

using namespace std;

void computeLPS(char *pattern, int M, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (pattern[len] == pattern[i]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *pattern, char *text) {
    int M = strlen(pattern);
    int N = strlen(text);
    int lps[M];
    computeLPS(pattern, M, lps);
    int i = 0, j = 0;

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == M) {
            cout << "Pattern Found At: " <<i -j << endl;
            j = lps[j - 1];
        } else if (i < N and pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}

int main() {
    char text[] = "ababdabacdababcabab";
    char pattern[] = "cdaba";
    KMPSearch(pattern, text);
    return 0;
}
