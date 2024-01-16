//
// Created by Akshansh Gusain on 20/09/21.
//

#include<stdc++.h>

using namespace std;

class Graph {
public:
    int V, E;
    vector<vector<pair<int, int>>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<pair<int, int>>());
    }

    void addEdge(int v, int u, int w) {
        adj[v].push_back({u, w});
        E++;
    }

};


void topologicalSort(int source, vector<bool> &vis, vector<int> &order, vector<vector<pair<int, int>>> &adj) {
    vis[source] = true;
    for (auto it: adj[source]) {
        if (!vis[it.first]) {
            topologicalSort(it.first, vis, order, adj);
        }
    }
    order.push_back(source);
}

void findLongestPath(Graph &graph, int source) {
    vector<bool> vis(graph.V, false);
    vector<int> topoSorted;
    vector<int> distance(graph.V, INT_MIN);

    // topological sort
    for (int i = 0; i < graph.V; i++) {
        if (!vis[i]) {
            topologicalSort(i, vis, topoSorted, graph.adj);
        }
    }



    // initialize the source node with 0
    distance[source] = 0;
    for (int i = graph.V - 1; i >= 0; i--) {

        if (distance[topoSorted[i]] != INT_MIN) {
            for (auto it: graph.adj[topoSorted[i]]) {
                int u = distance[topoSorted[i]];
                int v = distance[it.first];
                int w = it.second;

                if (u + w > v) {
                    distance[it.first] = u + w;
                }
            }
        }
    }

    for (int i = 0; i < graph.V; i++) {
        if (i != source and distance[i] != INT_MIN) {
            cout << source << " -> " << i << " = " << distance[i] << endl;
        }
    }
}

int main() {
    int V = 6;
    int source = 1;
    Graph graph(V);
    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 5, 5);
    graph.addEdge(5, 3, 2);
    graph.addEdge(3, 2, 20);
    graph.addEdge(4, 2, 10);
    graph.addEdge(5, 2, 50);
    graph.addEdge(1, 4, 2);

    findLongestPath(graph, source);
    return 0;
}