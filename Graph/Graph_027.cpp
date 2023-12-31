//
// Created by Akshansh Gusain on 29/12/23.
//
#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    int V, E;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<int>());
    }

    // Undirected Graph
    void addEdgeU(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        E++;
    }

    // Directed Graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        E++;
    }

    void print() {
        cout << endl;
        int i = 0;
        for (const auto &vertexList: this->adj) {
            cout << i << "th - ";
            for (auto it: vertexList) {
                cout << it << " ";
            }
            cout << endl;
            i++;
        }
    }
};

void dfs(
        int node,
        int parent,
        vector<bool> &visited,
        vector<int> &discoveryTime,
        vector<int> &minTime,
        int timer,
        Graph &g,
        vector<vector<int>> &bridges) {

    visited[node] = true;
    discoveryTime[node] = minTime[node] = timer;
    timer++;

    for (auto it: g.adj[node]) {
        if (it == parent) {
            continue;
        }
        if (!visited[it]) {
            // simple case of DFS
            dfs(it, node, visited, discoveryTime, minTime, timer, g, bridges);
            minTime[node] = min(minTime[node], minTime[it]);
            // check for bridge: node -- it
            if (minTime[it] > discoveryTime[node]) {
                // If Adj.Node's min time is greater than discovery time of current node
                // i.e., adj Node won't be able to reach current node
                bridges.push_back({node, it});
            }
        } else {
            // bridge is not possible,
            // simply update the lowest time
            minTime[node] = min(minTime[node], minTime[it]);
        }
    }
}

void findBridges(Graph &g) {
    vector<int> discoveryTime(g.V, -1);
    vector<int> minTime(g.V, -1);
    vector<bool> visited(g.V, false);
    vector<vector<int>> bridges;

    int timer = 0;

    for (int i = 0; i < g.V; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, discoveryTime, minTime, timer, g, bridges);
        }
    }

    for (auto &bridge: bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }
}

bool makeEqual(vector<string> &words) {
    vector<int> count(26, 0);
    for (auto word: words) {
        for (auto chari: word) {
            count[chari - 'a']++;
        }
    }
    for (auto cnt: count) {
//        cout<<cnt<<" ";
        if (cnt % words.size() != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    Graph graph(5);
    graph.addEdgeU(0, 1);
    graph.addEdgeU(0, 2);
    graph.addEdgeU(1, 2);
    graph.addEdgeU(1, 3);
    graph.addEdgeU(3, 4);

//    findBridges(graph);
    vector<string> words = {"abc", "aabc", "bc"};
//    vector<string> words = {"ab", "a"};
    cout << makeEqual(words);
    return 0;
}