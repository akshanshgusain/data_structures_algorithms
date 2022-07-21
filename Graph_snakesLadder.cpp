
//
// Created by Akshansh Gusain on 15/04/21.
//
#include<stdc++.h>

using namespace std;
typedef pair<int, int> pii;

unordered_map<int, int> mn_steps;

int getNextPos(vector<vector<int>> &board, int pos, int r, int c) {
    pos--;
    int i = pos / r;
    int j = pos % c;

    if (i % 2 == 1) {
        // rtl row
        j = c - j - 1;
    }

    i = r - 1 - i;
    return board[i][j] == -1 ? pos + 1 : board[i][j];
}

int snakesAndLadders(vector<vector<int>> &board) {
    int r = board.size();

    if (!r) return 0;
    int c = board[0].size();

    queue<pii> q;
    q.push({1, 0}); // <position, steps>
    mn_steps[1] = 0;

    while (!q.empty()) {
        int sz = q.size();

        for (int i = 0; i < sz; i++) {
            int pos = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (int i = 1; i < 7; ++i) {
                int next_pos = pos + i;
                int next_steps = steps + 1;
                if (next_pos > r * c) break;

                next_pos = getNextPos(board, next_pos, r, c);

                if (mn_steps.find(next_pos) != mn_steps.end() && mn_steps[next_pos] <= next_steps) continue;

                if (next_pos == r * c) return next_steps;

                mn_steps[next_pos] = next_steps;
                q.push({next_pos, next_steps});
            }
        }

    }

    return -1;

}

int main() {
    vector<vector<int>> move = {
            {-1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1},
            {-1, 35, -1, -1, 13, -1},
            {-1, -1, -1, -1, -1, -1},
            {-1, 15, -1, -1, -1, -1}};
    snakesAndLadders(move);
    return 0;
}
