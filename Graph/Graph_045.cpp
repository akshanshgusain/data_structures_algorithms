//
// Created by Akshansh Gusain on 22/09/21.
//https://www.youtube.com/watch?v=cA8-mdRJuCI
#include<stdc++.h>

using namespace std;

class Graph {
public:
    int V, E;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<int>());
    }

    /// Undirected Graph
    void addEdgeU(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        E++;
    }
};

int main() {
    int V = 6;
    Graph g(V);
    g.addEdgeU(5, 5);
    g.addEdgeU(0, 1);
    g.addEdgeU(1, 2);
    g.addEdgeU(2, 0);
    g.addEdgeU(0, 3);
    g.addEdgeU(3, 4);

    vector<vector<int>> reverse(V, vector<int>());
    vector<int> dummy(V, 0);

    // Creating a Reverse Graph
    for (int i = 0; i < V; i++) {
        dummy[i] = 1;

        for (auto it: g.adj[i]) {
            dummy[it] = 1;
        }

        for (int j = 0; j < V; j++) {
            if (dummy[j] == 0) {
                reverse[i].push_back(j);
                reverse[j].push_back(i);
            }
        }
        dummy.clear();
    }

    // Now Check for Bipartite and that's it.
    return 0;
}