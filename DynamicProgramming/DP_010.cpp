//
// Created by Akshansh Gusain on 01/11/21.
//

#include<stdc++.h>

using namespace std;
int t[100][100];

int countSubsetSum(int arr[], int sum, int n){
    if(n == 0 and sum!= 0){
        return 0;
    }
    if(sum == 0){
        return 1;
    }

    if(t[n-1][sum] != -1){
        return t[n-1][sum];
    }

    if(arr[n-1] > sum){
        return t[n-1][sum] = countSubsetSum(arr, sum, n-1);
    }else{
        return t[n-1][sum] = (countSubsetSum(arr,sum, n-1) + countSubsetSum(arr, sum - arr[n-1], n-1));
    }
}

int main() {
    memset(t, -1, sizeof(t));
    int arr[] = {1, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int diff = 1;
    int sum = 0;

    for(int i =0 ; i < n; i++){
        sum += arr[i];
    }
    int s = (diff+sum)/2;
    cout<<"s = "<<s<<endl;
    cout << countSubsetSum(arr,s, n);

    return 0;
}