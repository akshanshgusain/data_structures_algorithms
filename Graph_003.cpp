//
// Created by Akshansh Gusain on 21/08/21.
//

#include<stdc++.h>
using namespace std;

class Graph{
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
    // void addEdge(vector<int> adj[], int u, int v)
    //{
    //    adj[u].push_back(v);
    //    adj[v].push_back(u);
    //    E++;
    //}
};

void DFSUtil(int u, Graph &graph, vector<bool> &used){
    used[u] = true;
    cout<<u<<" -> ";

//    for(int i = 0 ; i < graph.adj[u].size(); i++){
//        if(!used[graph.adj[u][i]]){
//            DFSUtil(graph.adj[u][i], graph, used);
//        }
//    }
    for(auto it: graph.adj[u]){
        if(!used[it]){
            DFSUtil(it, graph, used);
        }
    }
}

void traverseDFS(Graph &graph){
    vector<bool> used(graph.V, false);
    for(int u = 0; u < graph.V; u++){ // We need this for loop to cover all vertices(even if some of them are disconnected).
        if(!used[u]){
            DFSUtil(u, graph, used);
        }
    }
}

int main(){
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Following is Depth First Traversal"<<endl;
    traverseDFS(graph); //0 -> 1 -> 2 -> 3 -> 4 ->

    return 0;
}