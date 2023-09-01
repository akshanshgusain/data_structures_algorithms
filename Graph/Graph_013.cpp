//
// Created by Akshansh Gusain on 01/09/23.
//
#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    int V, E;
    vector<vector<pair<int, int>>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<pair<int, int>>());
    }

    // Undirected Graph

    void addEdgeUWeighted(int u, int v, int w) {
        adj[v].emplace_back(u, w);
        adj[u].emplace_back(v, w);
        E++;
    }

    // Directed Graph
    void addEdgeWeighted(int v, int u, int w) {
        adj[v].emplace_back(u, w);
        E++;
    }

    void print() {
        cout << endl;
        int i = 0;
        for (const auto &vertexList: this->adj) {
            cout << i << "th - ";
            for (auto it: vertexList) {
                cout << it.first << " weighted at: " << it.second << " ";
            }
            cout << endl;
            i++;
        }
    }
};

void printShortestPath(Graph &graph, int source, vector<int> &distanceTo) {
    cout << "The Distance from source, " << source << ", are: " << endl;
    for (int i = 1; i < graph.V; i++) {
        cout << distanceTo[i] << " ";
    }
    cout << endl;
}

void dijkstraHeap(Graph &graph, int source) {
    vector<int> distanceTo(graph.V, INT_MAX);
    // pair<distance, vertex>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;

    distanceTo[source] = 0;
    heap.emplace(0, source);

    while (!heap.empty()) {
        // greedy pick the shortest distance
        auto currentVertex = heap.top().second;
        heap.pop();

        for (auto it: graph.adj[currentVertex]) {
            int neighbour = it.first;
            int neighbourDistance = it.second;

            // relax the new edge
            if (distanceTo[neighbour] > (distanceTo[currentVertex] + neighbourDistance)) {
                distanceTo[neighbour] = distanceTo[currentVertex] + neighbourDistance;
                heap.emplace(distanceTo[neighbour], neighbour);
            }
        }
    }

    printShortestPath(graph, source, distanceTo);
}


void dijkstraSet(Graph &graph, int source) {
    vector<int> distanceTo(graph.V, INT_MAX);
    // pair<distance, vertex>
    set<pair<int, int>> set;

    distanceTo[source] = 0;
    set.insert({0, source});

    while (!set.empty()) {
        // greedy pick the shortest distance
        auto v = *(set.begin());
        int currentVertex = v.second;
        int distanceToCurrentVertex = v.second;
        set.erase(v);

        for (auto it: graph.adj[currentVertex]) {
            int neighbour = it.first;
            int neighbourDistance = it.second;

            // relax the new edge
            if (distanceTo[neighbour] > (distanceTo[currentVertex] + neighbourDistance)) {
                if (distanceTo[neighbour] != INT_MAX) {
                    set.erase({distanceTo[neighbour], neighbour});
                }
                distanceTo[neighbour] = distanceTo[currentVertex] + neighbourDistance;
                set.insert({distanceTo[neighbour], neighbour});
            }
        }
    }

    printShortestPath(graph, source, distanceTo);
}

int main() {
    Graph graph(9);
    graph.addEdgeUWeighted(0, 1, 4);
    graph.addEdgeUWeighted(0, 7, 8);
    graph.addEdgeUWeighted(1, 2, 8);
    graph.addEdgeUWeighted(1, 7, 11);
    graph.addEdgeUWeighted(2, 3, 7);
    graph.addEdgeUWeighted(2, 8, 2);
    graph.addEdgeUWeighted(2, 5, 4);
    graph.addEdgeUWeighted(3, 4, 9);
    graph.addEdgeUWeighted(3, 5, 14);
    graph.addEdgeUWeighted(4, 5, 10);
    graph.addEdgeUWeighted(5, 6, 2);
    graph.addEdgeUWeighted(6, 7, 1);
    graph.addEdgeUWeighted(6, 8, 6);
    graph.addEdgeUWeighted(7, 8, 7);

    int source = 0;

    dijkstraHeap(graph, source);
    return 0;
}

//The Distance from source, 0, are:
//4 12 19 21 11 9 8 14