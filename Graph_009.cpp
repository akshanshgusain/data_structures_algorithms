//
// Created by Akshansh Gusain on 26/08/21.
//
#include<stdc++.h>

using namespace std;

void floodFill(vector<vector<int>> &image, int src, int newColor) {
    int m = image.size();
    int n = image[0].size();

    queue<pair<int, int>> q;
    q.push({src, src});

    int color = image[src][src];
    image[src][src] = newColor;

    while (!q.empty()) {
        auto currentNode = q.front();
        q.pop();

        int i = currentNode.first;
        int j = currentNode.second;

        if ((i + 1) >= 0 and (j + 0) > 0 and (i + 1) < m and (j + 0) < n and image[i + 1][j] == color) {
            q.push({i + 1, j});
            image[i + 1][j] = newColor;
        }

        if ((i + 0) >= 0 and (j + 1) > 0 and (i + 0) < m and (j + 1) < n and image[i][j + 1] == color) {
            q.push({i, j + 1});
            image[i][j + 1] = newColor;
        }

        if ((i + 0) >= 0 and (j - 1) > 0 and (i + 0) < m and (j - 1) < n and image[i][j - 1] == color) {
            q.push({i, j - 1});
            image[i][j - 1] = newColor;
        }

        if ((i - 1) >= 0 and (j - 0) > 0 and (i - 1) < m and (j - 0) < n and image[i-1][j - 0] == color) {
            q.push({i - 1, j - 0});
            image[i - 1][j - 0] = newColor;
        }
    }
}

int main() {
    vector<vector<int>> image = {{1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 0, 0},
                                 {1, 0, 0, 1, 1, 0, 1, 1},
                                 {1, 2, 2, 2, 2, 0, 1, 0},
                                 {1, 1, 1, 2, 2, 0, 1, 0},
                                 {1, 1, 1, 2, 2, 2, 2, 0},
                                 {1, 1, 1, 1, 1, 2, 1, 1},
                                 {1, 1, 1, 1, 1, 2, 2, 1},
    };

    floodFill(image, 4,3);

    for(auto i: image){
        for(auto j : i){
            cout<<j<<"  ";
        }
        cout<<endl;
    }

    return 0;
}
