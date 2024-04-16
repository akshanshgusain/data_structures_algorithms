//
// Created by Akshansh Gusain on 16/03/24.
//

//https://www.geeksforgeeks.org/distance-nearest-cell-1-binary-matrix/

// Using BSF and Queues

#include<stdc++.h>

using namespace std;

#define MAX 500
#define N 3
#define M 4

class graph {
private:
    vector<int> g[MAX];
    int n, m;
public:
    graph(int a, int b) {
        n = a;
        m = b;
    }

    void createGraph() {
        int k = 1; //NUmber to be assigned to a cell
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // If last row, then add edge on right sode.
                if (i == n) {
                    if (j != m) {
                        g[k].push_back(k + 1);
                        g[k + 1].push_back(k);
                    }
                } else if (j == m) {
                    g[k].push_back(k + m);
                    g[k + m].push_back(k);
                }// Else makes an edge in all four directions.
                else {
                    g[k].push_back(k + 1);
                    g[k + 1].push_back(k);
                    g[k].push_back(k + m);
                    g[k + m].push_back(k);
                }

                k++;
            }
        }
    }

    // BFS function to find minimum distance
    void bfs(bool visit[], int dist[], queue<int> q) {
        while (!q.empty()) {
            int temp = q.front();
            q.pop();

            for (int i = 0; i < g[temp].size(); i++) {
                if (visit[g[temp][i]] != 1) {
                    dist[g[temp][i]] =
                            min(dist[g[temp][i]], dist[temp] + 1);

                    q.push(g[temp][i]);
                    visit[g[temp][i]] = 1;
                }
            }
        }
    }

    // Printing the solution.
    void print(int dist[]) {
        for (int i = 1, c = 1; i <= n * m; i++, c++) {
            cout << dist[i] << " ";

            if (c % m == 0)
                cout << endl;
        }
    }
};

// Find minimum distance
void findMinDistance(bool mat[N][M]) {
    // Creating a graph with nodes values assigned
    // from 1 to N x M and matrix adjacent.
    graph g1(N, M);
    g1.createGraph();

    // To store minimum distance
    int dist[MAX];

    // To mark each node as visited or not in BFS
    bool visit[MAX] = {0};

    // Initialising the value of distance and visit.
    for (int i = 1; i <= M * N; i++) {
        dist[i] = INT_MAX;
        visit[i] = 0;
    }

    // Inserting nodes whose value in matrix
    // is 1 in the queue.
    int k = 1;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 1) {
                dist[k] = 0;
                visit[k] = 1;
                q.push(k);
            }
            k++;
        }
    }

    // Calling for Bfs with given Queue.
    g1.bfs(visit, dist, q);

    // Printing the solution.
    g1.print(dist);
}

// Driven Program
int main() {
    bool mat[N][M] =
            {
                    0, 0, 0, 1,
                    0, 0, 1, 1,
                    0, 1, 1, 0
            };

    findMinDistance(mat);

    return 0;
}