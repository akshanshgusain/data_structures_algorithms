//
// Created by Akshansh Gusain on 28/08/21.
//
//https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/
#include<stdc++.h>
#include "Graph.cpp"
using namespace std;

// Time: O(V+E), Space: O(V)
void timeToComplete(Graph &graph, vector<int> &inDegree){
    queue<int> q;
    vector<int> job(graph.V,0);

    //push all the vertex in the queue whose in-degree is 0
    for(int i = 0 ; i < graph.V; i++){
        if(inDegree[i] == 0){
            q.push(i);
            job[i] = 1;
        }
    }

    while(!q.empty()){
        int currentNode = q.front();
        q.pop();

        for(auto it: graph.adj[currentNode]){
            inDegree[it]--;
            if(inDegree[it] == 0){
                q.push(it);
                job[it] = job[currentNode] + 1;
            }
        }
    }

    for(auto it : job){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    Graph graph(10);
    vector<int> inDegree(10,0);
    graph.addEdge(0,2);inDegree[2]++;
    graph.addEdge(0, 3);inDegree[3]++;
    graph.addEdge(0, 4);inDegree[4]++;
    graph.addEdge(1, 2);inDegree[2]++;
    graph.addEdge(1, 7);inDegree[7]++;
    graph.addEdge(1, 8);inDegree[8]++;
    graph.addEdge(2, 5);inDegree[5]++;
    graph.addEdge(3, 5);inDegree[5]++;
    graph.addEdge(3, 7);inDegree[7]++;
    graph.addEdge(4, 7);inDegree[7]++;
    graph.addEdge(5, 6);inDegree[6]++;
    graph.addEdge(6, 7);inDegree[7]++;
    graph.addEdge(7, 9);inDegree[9]++;

    timeToComplete(graph, inDegree);
    return 0;
}