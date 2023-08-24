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

void dfs(int source, Graph &graph, vector<bool> &visited, stack<int> &stack) {
    visited[source] = true;
    for (auto it: graph.adj[source]) {
        if (!visited[it]) {
            dfs(it, graph, visited, stack);
        }
    }

    //Note that a vertex is pushed to stack only when all of its adjacent vertices
    // (and their adjacent vertices and so on) are already in the stack.
    stack.push(source);
}

// time: O(V + E), space: O(V + V + V) = O(V)
void topologicalSortDFS(Graph &graph, vector<int> &sorted) {
    stack<int> stack;
    vector<bool> visited(graph.V, false);

    for (int i = 0; i < graph.V; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, stack);
        }
    }

    // stack to vector

    while (!stack.empty()) {
        sorted.push_back(stack.top());
        stack.pop();
    }
}

/// Kahn's Algorithm
// time: O(V + E), space: O(V)
void topologicalSortBFS(Graph &graph, vector<int> &sorted) {
    vector<int> inDegree(graph.V, 0);
    queue<int> queue;

    // find out in-degrees
    for (int i = 0; i < graph.V; i++) {
        for (auto it: graph.adj[i]) {
            inDegree[it]++;
        }
    }

    // we need to push source(in-degree == 0) to the queue
    for (int i = 0; i < graph.V; i++) {
        if (inDegree[i] == 0) {
            queue.push(i);
        }
    }

    while(!queue.empty()){
        int currentVertex = queue.front();
        queue.pop();
        sorted.push_back(currentVertex);

        for(auto it : graph.adj[currentVertex]){
            inDegree[it]--;
            if(inDegree[it] == 0){
                queue.push(it);
            }
        }
    }
}

void printSortedArray(vector<int> &sorted){
    for (auto it: sorted) {
        cout << it << " ";
    }
    cout << endl;
}


int main() {
    Graph graph(6);
    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    vector<int> sorted;

    topologicalSortDFS(graph, sorted);
    cout << "Topological Sort, DFS: " << endl; //5 4 2 3 1 0
    printSortedArray(sorted);

    sorted.clear();

    cout << "Topological Sort, BFS: " << endl; // 4 5 2 0 3 1
    topologicalSortBFS(graph, sorted);
    printSortedArray(sorted);

    return 0;
}