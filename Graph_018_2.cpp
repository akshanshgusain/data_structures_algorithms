//
// Created by Akshansh Gusain on 07/09/21.
//
#include<stdc++.h>
using namespace std;

// Time: O(N-1) x O(E)

class Graph {
public:
    int V,E;
    vector<vector<pair<int,int>>> adj;

    Graph(int V){
        this->V = V;
        this->adj.assign(V,vector<pair<int,int>>());
    }

    void addEdge(int first, int second, int weight){
        adj[first].push_back(make_pair(second, weight));
        E++;
    }
};

void bellmanFord(Graph &graph, int source){
    vector<int> distance(graph.V, INT16_MAX);
    distance[source] = 0;

    // Relax all the edges
    for(int i = 0; i < graph.V-1; i++){
        for(int j = 0; j < graph.adj[i].size(); j ++){
            if(distance[graph.adj[i][j].first] != INT16_MAX and
            distance[graph.adj[i][j].first] + graph.adj[i][j].second < )
        }
    }
}

int main(){
    Graph graph(5);
    graph.addEdge(0,1,-1);
    graph.addEdge(0,1,-1);
    graph.addEdge(0,2,4);
    graph.addEdge(1,2,3);
    graph.addEdge(1,3,2);
    graph.addEdge(1,4,2);
    graph.addEdge(3,2,5);
    graph.addEdge(3,1,1);
    graph.addEdge(4,3,-3);

    int source = 0;


    bellmanFord(graph, source);
    return 0;
}
