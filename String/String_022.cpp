//
// Created by Akshansh Gusain on 13/08/21.
//
#include<stdc++.h>

using namespace std;
#define R 3
#define C 14

int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool search2D(char grid[R][C], string word, int i, int j) {
    if (grid[i][j] != word[0]) {
        return false;
    }

    int len = word.length();
    for (int dir = 0; dir < 8; dir++) {
        int k, rD, cD;
        rD = x[dir] + i;
        cD = y[dir] + j;

        for (k = 1; k < len; k++) {
            if (rD < 0 or rD > R or cD < 0 or cD > C) {
                break;
            }
            if(grid[rD][cD] != word[k]){
                break;
            }

            rD += x[dir];
            cD += y[dir];
        }

        if(k == len){
            return true;
        }
    }
    return false;
}


void patternSearch(char grid[R][C], string word) {

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (search2D(grid, word, i, j)) {
                cout << "Found patterns at: " << i << ", j:" << j << endl;
            }
        }
    }
}

int main() {
    char grid[R][C] = {"GEEKSFORGEEKS",
                       "GEEKSQUIZGEEK",
                       "IDEQAPRACTICE"};

    patternSearch(grid, "GEEKS");
    cout << endl;
    patternSearch(grid, "EEE");
    return 0;
}
