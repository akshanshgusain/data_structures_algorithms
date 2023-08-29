//
// Created by Akshansh Gusain on 29/08/23.
//
#include<bits/stdc++.h>

using namespace std;

vector<int> xMoveVector = {1, -1, 0, 0};
vector<int> yMoveVector = {0, 0, -1, 1};

bool isSafe(int x, int y, vector<vector<int>> &image, int n, int m, int color) {
    return ((x >= 0 and x < n) and (y >= 0 and y < m) and image[x][y] == color);
}

void floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {

    if (newColor == image[sr][sc]) {
        return;
    }

    int n = image.size();
    int m = image[0].size();

    queue<pair<int, int>> queue;
    queue.emplace(sr, sc);

    int color = image[sr][sc];
    image[sr][sc] = newColor;

    while (!queue.empty()) {
        auto currentVertex = queue.front();
        queue.pop();

        for (int k = 0; k < xMoveVector.size(); k++) {
            int nextXMove = currentVertex.first + xMoveVector[k];
            int nextYMove = currentVertex.second + yMoveVector[k];

            if (isSafe(nextXMove, nextYMove, image, n, m, color)) {
                image[nextXMove][nextYMove] = newColor;
                queue.emplace(nextXMove, nextYMove);
            }
        }

    }
}

int main() {
    vector<vector<int>> image = {{1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 0, 0},
                                 {1, 0, 0, 1, 1, 0, 1, 1},
                                 {1, 2, 2, 2, 2, 0, 1, 0},
                                 {1, 1, 1, 2, 2, 0, 1, 0},
                                 {1, 1, 1, 2, 2, 2, 2, 0},
                                 {1, 1, 1, 1, 1, 2, 1, 1},
                                 {1, 1, 1, 1, 1, 2, 2, 1},
    };

    floodFill(image, 4, 4, 3);

    for (const auto &i: image) {
        for (auto j: i) {
            cout << j << "  ";
        }
        cout << endl;
    }
    return 0;
}

/*
1  1  1  1  1  1  1  1
1  1  1  1  1  1  0  0
1  0  0  1  1  0  1  1
1  3  3  3  3  0  1  0
1  1  1  3  3  0  1  0
1  1  1  3  3  3  3  0
1  1  1  1  1  3  1  1
1  1  1  1  1  3  3  1

*/