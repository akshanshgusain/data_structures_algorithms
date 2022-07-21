//
// Created by Akshansh Gusain on 31/05/21.
//

#include<stdc++.h>

using namespace std;
#define M 4
#define N 4
int findMax(int gold[M][N], int m, int n){

    for(int col=n-2; col>=0;col-- ){
        for(int row =0; row< m; row++){

            int right = gold[row][col+1];
            int rightUp = (row==0)? 0:gold[row-1][col+1];
            int rightDown = (row==m-1)? 0:gold[row+1][col+1];

            gold[row][col] = gold[row][col] + max(right,
                                                  max(rightUp,rightDown));
        }
    }

    //take max from the first column
    int res = gold[0][0];
    for(int i=0; i<m;i++){
        res = max(res,gold[i][0]);
    }
    return res;
}

int main() {
    int n=4;
    int m = 4;
    int gold[4][4] = {{1, 3, 1, 5},
                                {2, 2, 4, 1},
                                {5, 0, 2, 3},
                                {0, 6, 1, 2}
    };
    cout<<findMax(gold,M,N);
    return 0;
}
