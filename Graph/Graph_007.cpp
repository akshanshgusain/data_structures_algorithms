//
// Created by Akshansh Gusain on 29/08/23.
//

#include<bits/stdc++.h>

using namespace std;

void dfs(int i, int j, const string &answer, vector<vector<int>> &mat, int n,
         vector<string> &result, vector<vector<bool>> &visited) {

    if (i < 0 or j < 0 or i >= n or j >= n) {
        return;
    }
    if (mat[i][j] == 0 or visited[i][j]) {
        return;
    }
    if (i == n - 1 and j == n - 1) {
        result.push_back(answer);
        return;
    }

    visited[i][j] = true;

    dfs(i - 1, j, answer + 'U', mat, n, result, visited);
    dfs(i, j + 1, answer + 'R', mat, n, result, visited);
    dfs(i + 1, j, answer + 'D', mat, n, result, visited);
    dfs(i, j - 1, answer + 'L', mat, n, result, visited);

    visited[i][j] = false; //backtrack
}


void findPath(vector<vector<int>> &mat, vector<string> &result) {
    int n = mat.size();
    vector<vector<bool>> visited(n, vector<bool>(n));

    // no entry point
    if (mat[0][0] == 0) {
        return;
    }
    // no exit point
    if (mat[n - 1][n - 1] == 0) {
        return;
    }

    dfs(0, 0, "", mat, n, result, visited);
}


int main() {
    vector<vector<int>> mat = {{1, 0, 0, 0, 0},
                               {1, 1, 1, 1, 1},
                               {1, 1, 1, 0, 1},
                               {0, 0, 0, 0, 1},
                               {0, 0, 0, 0, 1}};

    vector<string> result;

    findPath(mat, result);

    for (const string &a: result) {
        cout << a << " - ";
    }

    return 0;
}