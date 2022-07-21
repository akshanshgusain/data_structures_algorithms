//
// Created by Akshansh Gusain on 10/04/21.
//
#include<stdc++.h>

using namespace std;

class Graph {
    int V; // no. vertices
    list<int> *adj; //ptr to an array containing adjacency lists.

public:
    Graph(int V);

    void addEdge(int v, int w); //Add edge to the graph;

    void BFS(int s); //BFS starting at source s
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph:: addEdge(int v, int w){
    adj[v].push_back(w);  // w to v's list
}

void Graph::BFS(int s){
    //Mark all the vertices as not visible;
    bool *visited = new bool[V];
    for(int i= 0; i<V;i++){
        visited[i] = false;
    }

    //create a queue for BFS
    list<int> queue;

    //Mark current node as visited and enqueue it.
    visited[s] = true;
    queue.push_back(s);

    //i will be used to get all adjacent vertices of a vertex
    list<int>:: iterator i;

    while(!queue.empty()){
        //Deque a vertex from the queue and print it
        s = queue.front();
        cout<< s <<" ";
        queue.pop_front();

        //Get adjacent vertices of dequeued vertex. If the adjacent is not visited mark it visited and enqueue it
        for(i = adj[s].begin(); i != adj[s].end() ;i++){
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}
