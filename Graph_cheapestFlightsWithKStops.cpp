//
// Created by Akshansh Gusain on 06/05/21.
//

#include<stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int K){
    vector<vector<pair<int, int>>> g(n);
    for(auto it: flights){
        g[it[0]].push_back({it[1],it[2]});
    }
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    pq.push(make_tuple(0,src,0));

    while(!pq.empty()){
        auto[cost, u, stop] = pq.top();
        pq.pop();
        if(u == dest){
            return cost;
        }
        if(stop > K){
            continue;
        }
        for( auto child: g[u]){
            auto[v,w] = child;
            pq.push(make_tuple(cost+w,v,stop+1));
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> flights = {{0,1,100}, {1,2,100},{0,2,500}};
    cout<<findCheapestPrice(flights.size(), flights, 0,2,1);
    return 0;
}