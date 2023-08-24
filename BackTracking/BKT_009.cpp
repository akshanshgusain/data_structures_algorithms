//
// Created by Akshansh Gusain on 22/08/23.
//

/*
 Given a path in the form of a rectangular matrix having few landmines arbitrarily placed (marked as 0), calculate
 length of the shortest safe route possible from any cell in the first column to any cell in the last column of the
 matrix. We have to avoid landmines and their four adjacent cells (left, right, above and below) as they are also
 unsafe. We are allowed to move to only adjacent cells which are not landmines. i.e. the route cannot contains any
 diagonal moves.
 */

#include<bits/stdc++.h>

using namespace std;

struct Cell{
    int x;
    int y;
};

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
vector<int> xDirectionVector = {-1, 0, 0, 1};
vector<int> yDirectionVector = {0, -1, 1, 0};

bool isValid(int x, int y, int rows, int cols) {
    if (x < rows && y < cols && x >= 0 && y >= 0){
        return true;
    }
    return false;
}


void findShortestPath(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // if a landmines is found
            if (mat[i][j] == 0) {

                // mark all adjacent cells
                for (int k = 0; k < xDirectionVector.size(); k++)
                    if (isValid(i + xDirectionVector[k], j + yDirectionVector[k], rows, cols))
                        mat[i + xDirectionVector[k]][j + yDirectionVector[k]] = -1;
            }
        }
    }

    // mark all found adjacent cells as unsafe

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == -1)
                mat[i][j] = 0;
        }
    }


    vector<vector<int>> distance(rows, vector<int>(cols, -1));
    queue<Cell> q;

    for (int i = 0; i < rows; i++) {
        if (mat[i][0] == 1) {
            q.push(Cell{i, 0});
            distance[i][0] = 0;
        }
    }

    while (!q.empty()) {
        Cell cell = q.front();
        q.pop();

        int d = distance[cell.x][cell.y];

        int x = cell.x;
        int y = cell.y;

        for (int k = 0; k < xDirectionVector.size(); k++) {
            int nextX = x + xDirectionVector[k];
            int nextY = y + yDirectionVector[k];

            if (isValid(nextX, nextY, rows, cols) && distance[nextX][nextY] == -1 && mat[nextX][nextY] == 1) {
                distance[nextX][nextY] = d + 1;
                q.push(Cell{nextX, nextY});
            }
        }
    }

    // stores minimum cost of shortest path so far
    int ans = INT_MAX;

    // After BFS completes, the code calculates the minimum distance from the source to the rightmost column
    // while considering only cells that are safe and reachable.
    for (int i = 0; i < rows; i++) {
        if (mat[i][cols - 1] == 1 && distance[i][cols - 1] != -1) {
            ans = min(ans, distance[i][cols - 1]);
        }
    }

    // if destination can not be reached
    if (ans == INT_MAX){
        cout << "NOT POSSIBLE\n";
    }
    else{
        cout << "Length of shortest safe route is " << ans << endl;
    }


    cout<<"Distance Vector: \n\n";
    for(const auto &ix: distance){
        for(auto it: ix){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<int>> mat = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1}
    };

    findShortestPath(mat);
    return 0;
}