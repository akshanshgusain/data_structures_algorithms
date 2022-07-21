//
// Created by Akshansh Gusain on 15/09/21.
//

// https://www.youtube.com/watch?v=oNTsS8lGDHw
#include<stdc++.h>
using namespace std;

// Time: O(NLogN), Space: O(N)

class Graph {
public:
    int V, E;
    vector<vector<pair<int, int>>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<pair<int, int>>());
    }

    void addEdge(int first, int second, int weight) {
        adj[first].push_back(make_pair(second, weight));
        E++;
    }
};

void primsMST(Graph &graph) {
    vector<int> edgeWeight(graph.V, INT_MAX);
    vector<bool> mst(graph.V, false);
    vector<int> parent(graph.V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;// {edgeWeight[i], i}

    edgeWeight[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for (auto it: graph.adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mst[v] == false && weight < edgeWeight[v]) {
                parent[v] = u;
                edgeWeight[v] = weight;
                pq.push({edgeWeight[v], v});
            }
        }
    }

    for (int i = 1; i < graph.V; i++)
        cout << parent[i] << " - " << i << " \n";

}

int main() {
    Graph graph(6);
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 10);
    graph.addEdge(0, 3, 100);
    graph.addEdge(1, 3, 50);
    graph.addEdge(1, 4, 200);
    graph.addEdge(3, 4, 250);
    graph.addEdge(4, 5, 50);

    primsMST(graph);
    return 0;
}
