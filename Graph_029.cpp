//
// Created by Akshansh Gusain on 18/09/21.
// Take U Forward

#include<stdc++.h>

using namespace std;

/* Koraraju's Algorithm:
 1. Sort all nodes in order of finishing time: Topological Sort. O(N)
 2. Transpose the graph. O(N+E)
 3. DFS according to the finishing time. O(N+E) */

// Time: O(N+E), Space: O(N+E) + O(N) + O(N)

class Graph {
public:
    int V, E;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<int>());
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        E++;
    }
};


void revDfs(int node, vector<bool> &vis, vector<vector<int>> &transpose) {
    cout << node << " ";
    vis[node] = true;
    for (auto it: transpose[node]) {
        if (!vis[it]) {
            revDfs(it, vis, transpose);
        }
    }
}

void dfs(int node, stack<int> &st, vector<bool> &vis, vector<vector<int>> &adj) {
    vis[node] = true;
    for (auto it: adj[node]) {
        if (!vis[it]) {
            dfs(it, st, vis, adj);
        }
    }
    st.push(node);
}

void findSCC(Graph &graph) {
    stack<int> st;
    vector<bool> vis(graph.V, false);
    vector<vector<int>> transpose(graph.V);

    // Run Topological Sort.
    for (int i = 0; i < graph.V; i++) {
        if (!vis[i]) {
            dfs(i, st, vis, graph.adj);
        }
    }

    // Take transpose of the graph

    for (int i = 0; i < graph.V; i++) {
        vis[i] = 0;
        for (auto it: graph.adj[i]) {                   // Reverse the direction of the Edges.
            transpose[it].push_back(i);
        }
    }

    // DFS according to finishing time:

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            cout << "SCC : ";
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }
}


int main() {
    Graph graph(6);
    graph.addEdge(5, 5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    findSCC(graph);
    return 0;
}
