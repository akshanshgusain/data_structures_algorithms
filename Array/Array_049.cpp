//
// Created by Akshansh Gusain on 02/08/21.
//


// Clock Wise rotation : Take transpose and reverse the array col-wise
// Anti - Clock Wise rotation : Reverse the array col-wise and Take transpose.

#include<stdc++.h>

using namespace std;

void rotateArray(vector<vector<int>> &mat) {
    int row = mat.size();
    int col = mat[0].size();

    // transpose
    for (int i = 0; i < row; i++) {
        for (int j = i; j < col; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    // row-wise reverse
    for (int i = 0; i < row; i++) {
        int li = 0;
        int ri = col - 1;

        while (li < ri) {
            int temp = mat[i][li];
            mat[i][li] = mat[i][ri];
            mat[i][ri] = temp;
            li++;
            ri--;
        }
    }

}

int main() {
    vector<vector<int>> mat = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16}
    };
    rotateArray(mat);

    for(int i = 0 ; i < mat.size(); i++){
        for(int j = 0; j< mat[0].size(); j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
