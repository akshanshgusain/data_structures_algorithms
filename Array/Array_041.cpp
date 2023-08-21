//
// Created by Akshansh Gusain on 28/07/21.
//
#include<stdc++.h>

using namespace std;

// Draw the path that the spiral makes. We know that the path should turn clockwise whenever it
// would go out of bounds or into a cell that was previously visited.

void spiralOrder(vector<vector<int>> &A) {
    // dir = 0 : Go left
    // dir = 1 : Go Down
    // dir = 2 : Go Right
    // dir = 3 : Go Top
    int T = 0, B = A.size() - 1, L = 0, R = A[0].size() - 1, dir = 0;

    int i;
    vector<int> ans;

    while (T <= B and L <= R) {

        if (dir == 0) {
            for (i = L; i <= R; i++) {
                ans.push_back(A[T][i]);
            }
            T++;
        } else if (dir == 1) {
            for (i = T; i <= B; i++) {
                ans.push_back(A[i][R]);
            }
            R--;
        } else if (dir == 2) {
            for (i = R; i >= L; i--) {
                ans.push_back(A[B][i]);
            }
            B--;
        } else if (dir == 3) {
            for (i = B; i >= T; i--) {
                ans.push_back(A[i][L]);
            }
            L++;
        }
        dir = (dir + 1) % 4;
    }

    for (i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

}

int main() {
    vector<vector<int>> A = {{1,  2,  3,  4,  5,  6},
                             {7,  8,  9,  10, 11, 12},
                             {13, 14, 15, 16, 17, 18}};

    spiralOrder(A);
    return 0;
}