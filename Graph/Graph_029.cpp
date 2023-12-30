//
// Created by Akshansh Gusain on 30/12/23.
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

void dfs(int node, stack<int> &stack, vector<bool> &visited, Graph &graph) {
    visited[node] = true;
    for (auto it: graph.adj[node]) {
        if (!visited[it]) {
            dfs(it, stack, visited, graph);
        }
    }
    stack.push(node);
}

void dfs2(int node, vector<bool> &visited, vector<vector<int>> &transpose) {
    cout << node << " ";
    visited[node] = true;
    for (auto it: transpose[node]) {
        if (!visited[it]) {
            dfs2(it, visited, transpose);
        }
    }
}

void findSCC(Graph &graph) {
    stack<int> stack;
    vector<bool> visited(graph.V, false);

    // 1. run topological sort
    for (int i = 0; i < graph.V; i++) {
        if (!visited[i]) {
            dfs(i, stack, visited, graph);
        }
    }

    // 2. transpose the graph
    vector<vector<int>> transpose(graph.V);
    for (int i = 0; i < graph.V; i++) {
        visited[i] = false;
        // Reverse the direction of the Edges.
        for(auto it: graph.adj[i]){
            transpose[it].push_back(i);
        }
    }

    // run dfs according to finishing time
    int countSCC = 0;
    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();
        if (!visited[node]) {
            countSCC++;
            cout << "SCC : ";
            dfs2(node, visited, transpose);
            cout << endl;
        }
    }
    cout << "count of countSCC: " << countSCC << endl;
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