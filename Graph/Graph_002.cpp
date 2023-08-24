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


void BFS(Graph &graph, int source) {
    vector<bool> visited(graph.V, false);
    queue<int> q;


    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        cout << top << "-";

        for (auto it: graph.adj[top]) {
            if (!visited[it]) {
                visited[it] = true;
                q.push(it);
            }
        }

    }
}

void shortestPathTo(int destination, vector<bool> &used, vector<int> &parent) {
    cout << endl << "Shortest Path from Source to "<< destination << endl;

    if (!used[destination]) {
        cout << "No path!";
    } else {
        vector<int> path;
        for (int v = destination; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v: path)
            cout << v << " ";
    }
}

void BFSWithPath(Graph &graph, int source) {
    vector<bool> visited(graph.V, false);
    queue<int> q;

    vector<int> pathLength(graph.E);
    //stores for each vertex the vertex from which we reached it
    vector<int> parent(graph.V);

    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << "-";

        for (auto nextVertex: graph.adj[currentVertex]) {
            if (!visited[nextVertex]) {
                visited[nextVertex] = true;
                q.push(nextVertex);

                pathLength[nextVertex] = pathLength[parent[nextVertex]] + 1;
                parent[nextVertex] = currentVertex;
            }
        }
    }

    shortestPathTo(4, visited, parent);
}


int main() {
    Graph graph(5);
    graph.addEdgeU(0, 1);
    graph.addEdgeU(0, 4);

    graph.addEdgeU(1, 2);
    graph.addEdgeU(1, 3);
    graph.addEdgeU(1, 4);
    graph.addEdgeU(2, 3);
    graph.addEdgeU(3, 4);


    cout << "Following is Breath First Traversal" << endl;
    BFSWithPath(graph, 2);

    return 0;
}