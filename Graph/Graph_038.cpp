//
// Created by Akshansh Gusain on 21/09/21.
//https://www.youtube.com/watch?v=wuVwUK25Rfc&t=12s

#include<stdc++.h>

using namespace std;
//https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/

// Time: O(V+E), Space: O(V)
class Graph {
public:
    int V, E;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<int>());
    }

    /// Undirected Graph
    void addEdgeU(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        E++;
    }
};

bool canColor(int node, int maxColors, vector<int> &color, Graph &g) {
    vector<int> vis(g.V, false);
    int maxColorTillNow = 1;

    for (int i = 1; i <= g.V; i++) {
        if (vis[i]) {
            continue;
        }
        vis[i] = true;
        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int top = q.front();
            q.pop();

            // checking all Adjacent Nodes
            for(auto it: g.adj[top]){
                // If the color of the adj node is same, increase it by 1
                if(color[top] == color[it]){
                    color[it]++;
                }

                maxColorTillNow = max(maxColorTillNow,
                                      max(color[top], color[it]));
                if(maxColorTillNow > maxColors){
                    return false;
                }

                if(!vis[it]){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
    }
    return true;
}

int main() {
    Graph g(4);
    g.addEdgeU(0, 1);
    g.addEdgeU(0, 3);
    g.addEdgeU(1, 2);
    g.addEdgeU(2, 0);
    g.addEdgeU(2, 3);

    vector<int> color(g.V, 1);
    int maxColors = 3;

    if (canColor(0, maxColors, color, g)) {
        cout << "Can Color";
    } else {
        cout << "Cannot Color";
    }
    return 0;
}