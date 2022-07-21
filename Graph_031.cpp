//
// Created by Akshansh Gusain on 20/09/21.
//
#include<stdc++.h>
using namespace std;

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

void bellmanFord(vector<node> &edges){
    int N = edges.size();

    vector<int> distance(N, INT_MAX);

    for(int i =0 ; i < N-1; i++){
        for(auto it: edges){
            if(distance[it.u] + it.wt < distance[it.v]){
                distance[it.v] = distance[it.u] + it.wt;
            }
        }
    }
    bool flag = false;
    for(int i =0; i < N-1; i ++){
        for(auto it: edges){
            if(distance[it.u] + it.wt < distance[it.v]){
                flag = true;
                break;
            }
        }
    }

    if(flag){
        cout<<"Cycle Detected";
    }else{
        cout<<"Cycle Not Detected";
    }
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

    bellmanFord(edges);
    return 0;
}
