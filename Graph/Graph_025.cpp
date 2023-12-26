//
// Created by Akshansh Gusain on 28/12/23.
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

// The chromatic number of a graph is the minimum number of colors needed to color
// its vertices in such a way that no two adjacent vertices have the same color.

void findChromaticNumber(Graph &g) {
    vector<int> assignedColors(g.V, -1); // store the color assigned to each vertex.
    vector<bool> availableColors(g.V, true); // keep track of available colors for each vertex.
    assignedColors[0] = 0;
    int chromaticNumber = 0;

    // For each vertex i, iterate through its adjacent vertices (x in graph.adj[i]).
    // If the adjacent vertex x has already been assigned a color (result[x] != -1),
    // mark that color as unavailable (colorAvailable[result[x]] = false)
    for (int i = 1; i < g.V; i++) {
        for (auto it: g.adj[i]) {
            if (assignedColors[it] != -1) {
                availableColors[assignedColors[it]] = false;
            }
        }

        // find the first available color for the current vertex by searching through the colorAvailable array.
        int firstAvailableColor;
        for (firstAvailableColor = 0; firstAvailableColor < g.V; firstAvailableColor++) {
            if (availableColors[firstAvailableColor]) {
                break;
            }
        }

        // Assign the first available color to the current vertex (result[i] = firstAvailableColor).
        assignedColors[i] = firstAvailableColor;

        //Update the chromaticNumber to be the maximum of the current chromaticNumber and firstAvailableColor + 1.
        chromaticNumber = max(chromaticNumber, firstAvailableColor + 1);

        // Restore the availability of colors for the adjacent vertices of the current vertex
        for (auto it: g.adj[i]) {
            if (assignedColors[it] != -1) {
                availableColors[assignedColors[it]] = true;
            }
        }

    }

    cout << "Chromatic Number: " << chromaticNumber << endl;
    for (int i = 0; i < g.V; i++) {
        cout << " Vertex: " << i << " is colored :" << assignedColors[i] << endl;
    }

}

int main() {
    Graph graph(8);
    graph.addEdgeU(5, 6);
    graph.addEdgeU(0, 1);
    graph.addEdgeU(1, 3);
    graph.addEdgeU(2, 3);
    graph.addEdgeU(0, 2);
    graph.addEdgeU(2, 4);
    graph.addEdgeU(1, 4);
    graph.addEdgeU(7, 5);
    graph.addEdgeU(7, 6);

    findChromaticNumber(graph);
    return 0;
}