//
// Created by Akshansh Gusain on 02/09/23.
//
#include<bits/stdc++.h>

using namespace std;

// Time: O(N-1) x O(E)


vector<int> bellmanFord(vector<vector<int>> &edges, int V, int source) {
    if(V == 1){
        return {-1};
    }
    vector<int> distance(V, 1e8);
    distance[source] = 0;

    // Relaxing the edges N-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (auto it: edges) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (distance[u] != 1e8 and distance[u] + wt < distance[v]) {
                distance[v] = distance[u] + wt;
            }
        }
    }

    bool hasNegativeCycle = false;

    // Nth relaxation, if we can still reduce the distance, that would mean there is a negative cycle
    for (auto it: edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (distance[u] != 1e8 and distance[u] + wt < distance[v]) {
            cout << "Negative Cycle";
            hasNegativeCycle = true;
            return {-1};
        }
    }

    return distance;
}

int main() {
    vector<vector<int>> edges;

    edges.push_back({0, 1, -1});
    edges.push_back({0, 1, -1});
    edges.push_back({0, 2, 4});
    edges.push_back({1, 2, 3});
    edges.push_back({1, 3, 2});
    edges.push_back({1, 4, 2});
    edges.push_back({3, 2, 5});
    edges.push_back({3, 1, 1});
    edges.push_back({4, 3, -3});

    int v = 5;
    int source = 0;

    vector<int> distance = bellmanFord(edges, v, source);

    for(auto it: distance){
        cout<<it<<" ";
    }

    return 0;
}