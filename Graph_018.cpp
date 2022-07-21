//
// Created by Akshansh Gusain on 07/09/21.
//
#include<stdc++.h>
using namespace std;

// Time: O(N-1) x O(E)

struct node {
    int u;
    int v;
    int wt;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

void bellmanFord(){

}

int main(){
    vector<node> edges;
    int N = 5;
    edges.push_back(node(0,1,-1));
    edges.push_back(node(0,1,-1));
    edges.push_back(node(0,2,4));
    edges.push_back(node(1,2,3));
    edges.push_back(node(1,3,2));
    edges.push_back(node(1,4,2));
    edges.push_back(node(3,2,5));
    edges.push_back(node(3,1,1));
    edges.push_back(node(4,3,-3));

    int source = 0;
    vector<int> distance(N, INT16_MAX);
    distance[source] = 0;

    // Relaxing the edges
    for(int i= 1; i <=N-1; i++){
        for(auto it: edges){
            if(distance[it.u] + it.wt < distance[it.v]){
                distance[it.v] = distance[it.u] + it.wt;
            }
        }
    }

    int fl = 0;
    for(auto it: edges) {
        if(distance[it.u] + it.wt < distance[it.v]) {
            cout << "Negative Cycle";
            fl = 1;
            break;
        }
    }

    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << i << " " << distance[i] << endl;
        }
    }

    return 0;
}

/*
0 0
1 -1
2 2
3 -2
4 1
 */