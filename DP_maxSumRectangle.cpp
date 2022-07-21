//
// Created by Akshansh Gusain on 04/06/21.
//
#include<stdc++.h>

using namespace std;
#define ROW 4
#define COL 5

int kadane(vector<int> ans, int col) {
    int maxi = INT_MIN;
    int maxTH = 0;

    for (int i = 0; i < col; i++) {
        maxTH += ans[i];
        if (maxTH > maxi) {
            maxi = maxTH;
        }
        if (maxTH < 0) {
            maxTH = 0;
        }
    }
    return maxi;
}

int solve(vector<vector<int>> mat) {
    int ma = INT_MIN;

    for (int i = 0; i < ROW; i++) {

        vector<int> ans(COL);
        for (int j = i; j < ROW; j++) {
            for (int col = 0; col < COL; col++) {
                ans[col] += mat[j][col];
            }
            ma = max(ma, kadane(ans, COL));
        }
    }
    return ma;
}

int main() {
    vector<vector<int>> mat = {{1,  2,  -1, -4, -20},
                               {-8, -3, 4,  2,  1},
                               {3,  8,  10, 1,  3},
                               {-4, -1, 1,  7,  -6}};
    cout << solve(mat);
    return 0;
}
