//
// Created by Akshansh Gusain on 05/03/24.
//
#include "BT_000.cpp"
#include "../Graph/Graph_000.cpp"


bool isCyclic(int node, Graph &graph, vector<bool> &used, int parent) {
    used[node] = 1;

    for (auto it: graph.adj[node]) {
        if (!used[it]) {
            if (isCyclic(it, graph, used, node)) {
                return true;
            }
        } else if (it != parent) {
            return true;
        }
    }

    return false;
}


bool isTree(Graph &g) {
    vector<bool> visited(g.V, false);

    // The call to isCyclicUtil serves multiple purposes.
    // It returns true if graph reachable from vertex 0
    // is cyclcic. It also marks all vertices reachable
    // from 0.

    if (isCyclic(0, g, visited, -1)) {
        return false;
    }
    // If we find a vertex which is not reachable from 0
    // then we return false
    for (int u = 0; u < g.V; u++) {
        if (!visited[u]) {
            return false;
        }
    }
    return true;
}

int main() {
    Graph graph(5);
    graph.addEdgeU(1, 0);
    graph.addEdgeU(0, 2);
    graph.addEdgeU(0, 3);
    graph.addEdgeU(3, 4);

    isTree(graph) ? cout << "Graph is Tree\n" : cout << "Graph is not a Tree\n";

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    isTree(g2) ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n";
    return 0;
}