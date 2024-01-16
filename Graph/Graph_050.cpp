//
// Created by Akshansh Gusain on 08/01/24.
//
#include<bits/stdc++.h>

using namespace std;

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

int findCircleNum(vector<vector<int>> &isConnected) {
    int N = isConnected.size();

    DisjointSet ds(N);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (isConnected[i][j] == 1) {
                ds.makeUnion(i,j);
            }
        }
    }

    int groupCount = 0;
    for (int i = 0; i < N; i++) {
        if (i == ds.findParent(i)) {
            groupCount++;
        }
    }
    return groupCount;
}

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
    vis[node] = true;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
}

int findCircleNumDFS(vector<vector<int>>& isConnected) {
    int N = isConnected.size();
    // DFS Solution
    vector<vector<int>> adj(N, vector<int>(N, 0));
    for(int i=0; i < N; i++){
        for(int j=0; j < N;j++){
            if(isConnected[i][j]==1 and i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> visited (N, false);
    int count = 0;

    for(int i = 0;i < N; i++){
        if(!visited[i]){
            count++;
            dfs(i, adj, visited);
        }
    }
    return count;
}

int main() {
//    vector<vector<int>>provinces  = {{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}}; // 2
    vector<vector<int>>provinces  = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}}; // 3
    cout<<findCircleNumDFS(provinces);
}