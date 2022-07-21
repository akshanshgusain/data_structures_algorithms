//
// Created by Akshansh Gusain on 22/12/21.
//https://www.youtube.com/watch?v=UogHvfQ3e18&t=709s

#include<stdc++.h>
using namespace std;


// dp[i][0] stores the value when i is greater than previous element
// dp[i][1] stores the value when i is lesser than previous element

int lAS(int *arr, int n){
    int T[2][n];
    for(int i =0; i < n; i++){
        T[0][i] = T[1][i] = 1;
    }

    int result =1;
    for(int i =1;i < n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                T[0][i] = max(T[0][i], 1+ T[1][j]);
            }else{
                T[1][i] = max(T[1][i], 1+ T[0][j]);
            }
        }
        if(result < max(T[1][i], T[0][i])){
            result = max(T[1][i], T[0][i]);
        }
    }

    return result;
}

int main(){
   int arr []= { 1,17,5,10,13,15,10,5,16,8 };
//    vector<int> arr = { 10, 22, 9, 33, 49, 50, 31, 60 };
    int n = sizeof arr/sizeof arr[0];
    cout<<lAS(arr, n);
    return 0;
}