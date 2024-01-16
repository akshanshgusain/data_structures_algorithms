//
// Created by Akshansh Gusain on 20/09/21.
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

    /// Undirected Graph
    void addEdgeU(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        E++;
    }
};

void dfs(int source, int parent, int &timer,
         vector<int> &inTime,
         vector<int> &outTime,
         vector<vector<int>> &adj) {

    inTime[source] = timer++;
    for (auto it: adj[source]) {
        if(it != parent){
            dfs(it, source, timer, inTime, outTime, adj);
        }
    }

    outTime[source] = timer++;
}

bool checkIsSubTree(int x, int y, vector<int> &inTime, vector<int> &outTime){
    if(inTime[x] > inTime[y] and outTime[x] < outTime[y]){
        return true;
    }
    return false;
}

int main() {
    Graph graph(9);
    graph.addEdgeU(0, 1);
    graph.addEdgeU(0, 2);
    graph.addEdgeU(1, 5);
    graph.addEdgeU(1, 6);
    graph.addEdgeU(5, 8);
    graph.addEdgeU(6, 7);
    graph.addEdgeU(2, 3);
    graph.addEdgeU(2, 4);

    vector<int> inTime(graph.V + 1);
    vector<int> outTime(graph.V + 1);
    int timer = 1;

    int bobDirection = 0; // 0 for Away from Mansion, 1 for Towards the Mansion.
    int oliverLocation = 8;
    int bobLocation = 1;

    dfs(0, -1, timer, inTime, outTime, graph.adj);

    // Check If x is in the sub-tree of y or vice versa.
    if(!checkIsSubTree(bobDirection,oliverLocation, inTime, outTime) and
        !checkIsSubTree(oliverLocation, bobLocation, inTime,outTime)){
        cout<<"No";
        return 0;
    }

    if(bobDirection == 0){
        if(checkIsSubTree(oliverLocation, bobLocation, inTime,outTime)){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
    }else if(bobDirection == 1){
        if(checkIsSubTree(bobDirection,oliverLocation, inTime, outTime)){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
    }
    return 0;
}
