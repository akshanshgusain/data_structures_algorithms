//
// Created by Akshansh Gusain on 30/07/21.
// https://www.youtube.com/watch?v=ZYpYur0znng

#include<stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
int searchMat(vector<vector<int>> mat, int ele){
    int n = mat.size();
    int i=0, j=0;
    while(i < n and j >= 0){
        if(mat[i][j] == ele){
            cout<<" Found "<<ele<<", at: "<<i<<" ,"<<j<<endl;
            return 1;
        }
        if(mat[i][j] > ele){
            j--;
        }else{
            i++;
        }
    }
}

// https://leetcode.com/problems/search-a-2d-matrix/

bool searchMat2(vector<vector<int>>& mat, int ele){
    if(!mat.size()) return false;

    int n = mat.size();
    int m = mat[0].size();

    int lo = 0;
    int hi = (n*m) - 1;

    while(lo <= hi){
        int mid = (lo + (hi-lo))/2;

        if(mat[mid/m][mid%m] == ele){
            return true;
        }
        if(mat[mid/m][mid%m] < ele){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    return false;
}

int main(){

    return 0;
}