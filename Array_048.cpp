//
// Created by Akshansh Gusain on 02/08/21.
//
#include<stdc++.h>

using namespace std;

// Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of
// indexes such that both c > a and d > b.

// We pre-process the matrix such that index(i, j) stores max of elements in matrix from (i, j) to (N-1, N-1) and
// In the process keeps on updating maximum value found so far.
// We finally return the maximum value.

int findMaxVal(vector<vector<int>> mat){
    int row = mat.size();
    int col = mat[0].size();

    int maxVal = INT_MIN; // Stores maximum value
    // stores max of elements in vector from (i, j) to (N-1, N-1)
    vector<vector<int>> maxVec(row, vector<int> (col));

    maxVec[row-1][col-1] = mat[row-1][col-1]; // last element will be the same.

    //pre-process last row
    int maxv = mat[row-1][col-1];
    for(int j = col-2; j >= 0; j--){
        if(mat[row-1][j] > maxv){
            maxv = mat[row-1][j];
        }
        maxVec[row-1][j] = maxv;
    }
    //pre-process the last column
    maxv = mat[row-1][col-1];
    for(int i = row-2; i >= 0 ; i--){
        if(mat[i][col-1]> maxv){
            maxv = mat[i][col-1];
        }
        maxVec[i][col-1] = maxv;
    }

    //pre-process the rest of the matrix
    for(int i = row-2; i >= 0; i--){
        for(int j = col-2; j>= 0; j--){
            // Update maxValue
            if(maxVec[i+1][j+1] - mat[i][j] > maxVal){
                maxVal = maxVec[i+1][j+1] - mat[i][j];
            }
            //Update maxVec[i, j]
            maxVec[i][j] = max(mat[i][j], max(maxVec[i][j+1], maxVec[i+1][j]));
        }
    }

    return maxVal;

}

int main() {
    vector<vector<int>> arr = {
            {1,  2,  -1, -4, -20},
            {-8, -3, 4,  2,  1},
            {3,  8,  6,  1,  3},
            {-4, -1, 1,  7,  -6},
            {0,  -4, 10, -5, 1}
    };  //18
    cout<<"Max value: "<<findMaxVal(arr);
    return 0;
}
