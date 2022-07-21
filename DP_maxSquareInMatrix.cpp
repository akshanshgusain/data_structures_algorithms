//
// Created by Akshansh Gusain on 01/06/21.
//
#include<stdc++.h>
using namespace std;

int maxSquare(vector<vector<int>>& matrix){

    int rows = matrix.size();
    if(rows == 0)
        return 0;
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows +1, vector<int>(cols + 1, 0));
    int largest = 0;

    for(int i=1; i <= rows; i++){
        for(int j=1; j<=cols; j++){
            if(matrix[i-1][j-1] == 1){
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                if(largest < dp[i][j]){
                    largest = dp[i][j];
                }
            }
        }
    }
    return largest*largest;
}

int main(){
    vector<vector<int>> arr = {{0,1,1,0,1},
                               {1,1,0,1,0},
                               {0,1,1,1,0},
                               {1,1,1,1,0},
                               {1,1,1,1,1},
                               {0,0,0,0,0}};
    cout<<maxSquare(arr);
    return 0;
}
