//
// Created by Akshansh Gusain on 24/08/23.
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

bool dfs(int source, Graph &graph, vector<bool> &visited, vector<bool> &visitedTillNow) {
    visited[source] = true;
    visitedTillNow[source] = true;

    for (auto it: graph.adj[source]) {
        if (!visited[it]) {
            dfs(it, graph, visited, visitedTillNow);
        } else if (visitedTillNow[it]) {
            return true;
        }
    }
    visitedTillNow[source] = false; // backtrack

    return false;
}

bool detectCycleDFS(Graph &graph) {
    vector<bool> visited(graph.V, false);

    // we need to keep track of the nodes visited till now and the nodes that are
    // in the current recursion stack

    vector<bool> visitedTillNow(graph.V, false);
    for (int i = 0; i < graph.V; ++i) {
        if (!visited[i]) {
            return dfs(i, graph, visited, visitedTillNow);
        }
    }
    return false;
}


bool detectCycleBFS(Graph &graph) {
    queue<int> queue;
    vector<int> inDegree(graph.V, 0);
    int count = 0;

    // calculate in-degrees
    for (int i = 0; i < graph.V; i++) {
        for (auto it: graph.adj[i]) {
            inDegree[i]++;
        }
    }

    // find a source with 0- in degree
    for (int i = 0; i < graph.V; ++i) {
        if (inDegree[i] == 0) {
            queue.push(i);
        }
    }

    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();
        count++;

        for (auto it: graph.adj[currentVertex]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                queue.push(it);
            }
        }
    }

    if (count == graph.V) {
        return false;
    }

    return true;
}


void printResult(bool hasCycle){
    if (hasCycle) {
        cout << "Graph contains cycle";
    }else {
        cout << "Graph doesn't contain cycle";
    }

    cout<<endl;
}


int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "DFS Cycle Check: " << endl;
    printResult(detectCycleDFS(g));

    cout << "BFS Cycle Check: " << endl;
    printResult(detectCycleBFS(g));

    return 0;
}