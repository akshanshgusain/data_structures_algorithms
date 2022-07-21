//
// Created by Akshansh Gusain on 15/04/21.
//
#include<stdc++.h>
using namespace std;
#define V 6

// Time: O(V^3), Space: O(V^2)


void floyd_warshall(int graph[V][V]){
    int dist[V][V];

    //Assign all values of the graph to allPairs_SP
    for(int i=0; i<V ;i++){
        for(int j=0; j<V; j++){
            dist[i][j] = graph[i][j];
        }
    }

    //find all pairs shortest path by trying all possible paths
    for(int k= 0; k< V; k++){ //Try all intermediate nodes
        for(int i = 0; i<V; i++){   // Try for all starting positions
            for(int j=0; j<V ;j ++){ //Try for all possible ending positions
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX){ //Skip if k is unreachable from  i or j is unreachable from k
                        continue;
                    }else if(dist[i][k]+dist[k][j] < dist[i][j]){ // Check if new distance is shorter via vertex k
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
            }
        }
    }
    //check for negative edge weight cycle
    for(int i= 0; i <V; i++){
        if(dist[i][i] < 0){
            cout<<"Negative edge weight cycle is present"<<endl;
            return;
        }
    }

    //print Shortest Path Graph
    //Values printed as INT_MAX defines there is no Path
    for(int i= 0; i <V; i++){
        for(int j= 0; j <V; j++){
            cout<<i<<" to "<<j<<" distance is "<<dist[i][j]<<endl;
            cout<<"=============================="<<endl;
            return;
        }
    }
}
int main(){
    int graph[V][V] = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
                        {INT_MAX, 0, 4, 2, 7, INT_MAX},
                        {INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
                        {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
                        {INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
                        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0} };

    floyd_warshall(graph);

    return 0;
}
