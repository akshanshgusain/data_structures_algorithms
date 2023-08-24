//
// Created by Akshansh Gusain on 23/08/23.
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
};


void DFSUtil(int source, Graph &graph, vector<bool> &visited) {

    visited[source] = true;
    cout << source << " - > ";

    for (auto it: graph.adj[source]) {
        if (!visited[it]) {
            DFSUtil(it, graph, visited);
        }
    }
}

void DFS(Graph &graph) {
    vector<bool> visited(graph.V, false);

    // We need this for loop to cover all vertices(even if some of them are disconnected).
    for (int v = 0; v < graph.V; v++) {
        if (!visited[v]) {
            DFSUtil(v, graph, visited);
        }
    }
}

int main() {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Following is Depth First Traversal" << endl;
    DFS(graph); //0 -> 1 -> 2 -> 3 -> 4 ->

    return 0;
}