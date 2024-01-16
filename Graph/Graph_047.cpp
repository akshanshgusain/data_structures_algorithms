//
// Created by Akshansh Gusain on 07/03/22.
//
#include<stdc++.h>

using namespace std;

// Time: O(V+E)
class Graph {
public:
    int V, E;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<int>());
    }

    void addEdge(int v, int w){
        adj[v].push_back(w);
        E++;
    }

    /// Undirected Graph
    void addEdgeU(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        E++;
    }
};

// A utility function to delete an edge in an
// undirected graph.
void delEdge(vector<vector<int>> &adj, int u, int v)
{
    // Traversing through the first vector list
    // and removing the second element from it
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == v) {
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }

    // Traversing through the second vector list
    // and removing the first element from it
    for (int i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] == u) {
            adj[v].erase(adj[v].begin() + i);
            break;
        }
    }
}


void printEulerianPath(Graph &g) {
    int odd = 0, startPoint = 0;
    for (int i = 0; i < g.V; i++) {
        if (g.adj[i].size() % 2 == 1) {
            odd++;
            startPoint = i;
        }
    }

    if (odd > 2) {
        cout << "NO Eulerian Path possible";
        return;
    }

    // If solution exists
    stack<int> st;
    vector<int> ePath;
    int currVertex = startPoint;
    while (!st.empty() or !g.adj[currVertex].empty()) {
        if(g.adj[currVertex].empty()){
            ePath.push_back(currVertex);
            currVertex = st.top();
            st.pop();
        }else{
            for(auto it:  g.adj[currVertex]){
                st.push(currVertex);
//                g.adj[currVertex].erase(g.adj[i].begin() + i);
//                g.adj[i].erase(g.adj[currVertex].begin() + i);
                delEdge(g.adj, currVertex, it);
                currVertex = it;
                break;
            }
        }
    }

    for(auto it: ePath){
        cout<<it<<" ";
    }
    cout<<currVertex;
}

int main() {
    Graph graph(3);
    graph.addEdgeU(0, 4);
    graph.addEdgeU(0, 1);
    graph.addEdgeU(3, 1);
    graph.addEdgeU(3, 2);
    graph.addEdgeU(1, 2);

    printEulerianPath(graph);
    return 0;
}
