//
// Created by Akshansh Gusain on 01/09/23.
//

#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    int V, E;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<int>());
    }

    // Undirected Graph
    void addEdgeU(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        E++;
    }

    // Directed Graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        E++;
    }

    void print() {
        cout << endl;
        int i = 0;
        for (const auto &vertexList: this->adj) {
            cout << i << "th - ";
            for (auto it: vertexList) {
                cout << it << " ";
            }
            cout << endl;
            i++;
        }
    }
};

bool findTime(Graph &graph) {
    vector<int> inDegree(graph.V, 0);
    vector<int> job(graph.V, 0);
    queue<int> queue;

    // find out the in degree
    for(int i= 0; i < graph.V; i++){
        for(auto it: graph.adj[i]){
            inDegree[it]++;
        }
    }

    // find source
    for(int i= 0;i < graph.V; i++){
        if(inDegree[i] == 0){
            queue.push(i);
            job[i] = 1;
        }
    }

    while(!queue.empty()){
        int currentNode = queue.front();
        queue.pop();

        for(auto it: graph.adj[currentNode]){
            inDegree[it]--;
            if(inDegree[it] == 0){
                queue.push(it);
                job[it] = job[currentNode] + 1;
            }
        }
    }

    for (auto it: inDegree) {
        if (it > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    Graph graph(3);
    graph.addEdge(1,0);
    graph.addEdge(2,1);
    graph.addEdge(3,2);
//    graph.addEdge(0,1);

    cout<<findTime(graph);

    return 0;
}

