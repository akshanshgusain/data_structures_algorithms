//
// Created by Akshansh Gusain on 22/03/21.
//
#include<stdc++.h>
using namespace std;

int findMinimum(int arr[], int n, int k)
{
    int res = 0;
    for (int i = 0; i < n; i++) {
        // Buy current candy
        res += arr[i];

        // And take k candies for free
        // from the last
        n = n - k;
    }
    return res;
}

int findMaximum(int arr[], int n, int k)
{
    int res = 0, index = 0;

    for (int i = n - 1; i >= index; i--)
    {
        // Buy candy with maximum amount
        res += arr[i];

        // And get k candies for free from
        // the starting
        index += k;
    }
    return res;
}

int main(){
    int arr[] = { 3, 2, 1, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    sort(arr, arr + n);

    // Function call
    cout << findMinimum(arr, n, k) << endl << findMaximum(arr, n, k);
    return 0;
}
