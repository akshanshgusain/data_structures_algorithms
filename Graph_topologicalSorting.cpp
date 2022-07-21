//
// Created by Akshansh Gusain on 11/04/21.
//
#include<stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]){
    vector<int> in(V,0); // vector to store in-degree
    vector<int> ans;
    queue<int> q;
    for(int i=0; i<V; i++){
        for(auto x : adj[i]){
            in[x]++;
        }
    }
    for(int i=0; i<V;i++){
        if(in[i] == 0){
            q.push(i);
        }
    }

    //BFS
    while(!q.empty()){
        int td = q.front();
        q.pop();
        ans.push_back(td);
        for(auto x: adj[td]){
            in[x]--;
            if(in[x] == 0){
                q.push(x);
            }
        }
    }

    return ans;
}
int main(){
    vector<int> adj[6] = {{5,2}, {5,0}, {4,0}, {4,1}, {2,3}, {3,1}};
    vector<int> ans = topoSort(5,adj);
    for(auto a: ans){
        cout<<a<<"  ";
    }
    return 0;
}
