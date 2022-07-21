//
// Created by Akshansh Gusain on 21/08/21.
//

#include<stdc++.h>
using namespace std;

class Graph {
public:
    int V,E;
    vector<vector<int>> adj;

    Graph(int V){
        this->V = V;
        this->adj.assign(V,vector<int>());
    }

    void addEdge(int v, int w){
        adj[v].push_back(w);
        E++;
    }

    /// Undirected Graph
     void addEdgeU(vector<int> adj[], int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
        E++;
    }

};

