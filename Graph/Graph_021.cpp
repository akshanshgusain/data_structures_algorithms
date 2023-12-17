//
// Created by Akshansh Gusain on 12/12/23.
//

#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    int V, E;
    vector<vector<pair<int, int>>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<pair<int, int>>());
    }

    // Undirected Graph

    void addEdgeUWeighted(int u, int v, int w) {
        adj[v].emplace_back(u, w);
        adj[u].emplace_back(v, w);
        E++;
    }

    // Directed Graph
    void addEdgeWeighted(int v, int u, int w) {
        adj[v].emplace_back(u, w);
        E++;
    }

    void print() {
        cout << endl;
        int i = 0;
        for (const auto &vertexList: this->adj) {
            cout << i << "th - ";
            for (auto it: vertexList) {
                cout << it.first << " weighted at: " << it.second << " ";
            }
            cout << endl;
            i++;
        }
    }
};

class DisjointSet {
    vector<int> rank;
    vector<int> parent;

    void unionByRank(int node1, int node2) {
        node1 = findParent(node1);
        node2 = findParent(node2);

        if (node1 == node2) {
            return;
        }

        if (rank[node1] > rank[node2]) {
            parent[node2] = node1;
        } else if (rank[node2] > rank[node1]) {
            parent[node1] = node2;
        } else {
            parent[node2] = node1;
            rank[node1]++;
        }
    }

    void unionBySize(int node1, int node2) {}

public:
    // works as make_set function
    explicit DisjointSet(int nodes) {
        rank.resize(nodes + 1, 0); // every starting rank is 0
        parent.resize(nodes + 1);
        for (int i = 0; i <= nodes; i++) {
            parent[i] = i; // every node is its own parent
        }
    }

    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        // path compression step
        return parent[node] = findParent(parent[node]);
    }


    void makeUnion(int node1, int node2, int type = 1) {
        if (type == 1) {
            unionByRank(node1, node2);
        } else if (type == 2) {
            unionBySize(node1, node2);
        } else {
            cout << "invalid type of union1" << endl;
        }
    }
};

void sortEdges(Graph &g, vector<pair<int, pair<int, int>>> &edges){
    for(int i=0; i<g.V; i++){
        for(auto it: g.adj[i]){
            int nextNode = it.first;
            int weight = it.second;
            int node = i;
            edges.push_back({weight, {node, nextNode}});
        }
    }

    sort(edges.begin(), edges.end());
}

void kruskalMST(Graph &g) {
    vector<pair<int, pair<int, int>>> edges;
    sortEdges(g, edges);

    DisjointSet ds(g.V);
    int mstW = 0;
    vector<pair<int, int>> mst;

    for(auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findParent(u) != ds.findParent(v)){
            mstW += wt;
            ds.makeUnion(u, v);
            mst.push_back({u,v});
        }
    }

    cout << mstW << endl;
    for(auto it : mst) cout << it.first << " - " << it.second << endl;

}

int main() {
    Graph graph(6);
    graph.addEdgeUWeighted(0, 1, 5);
    graph.addEdgeUWeighted(0, 2, 10);
    graph.addEdgeUWeighted(0, 3, 100);
    graph.addEdgeUWeighted(1, 3, 50);
    graph.addEdgeUWeighted(1, 4, 200);
    graph.addEdgeUWeighted(3, 4, 250);
    graph.addEdgeUWeighted(4, 5, 50);
    kruskalMST(graph);
    return 0;
}