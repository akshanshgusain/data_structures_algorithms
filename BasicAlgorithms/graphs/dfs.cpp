//
// Created by Akshansh Gusain on 25/06/24.
//

#include<bits/stdc++.h>

using namespace std;

void dfsUtil(int source, vector<vector<int>> &g, vector<bool> &visited) {
    visited[source] = true;
    cout<< source << " -> ";

    for(auto it: g[source]){
        if(!visited[it]){
            dfsUtil(it, g, visited);
        }
    }
}

void dfs(vector<vector<int>> &g) {
    vector<bool> visited(g.size(), false);

    for (int v = 0; v < g.size(); v++) {
        if (!visited[v]) {
            dfsUtil(v, g, visited);
        }
    }
}

int main() {
    vector<vector<int>> graph = {{}};

    return 0;
}