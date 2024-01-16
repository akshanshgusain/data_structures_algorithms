//
// Created by Akshansh Gusain on 08/01/24.
//
#include<bits/stdc++.h>

using namespace std;

void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &mat, int n, int m) {
    vis[row][col] = true;
    // check for top, left, bottom right
    vector<int> xDir = {0, -1, 0, 1};
    vector<int> yDir = {1, 0, -1, 0};

    for (int i = 0; i < 4; i++) {
        int nextRow = row + xDir[i];
        int nextCol = col + yDir[i];
        if (nextRow >= 0 and nextRow < n and nextCol >= 0 and nextCol < m and !vis[nextRow][nextCol] and
            mat[nextRow][nextCol] == 'O') {
            dfs(nextRow, nextCol, vis, mat, n, m);
        }
    }
}

void solve(vector<vector<char>> &board) {
    // Boundary DFS traversal
    // all the zeros connected to the boundary cannot be converted
    int n = board.size();
    int m = board[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    // traverse first and last row
    for (int j = 0; j < m; j++) {
        if (!vis[0][j] and board[0][j] == 'O') {
            dfs(0, j, vis, board, n, m);
        }
        if (!vis[n - 1][j] and board[n - 1][j] == 'O') {
            dfs(n - 1, j, vis, board, n, m);
        }
    }

    // traverse first and last column
    for (int i = 0; i < n; i++) {
        if (!vis[i][0] and board[i][0] == 'O') {
            dfs(i, 0, vis, board, n, m);
        }
        if (!vis[i][m - 1] and board[i][m - 1] == 'O') {
            dfs(i, m - 1, vis, board, n, m);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] and board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
    // print
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            cout << board[i][j] << " ";

        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    vector<vector<char>> board2 = {{'X', 'O', 'X', 'O', 'X', 'O'},
                                   {'O', 'X', 'O', 'X', 'O', 'X'},
                                   {'X', 'O', 'X', 'O', 'X', 'O'},
                                   {'O', 'X', 'O', 'X', 'O', 'X'}};
    solve(board2);

    return 0;
}