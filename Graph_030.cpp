//
// Created by Akshansh Gusain on 19/09/21.
//https://www.youtube.com/watch?v=nbgaEu-pvkU


// Observation :
// A graph with odd length cycle can't be a bipartite graph.
// Steps:
// 1. Run a BFS and keep track of colors of each node.
// 2. Constantly checking if the adjacent nodes have the same color or not.
// 3. If they have the same color then break and print "NOT a Bipartite."
#include<stdc++.h>

using namespace std;

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

bool bfs(int source, vector<vector<int>> &adj, vector<int> &color){
    queue<int> q;
    q.push(source);
    color[source] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                q.push(it);
            }else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}


bool isBipartite(Graph &graph) {
    vector<int> color(graph.V, -1);

    for (int i = 0; i < graph.V; i++) {
        if (color[i] == -1){
            if(!bfs(i, graph.adj, color)){
                return false;
            }
        }
    }
    return true;
}

int main() {
    int V = 9;
    Graph graph(V);
    graph.addEdgeU(8, 7);
    graph.addEdgeU(0, 1);
    graph.addEdgeU(1, 2);
    graph.addEdgeU(2, 3);
    graph.addEdgeU(3, 4);
    graph.addEdgeU(4, 6);
    graph.addEdgeU(6, 7);
    graph.addEdgeU(1, 7);
    graph.addEdgeU(4, 5);

    Graph graph2(8);
    graph.addEdgeU(7, 7);
    graph.addEdgeU(0, 1);
    graph.addEdgeU(1, 2);
    graph.addEdgeU(2, 3);
    graph.addEdgeU(3, 4);
    graph.addEdgeU(4, 6);
    graph.addEdgeU(6, 1);
    graph.addEdgeU(4, 5);

    if (isBipartite(graph2)) {
        cout << "YES";
        return 0;
    }
    cout << "NO";

    return 0;
}