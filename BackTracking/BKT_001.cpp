//
// Created by Akshansh Gusain on 15/08/23.
//

#include<bits/stdc++.h>

using namespace std;


// Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
//
// Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).

void solveMazeUtil(
        int i,
        int j,
        vector<vector<int>> &maze,
        int size,
        vector<string> &ans,
        const string& move,
        vector<vector<int>> &vis
) {
    // base case
    if (i == size - 1 and j == size - 1) {
        ans.push_back(move);
    }

    // we will move Down->Left->Right->Up(Lexicographical order)

    // Down
    if (i + 1 < size and !vis[i + 1][j] and maze[i + 1][j] == 1) {
        vis[i][j] = 1;
        solveMazeUtil(i + 1, j, maze, size, ans, move + 'D', vis);
        vis[i][j]= 0;
    }

    // Left
    if (j - 1 > 0 and !vis[i][j - 1] and maze[i][j - 1] == 1) {
        vis[i][j] = 1;
        solveMazeUtil(i, j - 1, maze, size, ans, move + 'L', vis);
        vis[i][j] = 0;
    }


    // Right
    if (j + 1 < size && !vis[i][j + 1] && maze[i][j + 1] == 1) {
        vis[i][j] = 1;
        solveMazeUtil(i, j + 1, maze, size, ans, move + 'R', vis);
        vis[i][j] = 0;
    }

    // Upward
    if (i - 1 >= 0 && !vis[i - 1][j] && maze[i - 1][j] == 1) {
        vis[i][j] = 1;
        solveMazeUtil(i - 1, j, maze, size, ans, move + 'U', vis);
        vis[i][j] = 0;
    }
}

vector<string> solveMaze(vector<vector<int>> &maze) {
    int n = maze.size();
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    if (maze[0][0] == 1) {
        solveMazeUtil(0, 0, maze, n, ans, "", vis);
    }
    return ans;

}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    vector<string> result = solveMaze(maze);
    if (result.empty()) {
        cout << -1;
    } else {
        for (auto it: result) {
            cout << it << " ";
        }
    }
    cout << endl;

    return 0;
}

// output
// DDRDRR DRDDRR