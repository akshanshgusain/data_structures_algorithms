//
// Created by Akshansh Gusain on 18/09/21.
//
#include<stdc++.h>
using namespace std;

// Time: O(N^2)

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

void findChromaticNumber(Graph &graph) {
    vector<int> result(graph.V, -1);
    vector<bool> colorAvailable(graph.V, true);
    result[0] = 0;
    int chromaticNumber = 0;

    for (int i = 1; i < graph.V; i++) {
        for (auto x: graph.adj[i]) {
            if (result[x] != -1) {
                colorAvailable[result[x]] = false;
            }
        }

        int firstAvailableColor;
        for (firstAvailableColor = 0; firstAvailableColor < graph.V; firstAvailableColor++) {
            if (colorAvailable[firstAvailableColor] == true) {
                break;
            }
        }

        result[i] = firstAvailableColor;
        chromaticNumber = max(chromaticNumber, firstAvailableColor + 1);

        for (auto x: graph.adj[i]) {
            if (result[x] != -1) {
                colorAvailable[result[x]] = true;
            }
        }
    }

    cout<<"Chromatic Number: "<<chromaticNumber<<endl;
    for(int i = 0 ; i < graph.V; i++){
        cout<<" Vertex: "<< i<<" is colored :"<<result[i]<<endl;
    }

}

int main() {
    Graph graph(7);
    graph.addEdgeU(5, 6);
    graph.addEdgeU(0, 1);
    graph.addEdgeU(1, 3);
    graph.addEdgeU(2, 3);
    graph.addEdgeU(0, 2);
    graph.addEdgeU(2, 4);
    graph.addEdgeU(1, 4);

    findChromaticNumber(graph);
    return 0;
}
