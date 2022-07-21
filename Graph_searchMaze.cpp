//
// Created by Akshansh Gusain on 11/04/21.
//
//A variation of Rat in a Maze.

#include<stdc++.h>
using namespace std;
vector<string> v;
#define MAX 5

/// Time: O((N^2)^4), O(L*X) L = length of the path, X = number of paths

void dfs(int i, int j, string s, int m[MAX][MAX], int n, vector<vector<int>> &vis){
    if(i<0 or j<0 or i>=n or j>= n){
        return;
    }
    if(m[i][j] == 0 or vis[i][j] == 1){
        return;
    }
    if(i == n-1 and j == n-1){
        v.push_back(s);
        return;
    }
    vis[i][j] = 1;

    dfs(i-1, j, s +'U', m,n,vis);
    dfs(i+1, j, s +'D', m,n,vis);
    dfs(i, j-1, s +'L', m,n,vis);
    dfs(i, j+1, s +'R', m,n,vis);

    vis[i][j] =0;
}

vector<string> findPath(int m[MAX][MAX], int n){
    v.clear();
    vector<vector<int>> vis(MAX, vector<int>(MAX));
    if(m[0][0] == 0){
        return v;
    }
    if(m[n-1][n-1] == 0){
        return v;
    }
    string s ="";
    dfs(0,0,s,m,n,vis);
    sort(v.begin(), v.end());
    return v;
}
int main(){
    int m[MAX][MAX] = { { 1, 0, 0, 0, 0 },
                        { 1, 1, 1, 1, 1 },
                        { 1, 1, 1, 0, 1 },
                        { 0, 0, 0, 0, 1 },
                        { 0, 0, 0, 0, 1 } };
    int n = sizeof(m) / sizeof(m[0]);
    findPath(m,n);
    for( string a : v){
        cout<<a <<" - ";
    }
    return 0;
}
