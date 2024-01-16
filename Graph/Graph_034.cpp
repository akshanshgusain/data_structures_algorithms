//
// Created by Akshansh Gusain on 20/09/21.
//

#include<stdc++.h>
using namespace std;

class Graph {
public:
    int V, E;
    vector<vector<pair<int, int>>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<pair<int, int>>());
    }

    /// directed Graph
    void addEdge(int from, int to, int price) {
        adj[from].push_back({to, price});
        E++;
    }
};

int findCheapestPrice(Graph &graph, int source, int destination, int k) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    pq.push(make_tuple(0, source, 0)); // cost, currNode, stop, (priority queue is sorted by first value).

    while (!pq.empty()) {
        auto[cost, currNode, stops] = pq.top();
        pq.pop();

        if (currNode == destination) {
            return cost;
        }

        if (stops > k) {
            continue;
        }

        for (auto child: graph.adj[currNode]) {
            auto[v, wt] = child;
            pq.push(make_tuple(cost+wt,v,stops+1));
        }
    }

    return -1;
}


int main() {
    Graph graph(6);
    graph.addEdge(0, 1, 100);
    graph.addEdge(1, 2, 100);
    graph.addEdge(0, 2, 500);

    int src = 0, dest = 2, k = 1;
    cout << findCheapestPrice(graph, src, dest, k);

    return 0;
}