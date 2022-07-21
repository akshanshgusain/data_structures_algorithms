//
// Created by Akshansh Gusain on 24/08/21.
//
#include<stdc++.h>
using namespace std;
#define MAX 5


///Time: O((N^2)^4), O(L*X) L = length of the path, X = number of paths


void dfs(int i , int j, string answer, int mat[MAX][MAX],int n, vector<string> &v,vector<vector<int>> &used ){
    if(i<0 or j < 0 or i >=n or j >= n){
        return;
    }
    if(mat[i][j]==0  or used[i][j]==1){
        return;
    }
    if(i == n-1 and j == n-1){
        v.push_back(answer);
        return;
    }

    used[i][j] = 1;

    dfs(i-1, j, answer+'U', mat,n, v, used);
    dfs(i, j+1, answer+'R', mat,n, v, used);
    dfs(i+1, j, answer+'D', mat,n, v, used);
    dfs(i, j-1, answer+'L', mat,n, v, used);

    used[i][j] = 0; //backtrack
}

void findPath(int mat[MAX][MAX], int n, vector<string> &v){
   // v.clear();
   vector<vector<int>> used(MAX, vector<int>(MAX));
   if(mat[0][0] == 0){
       return;
   }
   if(mat[n-1][n-1] == 0){
       return;
   }

   string answer = "";
   dfs(0,0,answer, mat, n,v, used);
   //sort(v.begin(), v.end());
}

int main(){
    int mat[MAX][MAX] = { { 1, 0, 0, 0, 0 },
                          { 1, 1, 1, 1, 1 },
                          { 1, 1, 1, 0, 1 },
                          { 0, 0, 0, 0, 1 },
                          { 0, 0, 0, 0, 1 } };

    int n = sizeof(mat) / sizeof(mat[0]);

    vector<string> v;

    findPath(mat,n, v);
    for( string a : v){
        cout<<a <<" - ";
    }
    return 0;
}
