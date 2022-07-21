//
// Created by Akshansh Gusain on 28/08/21.
//
#include<stdc++.h>
#include "Graph.cpp"

using namespace std;

void dfs(int node, Graph &graph, vector<int> &used, stack<int> &st){
    used[node] = 1;
    for(auto it: graph.adj[node]){
        if(!used[it]){
            dfs(it, graph,used,st);
        }
    }
    st.push(node);
}

vector<char> findOrder(vector<string> &dict, int K) {
    // We need to build a graph of this dictionary
    Graph graph(K);

    for (int i = 0; i < dict.size() - 1; i++) {
        string w1 = dict[i];
        string w2 = dict[i + 1];

        for (int j = 0; j < min(w1.length(), w2.length()); j++) {
            if (w1[j] != w2[j]) {
                graph.adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                break;
            }
        }
    }

    // Call topological sort
    stack<int> st;
    vector<int> used(graph.V, 0);
    for(int i=0 ; i < graph.V; i++){
        if(!used[i]){
            dfs(i, graph, used, st);
        }
    }

    vector<char> topo;
    while(!st.empty()){
        topo.push_back(st.top() + 'a');
        st.pop();
    }

    return topo;
}

int main() {
    int K = 4;
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    vector<char> topo =  findOrder(dict, K);
    for(auto it: topo){
        cout<<it<<" ";
    }
    return 0;
}
