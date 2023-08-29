//
// Created by Akshansh Gusain on 28/08/23.
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

bool dfs(int source, int parent, vector<bool> &visited, Graph &g) {
    visited[source] = true;
    for (auto neighbor: g.adj[source]) {
        // If an adjacent vertex is not visited,
        // then recur for that adjacent.
        if (!visited[neighbor]) {
            if (dfs(neighbor, source, visited, g)) {
                return true;
            }
        }
            // If an adjacent vertex is visited and
            // is not parent of current vertex,
            // then there exists a cycle in the graph
        else if (neighbor != parent) {
            return true;
        }

    }
    return false;
}

/// Un-directed Graphs
// Time: O(V + E), Space: O(V+E) + O(N) + O(N)
bool detectCycleDFS(Graph &g) {
    vector<bool> visited(g.V, false);
    for (int i = 0; i < g.V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, g)) {
                return true;
            }
        }
    }
    return false;
}

// Time: O(V + E), Space: O(V+E) + O(N) + O(N)
bool detectCycleBFS(Graph &graph) {
    vector<bool> visited(graph.V, false);
    queue<pair<int, int>> queue; // {node, parent}
    int source = 0;

    // process the source
    visited[source] = true;
    queue.emplace(source, -1);

    while (!queue.empty()) {
        int currentVertex = queue.front().first;
        int parent = queue.front().second;
        queue.pop();
        for (auto neighbour: graph.adj[currentVertex]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                queue.emplace(neighbour, currentVertex);
            } else if (neighbour != parent) {
                return true;
            }
        }
    }

    return false;
}

void printResult(bool hasCycle) {
    if (hasCycle) {
        cout << "Graph contains cycle";
    } else {
        cout << "Graph doesn't contain cycle";
    }

    cout << endl;
}

int main() {
    Graph graph = Graph(5);
    graph.addEdgeU(1, 0);
    graph.addEdgeU(0, 2);
    graph.addEdgeU(2, 1);
    graph.addEdgeU(0, 3);
    graph.addEdgeU(3, 4);

    cout << "DFS Cycle Check: " << endl;
    printResult(detectCycleDFS(graph));

    cout << "BFS Cycle Check: " << endl;
    printResult(detectCycleBFS(graph));

    return 0;
}