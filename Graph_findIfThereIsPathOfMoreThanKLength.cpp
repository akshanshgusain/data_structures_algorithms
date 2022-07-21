//
// Created by Akshansh Gusain on 07/05/21.
//
//Find if there is a path of more than k length from a source
//Given a graph, a source vertex in the graph and a number k, find if there
// is a simple path (without any cycle) starting from given source and ending
// at any other vertex.

//The idea is to use Backtracking. We start from given source, explore all
// paths from current vertex. We keep track of current distance from source.
// If distance becomes more than k, we return true. If a path doesn’t produces
// more than k distance, we backtrack
//Back Tracking
#include<stdc++.h>
using namespace std;

bool solve(int src, int k, vector<pair<int, int>> g[], vector<bool> &vis){
    vis[src] = true;
    if(k<=0){
        return true;
    }

    for(auto it: g[src]){
        int u = it.first;
        int w = it.second;
        if(vis[u] == true){
            continue;
        }
        if(w >= k){
            return true;
        }
        if(solve(u,k-w,g,vis)){
            return true;
        }
        vis[src] = false;
        return false;
    }
}

int main(){
    int v, e;
    cin>>v>>e;

    int k;
    cin>>k;
    vector<pair<int, int>> g[v+1];

    for(int i=0; i<e; i++){
        int x,y, w;
        cin>>x>>y>>w;
        g[x].emplace_back(y,w);
        g[y].emplace_back(x,w);
    }
    vector<bool> vis(v+1,false);
    cout<<solve(1,k,g,vis);
    return 0;
}