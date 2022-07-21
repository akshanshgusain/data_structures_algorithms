//
// Created by Akshansh Gusain on 14/09/21.
//

/// Disjoint Set Union DS | Union by Rank and Path Compression
// https://www.youtube.com/watch?v=3gbO7FDYNFQ

// Time: O(4alpha) ~ O(4) for finding the parent, Space: O(N)

// Sudo Code:
#include<stdc++.h>
using namespace std;

int parent[1000];
int rankDSU[1000];

void makeSet(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i; // Every node is its own parent
        rankDSU[i] = 0;  /// Starting rankDSU is 0
    }
}

//  7 -> 6 -> 4 -> 3
int findParent(int node) {
    if (node == parent[node]) {
        return node;
    }
    // Path compression
    return parent[node] = findParent(parent[node]);
}

void unionL(int u, int v) {
    u = findParent(u);
    v = findParent(v);

    if(rankDSU[u] < rankDSU[v]){
        parent[u] = v;
    }else if(rankDSU[u] > rankDSU[v]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rankDSU[u]++;
    }
}


int main() {
    makeSet(5);
    int m;
    while(m--){
        int u, v;
        unionL(u, v);
    }
    // if node 2 and 3 belong to the same component or not
    if(findParent(2) != findParent(3)){
        cout<<"Different Component";
    }else{
        cout<<"Same Component";
    }
}
