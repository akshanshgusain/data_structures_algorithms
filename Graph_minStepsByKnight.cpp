//
// Created by Akshansh Gusain on 11/04/21.
//This problem can be seen as shortest path in unweighted graph. Therefore we use BFS to solve this problem.
// We try all 8 possible positions where a Knight can reach from its position. If reachable position is not
// already visited and is inside the board, we push this state into queue with distance 1 more than its parent
// state. Finally we return distance of target position, when it gets pop out from queue.

#include<stdc++.h>

using namespace std;

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n) {
    int x1 = KnightPos[0];
    int y1 = KnightPos[1];
    int x2 = TargetPos[0];
    int y2 = TargetPos[1];
    int a[1000][1000];
    if (x1 == x2 and y1 == y2) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(x1 - 1, y1 - 1));

    while (!q.empty()) {
        auto cur = q.front();
        int i = cur.first;
        int j = cur.second;
        q.pop();

        if ((i + 1) >= 0 and (i + 1) < n and (j + 2) >= 0 and (j + 2) < n and a[i + 1][j + 2] == 0) {
            a[i + 1][j + 2] = a[i][j] + 1;
            q.push(make_pair(i + 1, j + 2));
        }

        if ((i - 1) >= 0 and (i - 1) < n and (j + 2) >= 0 and (j + 2) < n and a[i - 1][j + 2] == 0) {
            a[i - 1][j + 2] = a[i][j] + 1;
            q.push(make_pair(i - 1, j + 2));
        }

        if ((i - 2) >= 0 and (i - 2) < n and (j + 1) >= 0 and (j + 1) < n and a[i - 2][j + 1] == 0) {
            a[i - 2][j + 1] = a[i][j] + 1;
            q.push(make_pair(i - 2, j + 1));
        }

        if ((i + 2) >= 0 and (i + 2) < n and (j + 1) >= 0 and (j + 1) < n and a[i + 2][j + 1] == 0) {
            a[i + 2][j + 1] = a[i][j] + 1;
            q.push(make_pair(i + 2, j + 1));
        }

        if ((i - 1) >= 0 and (i - 1) < n and (j - 2) >= 0 and (j - 2) < n and a[i - 1][j - 2] == 0) {
            a[i - 1][j - 2] = a[i][j] + 1;
            q.push(make_pair(i - 1, j - 2));
        }

        if ((i + 1) >= 0 and (i + 1) < n and (j - 2) >= 0 and (j - 2) < n and a[i + 1][j - 2] == 0) {
            a[i + 1][j - 2] = a[i][j] + 1;
            q.push(make_pair(i + 1, j - 2));
        }

        if ((i - 2) >= 0 and (i - 2) < n and (j - 1) >= 0 and (j - 1) < n and a[i - 2][j - 1] == 0) {
            a[i - 2][j - 1] = a[i][j] + 1;
            q.push(make_pair(i - 2, j - 1));
        }
        if ((i + 2) >= 0 and (i + 2) < n and (j - 1) >= 0 and (j - 1) < n and a[i + 2][j - 1] == 0) {
            a[i + 2][j - 1] = a[i][j] + 1;
            q.push(make_pair(i + 2, j - 1));
        }
    }
    return a[x2 - 1][y2 - 1];
}

int main() {
    int N = 30;
    vector<int> knightPos = {1, 1};
    vector<int> targetPos = {30, 30};
    cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}