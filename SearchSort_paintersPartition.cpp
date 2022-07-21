//
// Created by Akshansh Gusain on 01/03/21.
//
#include<stdc++.h>
using namespace std;

// There are two approaches to solve this solution
// 1. using Binary Search same as "Book Allocation Problem"
//2. using Dynamic programing

int main(){

    int arr[] = { 10, 20, 60, 50, 30, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << partition(arr, n, k) << endl;

    return 0;
}
