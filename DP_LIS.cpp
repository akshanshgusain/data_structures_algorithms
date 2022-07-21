//
// Created by Akshansh Gusain on 01/06/21.
//
#include<stdc++.h>
using namespace std;

int longestSubSequence(int a[], int n){
    int dp[n];
    for(int i = 0; i < n; i++)
        dp[i] = 1;


    for(int i = 1; i < n; i++){
        for(int j=0; j<i;j++){
            if(a[j]< a[i]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }

    int maxi = INT_MIN;
    for(int i=0;i <n; i++){
        //cout<< dp[i]<<endl;
       maxi = max(maxi, dp[i]);
    }
    return maxi;
}
int main(){
    //int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int arr[] = {10, 9, 4, 5, 4, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Length of lis is: "<<endl<<longestSubSequence(arr, n);
    return 0;
}