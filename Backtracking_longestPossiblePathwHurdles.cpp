//
// Created by Akshansh Gusain on 30/03/21.
//
#include<stdc++.h>
using namespace std;
#define R 3
#define C 10

struct Pair{
    bool found; //true if the destination is found
    int value; //store the cost of longest path from current cell to destination cell;
};

Pair findLongestPathUtil(int mat[R][C], int i, int j, int x, int y, bool visited[R][C]){
    // if (i, j) itself is destination, return true
    if (i == x && j == y)
    {
        Pair p = { true, 0 };
        return p;
    }

    // if not a valid cell, return false
    if (i < 0 || i >= R || j < 0 || j >= C ||
        mat[i][j] == 0 || visited[i][j])
    {
        Pair p = { false, INT_MAX };
        return p;
    }

    // include (i, j) in current path i.e.
    // set visited(i, j) to true
    visited[i][j] = true;

    // res stores longest path from current cell (i, j) to
    // destination cell (x, y)
    int res = INT_MIN;

    // go left from current cell
    Pair sol = findLongestPathUtil(mat, i, j - 1, x, y, visited);

    // if destination can be reached on going left from current
    // cell, update res
    if (sol.found)
        res = max(res, sol.value);

    // go right from current cell
    sol = findLongestPathUtil(mat, i, j + 1, x, y, visited);

    // if destination can be reached on going right from current
    // cell, update res
    if (sol.found)
        res = max(res, sol.value);

    // go up from current cell
    sol = findLongestPathUtil(mat, i - 1, j, x, y, visited);

    // if destination can be reached on going up from current
    // cell, update res
    if (sol.found)
        res = max(res, sol.value);

    // go down from current cell
    sol = findLongestPathUtil(mat, i + 1, j, x, y, visited);

    // if destination can be reached on going down from current
    // cell, update res
    if (sol.found)
        res = max(res, sol.value);

    // Backtrack
    visited[i][j] = false;

    // if destination can be reached from current cell,
    // return true
    if (res != INT_MIN)
    {
        Pair p = { true, 1 + res };
        return p;
    }

        // if destination can't be reached from current cell,
        // return false
    else
    {
        Pair p = { false, INT_MAX };
        return p;
    }

}
void findLongestPath(int mat[R][C], int i, int j, int x, int y){
    // create a boolean matrix to store info about
    // cells already visited in current route
    bool visited[R][C];
    memset(visited, false, sizeof visited);

    //find longest rout from (i,j) to (x,y) and print max. cost
    Pair p = findLongestPathUtil(mat, i, j, x,y, visited);
    if(p.found){
        cout<<"Length of the longest possible route is : "<<p.value;
    }else{
        cout << "Destination not reachable from given source";
    }

}

int main(){
    // input matrix with hurdles shown with number 0
    int mat[R][C] =
            {
                    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                    { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
            };

    // find longest path with source (0, 0) and
    // destination (1, 7)
    findLongestPath(mat, 0, 0, 1, 7);
    return 0;
}
