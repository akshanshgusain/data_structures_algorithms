//
// Created by Akshansh Gusain on 21/08/21.
//
#include<stdc++.h>
#include "Graph.cpp"
using namespace std;

/// DFS , Time: O(v+e)

bool checkCycle(int node, Graph &graph, vector<int> &used, vector<int> &dfsUsed) {
    used[node] = 1;
    dfsUsed[node] = 1;

    for(auto it : graph.adj[node]) {
        if(!used[it]) {
            if(checkCycle(it, graph, used, dfsUsed)) return true;
        } else if(dfsUsed[it]) {
            return true;
        }
    }
    dfsUsed[node] = 0;
    return false;
}

bool isCyclic(int N, Graph &graph) {
    vector<int> used(N, 0);
    vector<int> dfsUsed(N, 0); // we need to maintain a visited array for DFS Calls starting at every Node.

    for(int i = 0;i<N;i++) {
        if(!used[i]) {
            if(checkCycle(i, graph, used, dfsUsed)) {
                return true;
            }
        }
    }
    return false;
}

/// BFS , Time: O(v+e)
// We will use the Topological sort with BFS (Kahn's Algorithm) that only works if the given graph is a DAG.
// if we supply a cyclic graph to this algorithm then it won't generate anything
bool isCyclic2(Graph &graph){
    vector<int> topo;
    vector<int> inDegree(graph.V,0);
    queue<int> q;

    for(int i =0 ; i < graph.V ; i ++){
        for(auto  it: graph.adj[i]){
            inDegree[i]++;
        }
    }

    for(int i = 0 ; i < graph.V ; i ++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    int count = 0;
    while(!q.empty()){
        int currentVertex = q.front();
        q.pop();
        count++;
        for(auto it: graph.adj[currentVertex]){
            inDegree[it]--;
            if(inDegree[it] == 0){
                q.push(it);
            }
        }
    }

    if(count == graph.V){
        return false;
    }
    return true;
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout<<"DFS Cycle Check: "<<endl;
    if(isCyclic(g.V, g))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";

    cout<<endl<<"BFS/Kahn's Cycle Check: "<<endl;

    if(isCyclic2( g))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
/*

DFS Cycle Check:
Graph contains cycle
BFS/Kahn's Cycle Check:
Graph contains cycle

*/