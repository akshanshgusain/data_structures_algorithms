//
// Created by Akshansh Gusain on 28/12/23.
//

#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V, E;
    vector<vector<pair<int,int>>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<pair<int, int>>());
    }

    // Undirected Graph

    void addEdgeUWeighted(int u, int v, int w) {
        adj[v].emplace_back(u,w);
        adj[u].emplace_back(v,w);
        E++;
    }

    // Directed Graph
    void addEdgeWeighted(int v, int u, int w){
        adj[v].emplace_back(u,w);
        E++;
    }

    void print() {
        cout << endl;
        int i = 0;
        for (const auto &vertexList: this->adj) {
            cout << i << "th - ";
            for (auto it: vertexList) {
                cout << it.first << " weighted at: "<<it.second<<" ";
            }
            cout << endl;
            i++;
        }
    }
};

// Space: O(V+E), Time: O(E logV)
void primsMST(Graph &g){
    vector<int> edgeWeights(g.V, INT_MAX);
    vector<int> visited(g.V, false);
    vector<int> parent(g.V, -1);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
    // {edgeWeight[i], i}

    // pick an arbitrary node
    edgeWeights[0] = 0;
    pq.emplace(0,0); //{edgeWeight[i], i}

    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        visited[node] = true;

        for(auto it : g.adj[node]){
            int nextNode = it.first;
            int edgeWeight = it.second;
            if(!visited[nextNode] and edgeWeight < edgeWeights[nextNode]){
                parent[nextNode] = node;
                edgeWeights[nextNode] = edgeWeight;
                pq.push({edgeWeights[nextNode], nextNode});
            }
        }
    }

    for(int i = 1 ; i < g.V; i++){
        cout << parent[i] << " - " << i << " \n";
    }
}

int main(){
    Graph graph(6);
    graph.addEdgeUWeighted(0, 1, 5);
    graph.addEdgeUWeighted(0, 2, 10);
    graph.addEdgeUWeighted(0, 3, 100);
    graph.addEdgeUWeighted(1, 3, 50);
    graph.addEdgeUWeighted(1, 4, 200);
    graph.addEdgeUWeighted(3, 4, 250);
    graph.addEdgeUWeighted(4, 5, 50);
    primsMST(graph);

    return 0;
}