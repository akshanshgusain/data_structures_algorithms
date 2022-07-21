//
// Created by Akshansh Gusain on 11/04/21.
//
#include<stdc++.h>

using namespace std;
// Dimentions of paint screen
#define M 8
#define N 8

void dfs(vector<vector<int>> &image, int sr, int sc, int color, int newColor) {

    if (image[sr][sc] == color) {
        image[sr][sc] = newColor;
        //check upward
        if (sr >= 1) dfs(image, sr - 1, sc, color, newColor);
        //check left
        if (sc >= 1) dfs(image, sr, sc - 1, color, newColor);
        //check downward
        if (sr + 1 < image.size()) dfs(image, sr + 1, sc, color, newColor);
        //check right
        if (sc + 1 < image[0].size()) dfs(image, sr, sc + 1, color, newColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int color = image[sr][sc];
    if (color != newColor) {
        dfs(image, sr, sc, color, newColor);
    }
    return image;
}

int main() {

    vector<vector<int>> image = {{1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 0, 0},
                                 {1, 0, 0, 1, 1, 0, 1, 1},
                                 {1, 2, 2, 2, 2, 0, 1, 0},
                                 {1, 1, 1, 2, 2, 0, 1, 0},
                                 {1, 1, 1, 2, 2, 2, 2, 0},
                                 {1, 1, 1, 1, 1, 2, 1, 1},
                                 {1, 1, 1, 1, 1, 2, 2, 1},};
    int startingRow = 4, startingColumn = 4;
    int newColor = 6;

    vector<vector<int>> newImage = floodFill(image, startingRow, startingColumn, newColor);
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
            cout << newImage[i][j] << " ";
        cout << endl;
    }
    return 0;
}
