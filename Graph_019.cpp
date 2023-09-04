//
// Created by Akshansh Gusain on 08/09/21.
//

#include<stdc++.h>

using namespace std;


// Time: O(V^3), Space: O(V^2)

void floyd_warshall(vector<vector<int>> &graph) {
    int V = graph.size();

    int dis[V][V];
    int i, j, k;
    vector<vector<int>> dist{V, vector<int>(V)};

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dis[i][j] = graph[i][j];
        }
    }



    // Find the min distance between i and j via k.

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dis[i][k] == INT_MAX or dis[k][j] == INT_MAX) {
                    continue;
                }
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    //Check for negative cycle
    // dis[i][i] represents distance of ith node from itself, that can't ever be less than 0
    for (i = 0; i < V; i++) {
        if (dis[i][i] < 0) {
            cout << "Negative Edge Cycle is present...." << endl;
            break;
        }
    }

    //Print the all-pair shortest distance
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            cout<<"Min. Distance between i="<<i<<", j="<<j<<" is "<<dis[i][j]<<endl;
        }
    }
}

int main() {
    vector<vector<int>> graph = {{0,       1,       4,       INT_MAX, INT_MAX, INT_MAX},
                       {INT_MAX, 0,       4,       2,       7,       INT_MAX},
                       {INT_MAX, INT_MAX, 0,       3,       4,       INT_MAX},
                       {INT_MAX, INT_MAX, INT_MAX, 0,       INT_MAX, 4},
                       {INT_MAX, INT_MAX, INT_MAX, 3,       0,       INT_MAX},
                       {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5,       0}};

    floyd_warshall(graph);

    return 0;
}