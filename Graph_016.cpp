//
// Created by Akshansh Gusain on 28/08/21.
//
//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
#include<stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &vect, int i, int j, int row, int col) {
    if (i < 0 or j < 0 or i >= row or j >= col or vect[i][j] != 1) {
        return;
    }

    vect[i][j] = 2;

    dfs(vect, i + 1, j, row, col);
    dfs(vect, i, j + 1, row, col);
    dfs(vect, i - 1, j, row, col);
    dfs(vect, i, j - 1, row, col);
}

int findIslands(vector<vector<int>> &vect) {
    int r = vect.size();
    int c = vect[0].size();

    int noOfIslands = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (vect[i][j] == 1) {
                dfs(vect, i, j, r, c);
                noOfIslands++;
            }
        }
    }
}

int main() {
    vector<vector<int>> vect = {{1, 1, 0, 0, 0},
                                {0, 1, 0, 0, 1},
                                {1, 0, 0, 1, 1},
                                {0, 0, 0, 0, 0},
                                {1, 0, 1, 0, 1}};

    cout << "Number of Islands: " << findIslands(vect);
    return 0;
}
