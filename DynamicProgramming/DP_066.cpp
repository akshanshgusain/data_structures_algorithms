//
// Created by Akshansh Gusain on 31/12/21.
//

#include<stdc++.h>

using namespace std;
#define M 4
#define N 4

// goldTable[i][j] stores the max. value if you start your dig at
// goldMine[i][j].
// the Least values will at goldTable[x][N], that is last column
// So N-1 th colum will be our starting point.

int findMax(int goldMine[M][N]) {
    int goldtable[M][N];
    memset(goldtable, 0, sizeof goldtable);

    for(int col = N-2; col >= 0; col--){
        for(int row = 0; row < M; row++){

            int right = goldMine[row][col+1];

            //If you have a row above the current position take that value
            // otherwise take 0
            int rightUp = (row==0) ? 0 : goldMine[row-1][col+1];

            //If you have a row below the current position take that value
            // otherwise take 0
            int rightDown = (row == M-1) ? 0: goldMine[row+1][col+1];

            // take maximum of these values:
            goldtable[row][col] = goldMine[row][col] +
                    max(right, max(rightUp, rightDown));
        }
    }

    // Find the max from the first columns
    int res = goldMine[0][0];
    for(int i=0; i<M;i++){
        res = max(res,goldMine[i][0]);
    }
    return res;

}

int main() {
    int goldMine[M][N] = {{1, 3, 1, 5},
                          {2, 2, 4, 1},
                          {5, 0, 2, 3},
                          {0, 6, 1, 2}
    };
    cout << findMax(goldMine);
    return 0;
}