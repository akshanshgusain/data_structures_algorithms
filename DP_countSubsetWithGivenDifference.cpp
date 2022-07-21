//
// Created by Akshansh Gusain on 18/05/21.
//
#include<stdc++.h>
using namespace std;

int countSubsetSum(int arr[], int sum, int n) {
    int dp[n + 1][sum + 1];
    int i, j;


    for (j = 0; j <= sum; j++) {
        dp[0][j] = 0;
    }

    for (i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= sum; j++) {
            if (arr[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            }
        }
    }

    return dp[n][sum];
}

int main(){
    //int arr[] = {1, 5, 3, 7, 4};
    int arr[] = {1,1,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    /* sum (S1) = (diff + sum(Array) )/2*/
    int sum = 0;
    int diff = 1;
    for(int i=0; i<n; i++ ) sum+=arr[i];
    if((diff + sum)%2 != 0)
    {
        cout<<"No Solution";
        return 0;
    }
    int sum_s1 = (diff + sum)/2;
    cout<<"sum: "<<sum_s1<<endl;
    cout<<countSubsetSum(arr, sum_s1, n);

    return 0;
}

