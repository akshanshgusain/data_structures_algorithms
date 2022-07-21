//
// Created by Akshansh Gusain on 13/04/21.
//This this a Brute force approach Find OP takes O(n) and Union OP takes O(n)

#include<stdc++.h>
using namespace std;
vector<int> dsuf;

int find(int v){
    if(dsuf[v] == -1){
        return v;
    }
    return find(dsuf[v]);
}

void union_op(int fromP, int toP){
    fromP = find(fromP);
    toP = find(toP);
    dsuf[fromP] = toP;
}

bool isCyclic(vector<pair<int, int>>& edge_List){

    for(auto p: edge_List){
        int fromP = find(p.first);
        int toP = find(p.second);

        if(fromP == toP){
            return true;
        }

        //union operation
        union_op(fromP, toP);
    }
    return false;
}

int main(){
    int E; // No. Edges
    int V; //No. Vertices
    cin>>E>>V;

    dsuf.resize(V,-1); //Mark all vertices as seperate subsets with only 1 element
    vector<pair<int, int>> edge_list;
    for(int i =0; i<E ;i++){
        int from, to;
        cin>>from>>to;
        edge_list.push_back(make_pair(from,to));
    }

    if(isCyclic(edge_list)){
        cout<<"TRUE \n";
    }else{
        cout<<"FALSE\n";
    }
    return 0;
}