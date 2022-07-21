//
// Created by Akshansh Gusain on 21/09/21.
//https://www.youtube.com/watch?v=WY6Jsp3NxIk&t=1317s


/* Conditions for Euler Graph
 * 1. Start node = End Node
 * 2. Every Edge must be visited only once.
 * 3. All vertices should have even degree.
 * 4. All the vertices with non-zero degree are connected in a component.
 *    rest all vertices must have 0 degree.
 * 5. Graph with no edges is a Euler Graph.*/

/* Steps of the algorithm:
 * 1. Connectivity Check:  Check if all edges are present in 1 component only.
 *    1.1. Find a node with degree > 0.
 *    1.2. If no node found the Euler graph.
 *    1.3. Else do DFS and mark all nodes in component: check if any node with degree > 0 was not visited, If true
 *    Not a Euler Graph.
 * 2. Count odd Degree Nodes.
 *    2.1. Count = 0 => Eulerian Graph.
 *    2.2. Count = 2 => Semi-Eulerian Graph.
 *    2.3. Count > 2 => Not-Eulerian Graph. */

#include<stdc++.h>

using namespace std;

// Time: O(V+E)
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

void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj) {
    vis[node] = true;
    for (auto it: adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj);
        }
    }
}

bool connectedGraph(Graph &graph) {
    vector<bool> vis(graph.V, false);
    int node = -1;
    for (int i = 0; i < graph.V; i++) {
        // Find a node with degree > 0
        if (!graph.adj[i].empty()) {
            node = i;
            break;
        }
    }
    // No start node was found -> No edges are present in the graph
    if (node == -1) {
        return true;
    }

    dfs(node, vis, graph.adj);

    // check if all non-zero vertices are visited
    for (int i = 0; i < graph.V; i++) {
        if (vis[i] == false and graph.adj[i].size() > 0) {
            return false;
        }
    }

    return true;
}


int findEuler(Graph &graph) {
    // Steps:
    // 1.  Connectivity Check:  Check if all edges are present in 1 component only.
    if (!connectedGraph(graph)) { //multi-component Edged Graph.
        return 0;
    }

    // 2. Count odd Degree Nodes.
    int odd = 0;
    for (int i = 0; i < graph.V; i++) {
        if (graph.adj[i].size() & 1) {
            odd++;
        }
    }

    if (odd > 2) {
        return 0;
    }
    return (odd == 0) ? 2 : 1;
}

void findEulerianCycle(Graph &graph) {
    int result = findEuler(graph);

    if (result == 0) {
        cout << "Graph is NOT a Eulerian Graph" << endl;
    } else if (result == 1) {
        cout << "Graph is a Semi-Eulerian Graph" << endl;
    } else {
        cout << "Graph is an Eulerian Graph" << endl;
    }
}

int main() {
    Graph graph(5);
    graph.addEdgeU(0, 1);
    graph.addEdgeU(0, 2);
    graph.addEdgeU(1, 2);
    graph.addEdgeU(0, 3);
    graph.addEdgeU(3, 4);
    findEulerianCycle(graph);
    return 0;
}