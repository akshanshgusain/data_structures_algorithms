//
// Created by Akshansh Gusain on 09/01/24.
//
#include<bits/stdc++.h>

using namespace std;

bool dfsCheck(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis, vector<bool> &check) {
    vis[node] = true;
    pathVis[node] = true;
    check[node] = false;

    for (auto it: adj[node]) {
        if (!vis[it]) {
            if (dfsCheck(it, adj, vis, pathVis, check)) {
                check[node] = false;
                return true;
            }
        }
        // if the node has been previously visited
        // but it has to be visited on the same path
        else if (pathVis[it]) {
            check[node] = false;
            return true;
        }
    }
    check[node] = true;
    pathVis[node] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    // nodes that are part of a cycle can't be a safe node
    // any node that leads to a cycle can not be a safe node
    vector<bool> vis(graph.size(), false);
    vector<bool> pathVisited(graph.size(), false);
    vector<bool> check(graph.size(), false);

    vector<int> safeNodes;

    for (int i = 0; i < graph.size(); i++) {
        if (!vis[i]) {
            dfsCheck(i, graph, vis, pathVisited, check);
        }
    }
    for(int i=0; i <graph.size(); i++){
        if(check[i]==1){
            safeNodes.push_back(i);
        }
    }

    return safeNodes;
}


int main() {

    return 0;
}