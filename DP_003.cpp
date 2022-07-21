//
// Created by Akshansh Gusain on 26/10/21.
//

#include<stdc++.h>
using namespace std;
int t[100][100];

int knapsack(int val[], int wt[], int W, int n){
    if(n== 0 or W ==0){
        return 0;
    }

    if( t[n][W] != -1){
        return t[n][W];
    }
    if(wt[n-1] < W){
        return  t[n][W] = max(val[n-1] + knapsack(val, wt, W - wt[n-1], n-1),
                   knapsack(val ,wt, W, n-1));
    }else{
        return t[n][W] = knapsack(val ,wt, W, n-1);
    }
}

int main(){
    memset(t, -1, sizeof(t));
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(val, wt, W, n); //180
    return 0;
}