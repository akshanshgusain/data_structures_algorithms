//
// Created by Akshansh Gusain on 03/01/24.
//

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

void dfs(
        int node,
        int parent,
        vector<bool> &visited,
        vector<int> &discoveryTime,
        vector<int> &minTime,
        int timer,
        vector<int> &articulationPoints,
        Graph &g) {
    visited[node] = true;
    discoveryTime[node] = minTime[node] = timer;
    timer++;

    int child = 0;

    for (auto it: g.adj[node]) {
        if (it == parent) {
            continue;
        }
        if (!visited[it]) {
            // simple case of DFS
            dfs(it, node, visited, discoveryTime, minTime, timer, articulationPoints, g);
            minTime[node] = min(minTime[node], minTime[it]);
            // check for articulation point : node -- it
            if (minTime[it] >= discoveryTime[node] and parent != -1) {
                articulationPoints[node] = 1;
            }
            child++;
        } else {
            minTime[node] = min(minTime[node], discoveryTime[it]);
        }
    }
    if (child > 1 and parent == -1) {
        articulationPoints[node] = 1;
    }
}

void findArticulationPoint(Graph &graph) {
    vector<int> discoveryTime(graph.V, -1);
    vector<int> minTime(graph.V, -1);
    vector<bool> visited(graph.V, false);
    vector<int> articulationPoints(graph.V, 0);
    int timer = 0;

    for (int i = 0; i < graph.V; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, discoveryTime, minTime, timer, articulationPoints, graph);
        }
    }

    for (int i = 0; i < graph.V; i++) {
        if (articulationPoints[i] == 1) {
            cout << i << " ";
        }
    }
}

int main() {
    Graph graph(5);
    graph.addEdgeU(0, 1);
    graph.addEdgeU(0, 2);
    graph.addEdgeU(1, 2);
    graph.addEdgeU(1, 3);
    graph.addEdgeU(4, 3);

    findArticulationPoint(graph);
    return 0;
}