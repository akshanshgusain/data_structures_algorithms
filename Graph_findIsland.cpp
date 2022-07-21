//
// Created by Akshansh Gusain on 13/04/21.
//

#include<stdc++.h>

using namespace std;
#define ROW 5
#define COL 5

void mark_current_island(vector<vector<int>> &matrix, int x, int y, int r, int c) {
    if (x < 0 || x >= r || y < 0 || y >= c || matrix[x][y] != 1)  //Boundary case for matrix
        return;

    //Mark current cell as visited
    matrix[x][y] = 2;

    //Make recursive call in all 4 adjacent directions
    mark_current_island(matrix, x + 1, y, r, c);  //DOWN
    mark_current_island(matrix, x, y + 1, r, c);  //RIGHT
    mark_current_island(matrix, x - 1, y, r, c);  //TOP
    mark_current_island(matrix, x, y - 1, r, c);  //LEFT
}

int numIslands(vector<vector<int>>& grid) {


    int rows = grid.size();
    if (rows == 0)     //Empty grid boundary case
        return 0;
    int cols = grid[0].size();

    //Iterate for all cells of the array
    int no_of_islands = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                mark_current_island(grid, i, j, rows, cols);
                no_of_islands += 1;
            }
        }
    }
    return no_of_islands;
}

int main() {
    vector<vector<int>>vect(ROW, vector<int>(COL));
    vect = { { 1, 1, 0, 0, 0 },
             { 0, 1, 0, 0, 1 },
             { 1, 0, 0, 1, 1 },
             { 0, 0, 0, 0, 0 },
             { 1, 0, 1, 0, 1 } };

    cout << "Number of islands is: " << numIslands(vect);
    return 0;
}