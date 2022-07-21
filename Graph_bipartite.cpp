//
// Created by Akshansh Gusain on 06/05/21.
//
//1. If you can color the graph with only two colors then bi-partition is possible.
//2.  A bi-graph/ Bipartite graph is a graph whose vertices can be divided into 2 disjoint & independent sets U and V such that
//every edge connects a vertex in U to a vertex in V.
//3. A bipartite graph can only have even edge length cycle.
// Time complexity is O(E+V)
#include<stdc++.h>
using namespace std;
#define pb push_back
#define V 4

bool isBipartite(vector<vector<int>>& adj,int N,int node,vector<int>& color)
{
    queue<int> q;
    q.push(node);
    color[node] = 1;

    //Process current graph component using BFS
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int ele: adj[curr])
        {
            if(color[ele]==color[curr]) //Odd-cycle
                return false;
            if(color[ele]==-1)  //Unvisited node
            {
                color[ele] = 1-color[curr];
                q.push(ele);
            }
        }
    }
    return true;
}

bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    
    vector<vector<int>> adj(N+1);
    for(int i=0;i<dislikes.size();++i)
    {
        adj[dislikes[i][0]].push_back(dislikes[i][1]);
        adj[dislikes[i][1]].push_back(dislikes[i][0]);
    }

    vector<int> color(N+1,-1);
    for(int i=1;i<=N;++i)
        if(color[i]==-1)
            if(!isBipartite(adj,N,i,color))
                return false;
    return true;
}

int main(){

    vector<vector<int>> vec = {{0,1},{0,3},{1,0}, {1,2},{2,1},{2,3},{3,0},{3,2}};
    possibleBipartition(V,vec);
    return 0;
}