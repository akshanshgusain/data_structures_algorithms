//
// Created by Akshansh Gusain on 23/03/21.
//
/*
 * we just have to replace the minimum element arr[i] in array by -arr[i] for current operation.
 * In this way we can make sum of array maximum after K operations. Once interesting case is,
 * once minimum element becomes 0, we don’t need to make any more changes.
 */

#include<stdc++.h>
using namespace std;

int maximumSum(int arr[], int n, int k){
    int sum = 0;
    int i = 0;
    sort(arr, arr+n);

    while(k > 0){
        if(arr[i] >=0){
            k=0;
        }else{
            arr[i] = (-1)*arr[i];
            k = k-1;
        }
        i++;
    }
    // Calculating sum
    for(int j = 0; j < n; j++)
    {
        sum += arr[j];
    }
    return sum;
}

int main(){
    int arr[] = { -2, 0, 5, -1, 2 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maximumSum(arr, n, k);
    return 0;
}
