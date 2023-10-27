#include<bits/stdc++.h>

using namespace std;



class DisjointSet {
    void unionByRank(int node1, int node2, int &islandCount) {

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

        islandCount--;
    }

    void unionBySize(int node1, int node2) {}

public:
    vector<int> rank;
    vector<int> parent;

    // works as make_set function
    explicit DisjointSet(int nodes) {
        rank.resize(nodes , 0); // every starting rank is 0
        parent.resize(nodes );
        for (int i = 0; i < nodes; i++) {
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


    void makeUnion(int node1, int node2,int &islandCount ,int type = 1) {
        if (type == 1) {
            unionByRank(node1, node2, islandCount);
        } else if (type == 2) {
            unionBySize(node1, node2);
        } else {
            cout << "invalid type of union1" << endl;
        }
    }
};


int numIslandsUnionFind(vector<vector<char>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int islandCount=0;

    int directionVectorCol[4]={0, 1, 0, -1};
    int directionVectorRow[4]={1, 0, -1, 0};

    DisjointSet ds(n*m);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]=='1') {
                islandCount++;
                for(int k=0; k<4; k++) {
                    int ci= directionVectorRow[k] + i;
                    int cj= directionVectorCol[k] + j;
                    if(ci<0 || cj<0 || ci>=n || cj>=m)
                        continue;
                    if(grid[ci][cj]=='1') {
                        ds.makeUnion((i*m)+j, (ci*m)+cj, islandCount);
                    }
                }
            }
        }
    }
    return islandCount;
}

int numIslandDFS(vector<vector<char>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    int islandCount=0;

    int directionVectorCol[4]={0, 1, 0, -1};
    int directionVectorRow[4]={1, 0, -1, 0};


}

int main() {
//    vector<vector<char>> grid = {
//            {'1', '1', '1', '1', '0'},
//            {'1', '1', '0', '1', '0'},
//            {'1', '1', '0', '0', '0'},
//            {'0', '0', '0', '0', '0'}
//    };
// 1

    vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };

// 3
    cout << numIslandsUnionFind(grid);

    return 0;
}
