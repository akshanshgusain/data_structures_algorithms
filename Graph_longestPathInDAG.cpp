//
// Created by Akshansh Gusain on 06/05/21.
//

/*6 7
1
0 1 5
1 5 5
5 3 2
3 2 20
4 2 10
5 2 50
1 4 2*/
#include<stdc++.h>
using namespace std;

vector<int> order;
void topo(int src, vector<int> &vis, vector<vector<pair<int, int>>> g ){
    vis[src] = 1;
    for(auto x:g[src]){
        if(!vis[x.first]){
            topo(x.first, vis, g);
        }
    }
    order.push_back(src);
}

int main(){
    int v, e;
    cin>>v>>e;
    int src;
    cin>>src;

    vector<vector<pair<int ,int>>> g(v);
    for(int i=0; i<e; i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,x});
    }

    vector<int> vis(v,0);
    for(int i=0; i<v; i++){
        if(!vis[i]){
            topo(i, vis, g);
        }
    }

    vector<int> dist(v);
    for(int i =0; i<v ;i++){
        dist[i] = INT_MIN;
    }
    dist[src] = 0;
    for(int i= v; i>=0; i++){
        if(dist[order[i]] != INT_MIN){
            for(auto it: g[order[i]]){
                int v =dist[it.first];
                int w = it.second;
                int u = dist[order[i]];
                if(u+w > v){
                    dist[it.first] = u+w;
                }
            }

        }
    }

    for(int i=0;i<v ;i++){
        if(i != src and dist[i]!= INT_MIN){
            cout<<" -> "<<i<<" = "<<dist[i]<<endl;
        }
    }

    return 0;
}
