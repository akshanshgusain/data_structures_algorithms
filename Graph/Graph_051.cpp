//
// Created by Akshansh Gusain on 08/01/24.
//
// https://leetcode.com/problems/01-matrix/
#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    int V, E;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<int>());
    }

    // Undirected Graph
    void addEdgeU(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        E++;
    }

    // Directed Graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        E++;
    }

    void print() {
        cout << endl;
        int i = 0;
        for (const auto &vertexList: this->adj) {
            cout << i << "th - ";
            for (auto it: vertexList) {
                cout << it << " ";
            }
            cout << endl;
            i++;
        }
    }
};

bool isValidMove(int nextRow, int nextCol, int n, int m, vector<vector<bool>> &vis) {
    return (nextRow >= 0 and nextRow < n) and (nextCol >= 0 and nextCol < m) and (vis[nextRow][nextCol]==0);
}

vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> queue;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                queue.push({{i, j}, 0});
                vis[i][j] = true;
            }
        }
    }

    vector<int> rowDir = {-1, 0, 1, 0};
    vector<int> colDir = {0, 1, 0, -1};

    while (!queue.empty()) {
        int row = queue.front().first.first;
        int col = queue.front().first.second;
        int steps = queue.front().second;
        queue.pop();
        dist[row][col] = steps;

        for (int i = 0; i < 4; i++) {
            int nextRow = row + rowDir[i];
            int nextCol = col + colDir[i];

            if (nextRow >= 0 and nextRow < n and nextCol >= 0 and nextCol < m and vis[nextRow][nextCol]==0) {
                vis[nextRow][nextCol] = true;
                queue.push({{nextRow, nextCol}, steps + 1});
            }
        }

    }

    return dist;
}


int main() {
    vector<vector<int>> mat = {{0, 0, 0},
                               {0, 1, 0},
                               {0, 0, 0}}; // matrix
    vector<vector<int>> updated = updateMatrix(mat);

    for (auto it: updated) {
        for (auto i: it) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

