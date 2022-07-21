//
// Created by Akshansh Gusain on 01/01/22.
//https://www.youtube.com/watch?v=RElcqtFYTm0    // 13:00
//https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
#include<stdc++.h>
using namespace std;

int maxSquare(vector<vector<int>> &arr){
    int rows = arr.size();
    int cols = arr[0].size();

    if(rows == 0){
        return 0;
    }

    vector<vector<int>> T(rows+1, vector<int>(cols+1,0));

    int largest = 0;

    //Let the given binary matrix be M[R][C]. The idea of the algorithm is to construct an auxiliary
    //size matrix S[][] in which each entry S[i][j] represents the size of the square sub-matrix with
    //all 1s including M[i][j] where M[i][j] is the rightmost and bottom-most entry in sub-matrix.
    for(int i =1; i <= rows; i++){
        for(int j = 1; j <= cols; j++){
            if(arr[i-1][j-1] == 1){
                // We need to make sure that there are no adj. 0's to add current index to form a largest square
                // matrix
                T[i][j] = 1 + min( T[i-1][j], min(T[i-1][j-1], T[i][j-1]));
                if(largest < T[i][j]){
                    largest = T[i][j];
                }
            }
        }
    }
    return largest * largest;
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

