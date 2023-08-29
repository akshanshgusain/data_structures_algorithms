//
// Created by Akshansh Gusain on 24/08/21.
//
#include<stdc++.h>

using namespace std;

int solve(vector<int> &knightPos, vector<int> &targetPos, int N) {
    int x1 = knightPos[0];
    int y1 = knightPos[1];
    int x2 = targetPos[0];
    int y2 = targetPos[1];

    int a[1000][1000];

    //base case
    if (x1 == x2 and y1 == y2) {
        return 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = 0;
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(x1 - 1, y1 - 1));

    while (!q.empty()) {
        auto currentMove = q.front();
        q.pop();
        int i = currentMove.first;
        int j = currentMove.second;

        if ((j + 2) >= 0 and (j + 2) < N and (i + 1) >= 0 and (i + 1) < N and  a[i + 1][j + 2] == 0) {
            a[i + 1][j + 2] = a[i][j] + 1;
            q.push(make_pair(i + 1, j + 2));
        }
        if ((j + 2) >= 0 and (j + 2) < N and (i - 1) >= 0 and (i - 1) < N and  a[i - 1][j + 2] == 0) {
            a[i - 1][j + 2] = a[i][j] + 1;
            q.push(make_pair(i - 1, j + 2));
        }

        if ((j - 2) >= 0 and (j - 2) < N and (i - 1) >= 0 and (i - 1) < N and  a[i - 1][j - 2] == 0) {
            a[i - 1][j - 2] = a[i][j] + 1;
            q.push(make_pair(i - 1, j - 2));
        }

        if ((j - 2) >= 0 and (j - 2) < N and (i + 1) >= 0 and (i + 1) < N and  a[i + 1][j - 2] == 0) {
            a[i + 1][j - 2] = a[i][j] + 1;
            q.push(make_pair(i + 1, j - 2));
        }

        if ((i + 2) >= 0 and (i + 2) < N and (j + 1) >= 0 and (j + 1) < N and a[i + 2][j + 1] == 0) {
            a[i + 2][j + 1] = a[i][j] + 1;
            q.push(make_pair(i + 2, j + 1));
        }

        if ((i + 2) >= 0 and (i + 2) < N and (j - 1) >= 0 and (j - 1) < N and a[i + 2][j - 1] == 0) {
            a[i + 2][j - 1] = a[i][j] + 1;
            q.push(make_pair(i + 2, j - 1));
        }

        if ( (i - 2) >= 0 and (i - 2) < N and (j + 1) >= 0 and (j + 1) < N and  a[i - 2][j + 1] == 0) {
            a[i - 2][j + 1] = a[i][j] + 1;
            q.push(make_pair(i - 2, j + 1));
        }

        if ((i - 2) >= 0 and (i - 2) < N and (j - 1) >= 0 and (j - 1) < N and a[i - 2][j - 1] == 0) {
            a[i - 2][j - 1] = a[i][j] + 1;
            q.push(make_pair(i - 2, j - 1));
        }
    }

    return a[x2 - 1][y2 - 1];
}

int main() {
    int N = 30; // size of the chess board
    vector<int> knightPos = {1, 1};
    vector<int> targetPos = {30, 30};
    cout << "Min. Step to Reach Target: " << solve(knightPos, targetPos, N);
    return 0;
}
