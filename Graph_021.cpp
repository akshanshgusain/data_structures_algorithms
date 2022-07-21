//
// Created by Akshansh Gusain on 14/09/21.
//

#include<stdc++.h>
using namespace std;

// Time: O(MLogM) + O(M x O(4alpha)) = O(MLogM), Space: O(M) + (O(N)+O(N) Disjoint Set) = O(N)
// Store the graph in a Linear DS rather than an Adjacency List, because we want to sort node according to weight.

struct Node{
    int u;
    int v;
    int weight;
    Node(int first, int second, int weight){
        u = first;
        v= second;
        this->weight = weight;
    }
};

bool compare(Node a, Node b){
    return a.weight < b.weight;
}

int findParent(int u, vector<int> &parent){
    if(u== parent[u]){
        return u;
    }
    return parent[u] = findParent(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(u, parent);
    v = findParent(v, parent);

    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    vector<Node> edges;
    /*
           10
       0--------1
       | \ |
         6| 5\ |15
       | \ |
       2--------3
           4
    */
    int N = 6;

    edges.push_back(Node(0,1,10));
    edges.push_back(Node(0,2,6));
    edges.push_back(Node(0,3,5));
    edges.push_back(Node(1,3,15));
    edges.push_back(Node(2,3,4));
    edges.push_back(Node(2,3,4));

    sort(edges.begin(), edges.end(), compare);

    // Parent vector
    vector<int> parent(N);
    for(int i = 0;i<N;i++)
        parent[i] = i;

    // Rank vector
    vector<int> rank(N, 0);

    int cost = 0;
    vector<pair<int,int>> mst;

    for(auto it : edges) {
        if(findParent(it.v, parent) != findParent(it.u, parent)) {
            cost += it.weight;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }

    cout << cost << endl;
    for(auto it : mst) cout << it.first << " - " << it.second << endl;

    /*
     19
    2 - 3
    0 - 3
    0 - 1*/

    return 0;
}