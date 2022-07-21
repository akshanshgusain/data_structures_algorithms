//
// Created by Akshansh Gusain on 25/03/21.
//
/*Given an array of non-negative integers. Our task is to find minimum number of elements such that their sum
 * should be greater than the sum of rest of the elements of the array.*/


/*
 * The Efficient Approach is to take the largest elements. We sort values in descending order, then take elements
 * from the largest, until we get strictly more than half of total sum of the given array.
 * */

#include<stdc++.h>
using namespace std;

int minElements(int arr[], int n){
    // calculating HALF of array sum
    int halfSum = 0;
    for (int i = 0; i < n; i++)
        halfSum = halfSum + arr[i];
    halfSum = halfSum / 2;

    // sort the array in descending order.
    sort(arr, arr + n, greater<>());

    int res = 0, curr_sum = 0;
    for (int i = 0; i < n; i++) {

        curr_sum += arr[i];
        res++;

        // current sum greater than sum
        if (curr_sum > halfSum)
            return res;
    }
    return res;
}

int main(){
    int arr[] = {3, 1, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minElements(arr, n) << endl;
    return 0;
}

