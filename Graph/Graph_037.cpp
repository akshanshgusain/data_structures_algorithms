//
// Created by Akshansh Gusain on 21/09/21.
//

#include<stdc++.h>

using namespace std;

class Graph {
public:
    int V, E;
    vector<vector<pair<int, int>>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<pair<int, int>>());
    }

    /// Undirected Graph
    void addEdgeU(int u, int v, int wt) {
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
        E++;
    }
};

bool pathMoreThanK(Graph &graph, int source, int k, vector<bool> &vis) {

    if(k<=0){
        return true;
    }

    for(auto it: graph.adj[source]){
        int v = it.first;
        int wt = it.second;
        if(vis[v]){
            continue;
        }
        if(wt >= k){
            return true;
        }
        vis[source] = true;

        if(pathMoreThanK(graph,v,k-wt,vis)){
            return true;
        }
        vis[source] = false; //BackTrack

    }
    return false;
}

int main() {
    int V = 9;
    Graph g(V);
    g.addEdgeU(0, 1, 4);
    g.addEdgeU(0, 7, 8);
    g.addEdgeU(1, 2, 8);
    g.addEdgeU(1, 7, 11);
    g.addEdgeU(2, 3, 7);
    g.addEdgeU(2, 8, 2);
    g.addEdgeU(2, 5, 4);
    g.addEdgeU(3, 4, 9);
    g.addEdgeU(3, 5, 14);
    g.addEdgeU(4, 5, 10);
    g.addEdgeU(5, 6, 2);
    g.addEdgeU(6, 7, 1);
    g.addEdgeU(6, 8, 6);
    g.addEdgeU(7, 8, 7);

    int source = 0;
    int k = 60;
    vector<bool> vis(V + 1, false);
    if (pathMoreThanK(g, source, k, vis)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}