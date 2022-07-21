//
// Created by Akshansh Gusain on 18/09/21.
//https://www.youtube.com/watch?v=2rjZH0-2lhk&t=1053s

#include<stdc++.h>
using namespace std;

// Time: O(N+E), Space: O(N)

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

void dfs(int node,
         int parent,
         vector<bool> &vis,
         vector<int> &insertionTime,
         vector<int> &minimumTime,
         int &timer,
         vector<vector<int>> &adj) {
    vis[node] = true;
    insertionTime[node] = minimumTime[node] = timer++;

    for(auto it: adj[node]){
        if( it == parent){
            continue;
        }
        if(!vis[it]){
            dfs(it, node, vis, insertionTime, minimumTime, timer,adj);
            minimumTime[node] = min(minimumTime[node], minimumTime[it]);
            if(minimumTime[it] > insertionTime[node]){
                cout<< node <<" "<< it<<endl;
            }
        }else{
            // minimum insertion time amongst all the adjacent nodes
            minimumTime[node] = min(minimumTime[node], insertionTime[it]);
        }
    }
 }

 /* minimumTime[adjacent] > insertionTime[node] means its a bridge. */
 /* */
int main() {
    Graph graph(5);
    graph.addEdgeU(0, 1);
    graph.addEdgeU(0, 2);
    graph.addEdgeU(1, 2);
    graph.addEdgeU(1, 3);
    graph.addEdgeU(3, 4);

    vector<int> insertionTime(graph.V, -1);
    vector<int> minimumTime(graph.V, -1);
    vector<bool> vis(graph.V, false);
    int timer = 0;

    for (int i = 0; i < graph.V; i++) {
        if (!vis[i]) {
            dfs(i, -1, vis, insertionTime, minimumTime, timer, graph.adj);
        }
    }

    /*
     3 4
     1 3
    */
    return 0;
}