//
// Created by Akshansh Gusain on 21/08/21.
//

/*
 The algorithm can be understood as a fire spreading on the graph: at the zeroth step only the source s is on fire.
 At each step, the fire burning at each vertex spreads to all of its neighbors. In one iteration of the algorithm,
 the "ring of fire" is expanded in width by one unit (hence the name of the algorithm).

 More precisely, the algorithm can be stated as follows: Create a queue q which will contain the vertices to be
 processed and a Boolean array used[] which indicates for each vertex, if it has been lit (or visited) or not.

 Initially, push the source s to the queue and set used[s]=true, and for all other vertices v set used[v]=false.
 Then, loop until the queue is empty and in each iteration, pop a vertex from the front of the queue. Iterate
 through all the edges going out of this vertex and if some of these edges go to vertices that are not already
 lit, set them on fire and place them in the queue.
*/

// time: O( v + e)
#include<stdc++.h>
using namespace std;

// Adjacency List representation of a graph:
// vector<vector<int>> graph;
//    graph[0].push_back(1);
//    graph[0].push_back(2);
//    graph[1].push_back(2);
//    graph[2].push_back(0);
//    graph[2].push_back(3);
//    graph[3].push_back(3);

// Same can be encapsulated in a class
class Graph{
public:
    int V,E;
    vector<vector<int>> adj;

    Graph(int V){
        this->V = V;
        this->adj.assign(V,vector<int>());
    }

    /// Add w to v's List
    void addEdge(int v, int w){
        adj[v].push_back(w);
        E++; /// Every time you add a new Edge increment the counter
    }

    /// Undirected Graph
    // void addEdge(vector<int> adj[], int u, int v)
    //{
    //    adj[u].push_back(v);
    //    adj[v].push_back(u);
    //    E++;
    //}
};

// This BFS won't work for disconnected Graph
void traverseBFS(Graph &graph, int S){
    vector<bool> used(graph.V,false);
    queue<int> queue;

    // mark current vertex(S) visited and enqueue it.
    used[S] = true;
    queue.push(S);

    while(!queue.empty()){
        int currentVertex = queue.front();
        cout<<currentVertex<<" -> ";
        queue.pop();

        for(int u : graph.adj[currentVertex]){
            if(!used[u]){
                used[u] = true;
                queue.push(u);
            }
        }
    }
}

/// You can also calculate the lengths of the shortest paths (which just requires maintaining an
/// array of path lengths d[]) as well as save information to restore all of these shortest paths
/// (for this, it is necessary to maintain an array of "parents" p[], which stores for each vertex
/// the vertex from which we reached it).

void traverseBFSPath(Graph &graph, int S){
    vector<bool> used(graph.V,false);
    vector<int> pathLength(graph.E);
    vector<int> parent(graph.V); //stores for each vertex the vertex from which we reached it
    queue<int> queue;

    // mark current vertex(S) visited and enqueue it.
    used[S] = true;
    queue.push(S);
    parent[S] = -1;

    while(!queue.empty()){
        int currentVertex = queue.front();
        cout<<currentVertex<<" -> ";
        queue.pop();

        for(int u : graph.adj[currentVertex]){
            if(!used[u]){
                used[u] = true;
                queue.push(u);
                pathLength[u] = pathLength[currentVertex] + 1;
                parent[u] = currentVertex;
            }
        }
    }

    cout<<endl<<"Shortest Path from Source to 3"<<endl;
    int  u = 3;
    if (!used[u]) {
        cout << "No path!";
    } else {
        vector<int> path;
        for (int v = u; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v << " ";
    }

}

int main() {
    Graph graph(4);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.addEdge(2,0);
    graph.addEdge(2,3);
    graph.addEdge(3,3);

    cout<<"BFS stating at vertex 2, S=2"<<endl;
    traverseBFSPath(graph, 2);
    return 0;
}
