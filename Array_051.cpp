//
// Created by Akshansh Gusain on 02/08/21.
//
#include<stdc++.h>

using namespace std;


// Time: O(MN), Space: O(N)

void printCommonElements(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    unordered_map<int, int> mp;
    // initialize 1st row elements with value 1
    for (int j = 0; j < m; j++)
        mp[mat[0][j]] = 1;

    // traverse the matrix
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // If element is present in the map and
            // is not duplicated in current row.

            if (mp[mat[i][j]] == i) {
                // we increment count of the element
                // in map by 1
                mp[mat[i][j]] = i + 1;

                // If this is last row (check and print)
                if (i == n - 1 && mp[mat[i][j]] == n)
                    cout << mat[i][j] << " ";
            }
        }
    }

}

int main() {
    vector<vector<int>> mat = {
            {1, 2, 1, 4, 8},
            {3, 7, 8, 5, 1},
            {8, 7, 7, 3, 1},
            {8, 1, 2, 7, 9},
    };

    printCommonElements(mat);
    return 0;
}
