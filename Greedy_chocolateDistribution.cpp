//
// Created by Akshansh Gusain on 26/03/21.
//
#include<stdc++.h>
using namespace std;

int findMinDiff(int arr[], int n, int m){
    if(m==0 or n ==0)
        return 0;
    sort(arr,arr+n);

    if(n<m)
        return -1;

    int min_diff = INT_MAX;

    for(int i=0; i<n; i++){
        int difference  = arr[m+i-1] - arr[i];
        if(difference < min_diff){
            min_diff = difference;
        }
    }
    return min_diff;
}

int main(){
    int arr[] = { 12, 4,  7,  9,  2,  23, 25, 41, 30,
                  40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "<< findMinDiff(arr, n, m);
    return 0;
}
