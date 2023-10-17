//
// Created by Akshansh Gusain on 17/10/23.
//
#include<bits/stdc++.h>

using namespace std;

class DisjointSet {
    vector<int> rank;
    vector<int> parent;

    void unionByRank(int node1, int node2) {
        node1 = findParent(node1);
        node2 = findParent(node2);

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

int main() {
    DisjointSet ds(7);
    ds.makeUnion(1,2);
    ds.makeUnion(2,3);
    ds.makeUnion(4,5);
    ds.makeUnion(6,7);
    ds.makeUnion(5,6);

    if (ds.findParent(3) == ds.findParent(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not Same"<<endl;
    }

    ds.makeUnion(3,7);

    if (ds.findParent(3) == ds.findParent(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not Same"<<endl;
    }

    return 0;
}