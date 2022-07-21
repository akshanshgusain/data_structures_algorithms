//
// Created by Akshansh Gusain on 23/08/21.
//

#include<stdc++.h>
#include "Graph.cpp"
using namespace std;

/// Un-directed Graphs
// Time: O(V + E), Space: O(V+E) + O(N) + O(N)
/// DFS


bool checkForCycle(int node, int parent, vector<int> &used, Graph &graph){
    used[node] = true;
    for(auto it: graph.adj[node]){
        if(used[it] == 0){
            if(checkForCycle(it, node, used, graph)){
                return true;
            }else if(it != parent){
                return true;
            }
        }
    }

    return false;
}


bool isCyclic(Graph &graph){
    vector<int> used(graph.V, 0);
    for(int i = 0; i< graph.V; i++){
        if(!used[i]){
            if(checkForCycle(i, -1, used, graph)){
                return true;
            }
        }
    }
    return false;
}


/// BFS
// Time: O(V + E), Space: O(V+E) + O(N) + O(N)
bool checkForCycle(int node, Graph &g, vector<int> &used){
    queue<pair<int, int>> q;
    used[node] = 1;
    q.push({node, -1});

    while(!q.empty()){
        int currentVertex = q.front().first;
        int currentVertexsParent = q.front().second;
        q.pop();

        for(auto it: g.adj[currentVertex]){
            if(!used[it]){
                used[it] = 1;
                q.push({it, currentVertex});
            }else if(currentVertexsParent != it){
                return true;
            }
        }
    }

    return false;
}

bool isCyclic2(Graph &g){
    vector<int> used(g.V,0);
    for(int i =0 ; i< g.V; i++){
        if(!used[i]){
            if(checkForCycle(i, g, used)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
//    Graph g(4);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 2);
//    g.addEdge(2, 0);
//    g.addEdge(2, 3);
//    g.addEdge(3, 3);

    cout<<"DFS Cycle Check: "<<endl;
    if(isCyclic(g))
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