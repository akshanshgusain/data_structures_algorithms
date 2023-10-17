//
// Created by Akshansh Gusain on 08/09/21.
//

#include<stdc++.h>
using namespace std;

// Time: O(V^3), Space: O(V^2)

void floyd_warshall(vector<vector<int>> &graph) {
    int V = graph.size();

    // Find the min distance between i and j via k.

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] == INT_MAX or graph[k][j] == INT_MAX) {
                    continue;
                }
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    //Check for negative cycle
    // dis[i][i] represents distance of ith node from itself, that can't ever be less than 0
    for (int i = 0; i < V; i++) {
        if (graph[i][i] < 0) {
            cout << "Negative Edge Cycle is present...." << endl;
            break;
        }
    }

    //Print the all-pair shortest distance
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INT_MAX) {
                cout << "Min. Distance between i=" << i << ", j=" << j << " is Not Reachable " << endl;
            } else {
                cout << "Min. Distance between i=" << i << ", j=" << j << " is " << graph[i][j] << endl;
            }
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

/*
 Min. Distance between i=0, j=0 is 0
Min. Distance between i=0, j=1 is 1
Min. Distance between i=0, j=2 is 4
Min. Distance between i=0, j=3 is 3
Min. Distance between i=0, j=4 is 8
Min. Distance between i=0, j=5 is 7
Min. Distance between i=1, j=0 is Not Reachable
Min. Distance between i=1, j=1 is 0
Min. Distance between i=1, j=2 is 4
Min. Distance between i=1, j=3 is 2
Min. Distance between i=1, j=4 is 7
Min. Distance between i=1, j=5 is 6
Min. Distance between i=2, j=0 is Not Reachable
Min. Distance between i=2, j=1 is Not Reachable
Min. Distance between i=2, j=2 is 0
Min. Distance between i=2, j=3 is 3
Min. Distance between i=2, j=4 is 4
Min. Distance between i=2, j=5 is 7
Min. Distance between i=3, j=0 is Not Reachable
Min. Distance between i=3, j=1 is Not Reachable
Min. Distance between i=3, j=2 is Not Reachable
Min. Distance between i=3, j=3 is 0
Min. Distance between i=3, j=4 is 9
Min. Distance between i=3, j=5 is 4
Min. Distance between i=4, j=0 is Not Reachable
Min. Distance between i=4, j=1 is Not Reachable
Min. Distance between i=4, j=2 is Not Reachable
Min. Distance between i=4, j=3 is 3
Min. Distance between i=4, j=4 is 0
Min. Distance between i=4, j=5 is 7
Min. Distance between i=5, j=0 is Not Reachable
Min. Distance between i=5, j=1 is Not Reachable
Min. Distance between i=5, j=2 is Not Reachable
Min. Distance between i=5, j=3 is 8
Min. Distance between i=5, j=4 is 5
Min. Distance between i=5, j=5 is 0
 */