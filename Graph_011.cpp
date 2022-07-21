//
// Created by Akshansh Gusain on 26/08/21.
//
#include<stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>> graph, vector<int> &used){
    used[node] = 1;
    for(auto it: graph[node]){
        if(!used[it]){
            dfs(it, graph,used);
        }
    }
}


int makeConnected(int numOfComputers, vector<vector<int>>& connections) {
    vector<vector<int>> graph;
    graph.assign(numOfComputers,vector<int>());

    int availableWires = connections.size();

    if(availableWires < numOfComputers - 1){
        return -1;
    }

    // make a undirected graph
    for(int i =0 ; i< connections.size(); i++){
        graph[connections[i][0]].push_back(connections[i][1]);
        graph[connections[i][1]].push_back(connections[i][0]);
    }

    vector<int> used(numOfComputers,0);
    int count = 0;

    for(int i = 0; i < numOfComputers; i++){
        if(!used[i]){
            count++;
            dfs(i, graph,used);
        }
    }
    return count-1;
}

int main(){
    int n = 4;
    vector<vector<int>> connections = {{0,1}, {0,2},{1,2}};
    int count = makeConnected(n, connections);
    cout<<count;
    return 0;
}
