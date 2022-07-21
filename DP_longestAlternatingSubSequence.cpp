//
// Created by Akshansh Gusain on 02/06/21.
//
#include<stdc++.h>
using namespace std;

int lAS(vector<int> arr, int n){
    int dp[n][2];

    for(int i =0; i<n ; i++){
        dp[i][0] = dp[i][1] = 1;
    }

    int result = 1;

    for(int i= 1; i<n; i++){

        for(int j=0; j<i;j++){

            if(arr[j] < arr[i] and dp[i][0]<dp[j][1]+1){
                dp[i][0] = dp[j][1] + 1;
            }

            if(arr[j] > arr[i] and dp[i][1] < dp[j][0] + 1){
                dp[i][1] = dp[j][0]+1;
            }
        }
        if(result < max(dp[i][0], dp[i][1])){
            result = max(dp[i][0], dp[i][1]);
        }
    }
    return result;
}

int main(){
    vector<int> arr = { 1,17,5,10,13,15,10,5,16,8 };
//    vector<int> arr = { 10, 22, 9, 33, 49, 50, 31, 60 };
    int n = arr.size();
    cout<<lAS(arr, n);
}
