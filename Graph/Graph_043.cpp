//
// Created by Akshansh Gusain on 22/09/21.
//
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

    void addEdgeU(int u, int v) {
        adj[u].push_back(v);
        E++;
    }
};


int main() {
    int V = 4;
    Graph graphUndirected(V);
    graphUndirected.addEdgeU(0, 1);
    graphUndirected.addEdgeU(0, 2);
    graphUndirected.addEdgeU(1, 0);
    graphUndirected.addEdgeU(1, 2);
    graphUndirected.addEdgeU(1, 3);
    graphUndirected.addEdgeU(2, 0);
    graphUndirected.addEdgeU(2, 1);
    graphUndirected.addEdgeU(2, 3);
    graphUndirected.addEdgeU(3, 1);
    graphUndirected.addEdgeU(3, 2);

    bool isDirected = false;
    int countTriangles = 0;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            for (int k = 0; k < V; k++) {
                if(graphUndirected.adj[i][j] and graphUndirected.adj[j][k] and graphUndirected.adj[k][i]){
                    countTriangles++;
                }
            }
        }
    }
    if(isDirected){
        countTriangles /= 3;
    }else{
        countTriangles /= 6;
    }

    cout<<countTriangles;

    return 0;
}
