//
// Created by Akshansh Gusain on 18/09/21.
//https://www.youtube.com/watch?v=3t3JHswP7mw&t=28s
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

void dfs(int node, int parent, vector<bool> &vis, vector<int> &insertionTime,
         vector<int> &minimumTime, int &timer, vector<vector<int>> &adj,
         vector<int> &isArticulation){
        vis[node] = true;
        insertionTime[node] = minimumTime[node] = timer++;
        int child = 0;
        for(auto it: adj[node]){
            if(it == parent){
                continue;
            }

            if(!vis[it]){
                dfs(it, node, vis, insertionTime, minimumTime, timer, adj, isArticulation);
                minimumTime[node] = min(minimumTime[node], minimumTime[it]);
                child++;
                if(minimumTime[it] >= insertionTime[node] and parent != -1){
                    isArticulation[node] = 1;
                }
            }else{
                minimumTime[node] = min(minimumTime[node], insertionTime[it]);
            }
        }

        if(parent == -1 and child > 1){
            isArticulation[node] = 1;
        }
}

int main() {
    int V = 5;
    Graph graph(V);
    graph.addEdgeU(0,1);
    graph.addEdgeU(0,2);
    graph.addEdgeU(1,2);
    graph.addEdgeU(1,3);
    graph.addEdgeU(4,3);

    vector<int> insertionTime(V, -1);
    vector<int> minimumTime(V, -1);
    vector<bool> vis(V, false);
    vector<int> isArticulation(V, 0);
    int timer = 0;

    for(int i= 0; i < V; i++){
        if(!vis[i]){
            dfs(i, -1, vis, insertionTime, minimumTime, timer, graph.adj, isArticulation);
        }
    }

    for(int i = 0;i<V;i++) {
        if(isArticulation[i] == 1) cout << i << endl;
    }


    return 0;
}
