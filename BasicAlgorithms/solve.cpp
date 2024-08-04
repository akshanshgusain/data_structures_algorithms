//
// Created by Akshansh Gusain on 25/06/24.
//

#include<bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &g, int source) {
    vector<bool> visited(g.size(), false);
    queue<int> queue;

    visited[source] = true;
    queue.push(source);

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        cout<<node<<" ";
        for(auto it: g[node]){
            if(!visited[it]){
                visited[it] = true;
                queue.push(it);
            }
        }
    }
}

int main() {

    return 0;
}