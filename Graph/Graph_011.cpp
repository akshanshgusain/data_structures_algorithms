//
// Created by Akshansh Gusain on 26/10/23.
//
#include<bits/stdc++.h>

using namespace std;

// Number of Operations to Make Network Connected
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class DisjointSet {
    void unionByRank(int node1, int node2) {
        node1 = findParent(node1);
        node2 = findParent(node2);

        if (node1 == node2) {
            return;
        }

        if (rank[node1] > rank[node2]) {
            parent[node2] = node1;
        } else if (rank[node2] > rank[node1]) {
            parent[node1] = node2;
        } else {
            parent[node2] = node1;
            rank[node1]++;
        }
    }

    void unionBySize(int node1, int node2) {}

public:
    vector<int> rank;
    vector<int> parent;

    // works as make_set function
    explicit DisjointSet(int nodes) {
        rank.resize(nodes + 1, 0); // every starting rank is 0
        parent.resize(nodes + 1);
        for (int i = 0; i <= nodes; i++) {
            parent[i] = i; // every node is its own parent
        }
    }

    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        // path compression step
        return parent[node] = findParent(parent[node]);
    }


    void makeUnion(int node1, int node2, int type = 1) {
        if (type == 1) {
            unionByRank(node1, node2);
        } else if (type == 2) {
            unionBySize(node1, node2);
        } else {
            cout << "invalid type of union1" << endl;
        }
    }
};

int makeConnected(int n, vector<vector<int>> &connections, DisjointSet &ds) {

    int N = connections.size();

    // # of wires need to be at most 1 less than # of nodes
    if (n - 1 > N) {
        return -1;
    }

    for (int i = 0; i < N; i++) {
        if (ds.findParent(connections[i][0]) != ds.findParent(connections[i][1])) {
            ds.makeUnion(connections[i][0], connections[i][1]);
        }
    }

    // Count Islands
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ds.parent[i] == i) {
            ans++;
        }
    }
    return ans - 1;

}

int main() {
//    int n = 4;
//    vector<vector<int>> connections = {{0, 1},
//                                       {0, 2},
//                                       {1, 2}};
//
//    int n = 6;
//    vector<vector<int>> connections = {{0, 1},
//                                       {0, 2},
//                                       {0, 3},
//                                       {1, 2},
//                                       {1, 3},
//    };

    int n = 6;
    vector<vector<int>> connections = {{0, 1},
                                       {0, 2},
                                       {0, 3},
                                       {1, 2},};

    DisjointSet ds(n);
    cout << makeConnected(n, connections, ds);

    return 0;
}