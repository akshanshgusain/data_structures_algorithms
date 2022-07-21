//
// Created by Akshansh Gusain on 01/01/22.
// Could be solved with LIS also O(N^2)


// https://www.youtube.com/watch?v=luzDD2FdCz0
//https://www.geeksforgeeks.org/maximum-sum-pairs-specific-difference/

#include<stdc++.h>
using namespace std;

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K){
    // Sort input array in ascending order.
    sort(arr, arr+N);

    // dp[i] denotes the maximum disjoint pair sum
    // we can achieve using first i elements
    int dp[N];

    //  if no element then dp value will be 0
    dp[0] = 0;

    for (int i = 1; i < N; i++)
    {
        // first give previous value to dp[i] i.e.
        // no pairing with (i-1)th element
        dp[i] = dp[i-1];

        // if current and previous element can form a pair
        if (arr[i] - arr[i-1] < K)
        {
            // update dp[i] by choosing maximum between
            // pairing and not pairing
            if (i >= 2)
                dp[i] = max(dp[i], dp[i-2] + arr[i] + arr[i-1]);
            else
                dp[i] = max(dp[i], arr[i] + arr[i-1]);
        }
    }

    return dp[N - 1];
}

int main(){
    int arr[] = {3, 5, 10, 15, 17, 12, 9};
    int N = sizeof(arr)/sizeof(int);

    int K = 4;
    cout << maxSumPairWithDifferenceLessThanK(arr, N, K);
    return 0;
}