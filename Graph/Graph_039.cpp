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
    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v,wt});
        E++;
    }
};

int countMinEdgesToReverse(vector<vector<int>> &g, int V,
                           int source, int destination){
    // 1.  Create a graph with given edges, assign weight 0.
    // 2.  Add reverse edges with weight 1.

    Graph graph(V);
    for(auto it: g){
        graph.addEdge(it[0], it[1], 0);
        graph.addEdge(it[1], it[0], 1);
    }

    // Run Dijkastra's
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> distTo(graph.V, INT_MAX);

    distTo[source] = 0;
    pq.push({distTo[0], source});

    while(!pq.empty()){
        int prevNode = pq.top().second;
        pq.pop();

        for(auto it: graph.adj[prevNode]){
            int nextNode = it.first;
            int nextNodeDistance = it.second;
            if(distTo[nextNode] > (distTo[prevNode] + nextNodeDistance)){
                distTo[nextNode] = distTo[prevNode] + nextNodeDistance;
                pq.push({distTo[nextNode],nextNode });
            }
        }
    }
    for(auto it: distTo){
        cout<<it<<" ";
    }
    cout<<endl;
    return distTo[destination];
}

int main(){
    vector<vector<int>> g = {{0, 1}, {2, 1}, {2, 3}, {5, 1},
                             {4, 5}, {6, 4}, {6, 3}};
    int source = 0;
    int destination = 6;
    cout<<countMinEdgesToReverse(g, 7, source, destination);
    return 0;
}
