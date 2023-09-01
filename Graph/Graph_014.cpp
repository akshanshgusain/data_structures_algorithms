//
// Created by Akshansh Gusain on 01/09/23.
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

void findTime(Graph &graph) {
    queue<int> queue;
    vector<int> inDegree(graph.V, 0);
    // because vertices start with 1
    vector<int> sorted(graph.V+1, 0);

    // find out the in degree
    for (int i = 1; i < graph.V; i++) {
        for (auto it: graph.adj[i]) {
            inDegree[it]++;
        }
    }

    // find source(s)
    for (auto i = 1; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            queue.push(i);
            sorted[i] = 1; // The first source has a time of 1
        }
    }


    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();

        for (auto neighbor: graph.adj[currentVertex]) {
            inDegree[neighbor]-- ;
            if(inDegree[neighbor] == 0){
                queue.push(neighbor);
                sorted[neighbor] = sorted[currentVertex] + 1;
            }
        }
    }

    // because vertices start with 1
    for(int i= 1; i < sorted.size(); i ++){
        cout<<sorted[i]<<" ";
    }
}


int main() {
    Graph graph(10);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(1, 5);
    graph.addEdge(2, 3);
    graph.addEdge(2, 9);
    graph.addEdge(2, 8);
    graph.addEdge(3, 6);
    graph.addEdge(4, 6);
    graph.addEdge(4, 8);
    graph.addEdge(5, 8);
    graph.addEdge(6, 7);
    graph.addEdge(7, 8);
    graph.addEdge(8, 10);

    findTime(graph);
    return 0;
}