//
// Created by Akshansh Gusain on 12/04/21.
//https://www.youtube.com/watch?v=t2d-XYuPfg0
//Optimised: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

// we need 3 data structures - 1. Array/set(precessed) to keep track of visited nods. 2. Array/map (value)to keep track of shortest path
//3. Array(parent) - To form the shortest path graph.

//Time Complexity: O(v^2)

/*Steps :
 * 1. Pick the min. value node which is unprocessed.
 * 2. mark this node as processed.
 * 3. Update all adjacent vertices. If cost[U] + wt[UV] < cost[V] then update */


#include<stdc++.h>
using namespace std;
#define V 6

int selectMinVertex(vector<int>& value, vector<bool>& processed){
    int min = INT_MAX;
    int vertex;
    for(int i=0; i<V;i++){
        if(processed[i]==false and value[i]<min){
            vertex = i;
            min = value[i];
        }
    }
    return vertex;
}

void dijkastra(int graph[V][V]){
    int parent[V]; //Stores shortest Path structure;
    vector<int> value(V,INT_MAX); // Keeps shortest path values to each vertex from source
    vector<bool> processed(V, false); //TRUE -> Vertex is precessed

    //Assuming start point as Node 0
    parent[0] = -1;
    value[0] = 0;

    //Include (V-1) edges to cover all V vertices
    for(int i=0; i<V ;i++){
        //Select best vertex by greedy approach
        int U = selectMinVertex(value,processed);
        processed[U] = true; //Include the new vertex in the shortest path graph

        //relax adjacent vertices (not yet included in shortest path graph)
        for(int j=0; j<V ;j++){
            /* 3 conditions to relax: -
                    1. Edge is present from U to j.
                    2. vertex j is not included in shortest path graph
                    3. Edge weight is smaller than current edge weight.
            */
            if(graph[U][j] != 0
               and !processed[j]
               and value[U] != INT_MAX
               and (value[U]+graph[U][j] < value[j])){
                value[j] = value[U]+graph[U][j];
                parent[j] = U;
            }

        }
    }
    //Print Shortest path
    for(int i=0; i<V;i++){
        cout<<"U -> V: "<< parent[i]<<"->"<<i<<" wt = "<<graph[parent[i]][i]<<endl;
    }
}

int main(){

    int graph[V][V] = {{0,1,4,0,0,0},
                       {1,0,4,2,7,0},
                       {4,4,0,3,5,0},
                       {0,2,3,0,4,6},
                       {0,7,5,4,0,7},
                       {0,0,0,6,7,0}};
    dijkastra(graph);

    return 0;
}