//
// Created by Akshansh Gusain on 29/08/23.
//
#include<bits/stdc++.h>

using namespace std;



vector<int> xMoveVector = {2, 2, -2, -2, -1, -1, 1, 1};
vector<int> yMoveVector = {1, -1, 1, -1, 2, -2, 2, -2};

int isSafe(int x, int y, int n, vector<vector<int>> &chessBoard) {
    return (x >= 0 && x < n && y >= 0 && y < n && chessBoard[x][y] == 0);
}

int solve(vector<int> &KnightPos, vector<int> &TargetPos, int N) {
    int x1 = KnightPos[0];
    int y1 = KnightPos[1];
    int x2 = TargetPos[0];
    int y2 = TargetPos[1];

    if (x1 == x2 and y1 == y2) {
        return 0;
    }

    vector<vector<int>> chessBoard(N, vector<int>(N, 0));
    queue<pair<int, int>> queue;
    queue.emplace(x1 - 1, y1 - 1);

    while (!queue.empty()) {
        auto currentVertex = queue.front();
        queue.pop();

        int i = currentVertex.first;
        int j = currentVertex.second;

        for (int m = 0; m < xMoveVector.size(); m++) {
            int nextXMove = i + xMoveVector[m];
            int nextYMove = j + yMoveVector[m];

            if (isSafe(nextXMove, nextYMove, N, chessBoard)) {
                chessBoard[nextXMove][nextYMove] = chessBoard[i][j] + 1;
                queue.emplace(nextXMove, nextYMove);
            }
        }

    }

    return chessBoard[x2 - 1][y2 - 1];
}

int main() {
    int n = 30;
    vector<int> knightPos = {1, 1};
    vector<int> targetPos = {30, 30};
    cout << "Min. Step to Reach Target: " << solve(knightPos, targetPos, n);
    return 0;
}