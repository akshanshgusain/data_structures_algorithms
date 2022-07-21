//
// Created by Akshansh Gusain on 22/03/21.
//
// we perform cuts on highest cost edge as early as possible
#include<stdc++.h>
using namespace std;

int minimumCostOfBreaking(int X[], int Y[], int m, int n){
    int res =0;

    sort(X,X+m, greater<int>());
    sort(Y,Y+n, greater<int>());

    int hzntl = 1, vert =1; // init current Width as 1
    int i = 0, j = 0; // loop untill one or both cost array are processed

    while(i < m && j < n){
        if(X[i] > Y[j]){
            res += X[i] * vert;

            //increase current horizontal part count by 1
            hzntl++;
            i++;
        }else{
            res += Y[j] * hzntl;
            vert++;
            j++;
        }
    }
    //loop for horizontal array, if remains
    int total =0;
    while(i<m){
        total += X[i++];
    }
    res += total*vert;

    //loop for vertical array, if remains
    total = 0;
    while(j<n){
        total += Y[j++];
    }
    res += total*hzntl;

    return res;
}

int main(){
    int m = 6, n = 4;
    int X[] = {2, 1, 3, 1, 4};
    int Y[] = {4, 1, 2};
    cout << minimumCostOfBreaking(X, Y, m-1, n-1);
    return 0;
}