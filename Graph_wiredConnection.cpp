//
// Created by Akshansh Gusain on 12/04/21.
//
//https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include<stdc++.h>
using namespace std;

void dfs(int src, vector<int> g[], vector<int> &visited){
    visited[src] = 1;
    for(auto x: g[src]){
        if(!visited[x]){
            dfs(x,g,visited);
        }
    }
}

int makeConnected(int n, vector<vector<int>>& edges){
    vector<int> g[n];
    int m = edges.size();
    //if edges is less than (components - 1) return -1
    if(m < n-1){
        return -1;
    }
    // Making a adjacency list representation of graph
    for(int i =0; i < edges.size() ; i++){
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> vis(n,0);
    int c = 0;
    for(int i =0; i<n; i++){
        if(!vis[i]){
            c++;
            dfs(i,g,vis);
        }
    }

    return c-1;
}

int main(){
    int n = 4;
    vector<vector<int>> connections = {{0,1}, {0,2},{1,2}};

    int count = makeConnected(n, connections);
    cout<<count;
    return 0;
}