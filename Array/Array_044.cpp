//
// Created by Akshansh Gusain on 02/08/21.
//
#include<stdc++.h>

using namespace std;

// time: O(m+n), space: O(1)

int rowWithMax1s(vector<vector<int>> &mat) {
    int j, max_row_index = 0;
    j = mat[0].size() - 1; // last column

    for (int i = 0; i < mat.size(); i++) {
        bool flag = false;

        while (j >= 0 and mat[i][j] == 1) {
            j = j - 1;
            flag = true;
        }

        if (flag) {
            max_row_index = j;
        }

        if (max_row_index == 0 and mat[0][mat[0].size() - 1] == 0) {
            return -1;
        }
        return max_row_index;
    }
}

int main() {
    vector<vector<int>> mat = {{0, 0, 0, 1},
                               {0, 1, 1, 1},
                               {1, 1, 1, 1},
                               {0, 0, 0, 0}};
    cout << "Row with max ones: " <<rowWithMax1s(mat)+1<<"th row.";
    return 0;
}
