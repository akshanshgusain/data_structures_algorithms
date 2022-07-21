//
// Created by Akshansh Gusain on 04/06/21.
//
#include<stdc++.h>
using namespace std;
#define ROW 4
#define COL 5

int subsum(vector<int> a, int n) {
   int s =0;
   int ma = 1;
    unordered_map<int, int> m;
    for(int i=0; i< n; i++){
        s += a[i];
        if(s==0){
            ma = max(ma, i+1);
        }
        else if(m[s]){
            ma = max(ma, i - m[s]+1);
        }else{
            m[s] = 1;
        }
    }
    return ma;
}

int solve(vector<vector<int>> mat) {
    int ma = INT_MIN;

    for (int i = 0; i < ROW; i++) {

        vector<int> ans(COL);
        for (int j = i; j < ROW; j++) {
            for (int col = 0; col < COL; col++) {
                ans[col] += mat[j][col];
            }
            ma = max(ma, subsum(ans, COL) * (j-i+1));
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