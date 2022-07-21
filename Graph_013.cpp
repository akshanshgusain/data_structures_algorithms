//
// Created by Akshansh Gusain on 27/08/21.
//

#include<stdc++.h>
using namespace std;

///Dijkstra's Algorithm - Single Source Shortest Path
// Time: O((N+E)logN) ~ O(NlogN), Space: O(N) + O(N)
class Graph {
public:
    int V,E;
    vector<vector<pair<int,int>>> adj;

    Graph(int V){
        this->V = V;
        this->adj.assign(V,vector<pair<int,int>>());
    }

    void addEdge(int v, int u, int w){
        adj[v].push_back({u,w});
        E++;
    }

    void addEdgeU(int v, int u, int w){
        adj[v].push_back({u,w});
        adj[u].push_back({v,w});
        E++;
    }
};

void dijkstras(Graph &graph, int source){
    // Min Heap; In pair => (dist,from)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<int> distTo(graph.V+1, INT16_MAX);

    distTo[source] = 0;
    pq.push(make_pair(0,source));

    while(!pq.empty()){
        int prevNode = pq.top().second;
        pq.pop();

        for(auto it: graph.adj[prevNode]){
            int nextNode = it.first;
            int nextNodeDist = it.second;
            if(distTo[nextNode] > (distTo[prevNode] + nextNodeDist)){
                distTo[nextNode] = distTo[prevNode] + nextNodeDist;
                pq.push(make_pair(distTo[nextNode], nextNode));
            }
        }
    }

    cout<<"The Distance from source, "<<source<<", are: "<<endl;
    for(int i =1; i < graph.V; i++){
        cout<<distTo[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Graph graph(9);
    // Edge: (V, {U,WT})
    graph.addEdgeU(0,1,4);
    graph.addEdgeU(0,7,8);
    graph.addEdgeU(1,2,8);
    graph.addEdgeU(1,7,11);
    graph.addEdgeU(2,3,7);
    graph.addEdgeU(2,8,2);
    graph.addEdgeU(2,5,4);
    graph.addEdgeU(3,4,9);
    graph.addEdgeU(3,5,14);
    graph.addEdgeU(4,5,10);
    graph.addEdgeU(5, 6, 2);
    graph.addEdgeU(6, 7, 1);
    graph.addEdgeU(6, 8, 6);
    graph.addEdgeU(7, 8, 7);

    int source = 0;

    dijkstras(graph,source);

    /*
        The Distance from source, 0, are:
        4 12 19 21 11 9 8 14
    */

    return 0;
}