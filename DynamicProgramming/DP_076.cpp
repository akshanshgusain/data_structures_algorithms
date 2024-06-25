//
// Created by Akshansh Gusain on 04/01/22.
//
#include<stdc++.h>

using namespace std;

///Memoized version - Time: O(N^2), space: O(N^2)

//#define MAX 100
//int dp[MAX][MAX];
//
//// function to check all possible combinations
//// of removal and return the minimum one
//int countRemovals(int a[], int i, int j, int k) {
//    // base case when all elements are removed
//    if (i >= j)
//        return 0;
//
//        // if condition is satisfied, no more
//        // removals are required
//    else if ((a[j] - a[i]) <= k)
//        return 0;
//
//        // if the state has already been visited
//    else if (dp[i][j] != -1)
//        return dp[i][j];
//
//        // when Amax-Amin>d
//    else if ((a[j] - a[i]) > k) {
//
//        // minimum is taken of the removal
//        // of minimum element or removal
//        // of the maximum element
//        dp[i][j] = 1 + min(countRemovals(a, i + 1, j, k),
//                           countRemovals(a, i, j - 1, k));
//    }
//    return dp[i][j];
//}
//
//// To sort the array and return the answer
//int removals(int a[], int n, int k) {
//    // sort the array
//    sort(a, a + n);
//
//    // fill all stated with -1
//    // when only one element
//    memset(dp, -1, sizeof(dp));
//    if (n == 1)
//        return 0;
//    else
//        return countRemovals(a, 0, n - 1, k);
//}
//
//// Driver Code
//int main() {
//    int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
//    int n = sizeof(a) / sizeof(a[0]);
//    int k = 4;
//    cout << removals(a, n, k);
//    return 0;
//}

/* The solution could be further optimized. The idea is to sort the array in increasing order and traverse
 * through all the elements (let’s say index i) and find the maximum element on its right (index j) such
 * that arr[j] – arr[i] <= k. Thus, the number of elements to be removed becomes n-(j-i+1). The minimum
 * number of elements can be found by taking the minimum of n-(j-i-1) overall i. The value of index j can
 * be found through a binary search between start = i+1 and end = n-1;*/
// Function to find
// rightmost index
// which satisfies the condition
// arr[j] - arr[i] <= k


// Tabulation:  Time Complexity :O(NlogN) , Auxiliary Space: O(n)
int findInd(int key, int i,
            int n, int k, int arr[]) {
    int start, end, mid, ind = -1;

    // Initialising start to i + 1
    start = i + 1;

    // Initialising end to n - 1
    end = n - 1;

    // Binary search implementation
    // to find the rightmost element
    // that satisfy the condition
    while (start < end) {
        mid = start + (end - start) / 2;

        // Check if the condition satisfies
        if (arr[mid] - key <= k) {

            // Store the position
            ind = mid;

            // Make start = mid + 1
            start = mid + 1;
        } else {
            // Make end = mid
            end = mid;
        }
    }

    // Return the rightmost position
    return ind;
}

// Function to calculate
// minimum number of elements
// to be removed
int removals(int arr[], int n, int k) {
    int i, j, ans = n - 1;

    // Sort the given array
    sort(arr, arr + n);

    // Iterate from 0 to n-1
    for (i = 0; i < n; i++) {

        // Find j such that
        // arr[j] - arr[i] <= k
        j = findInd(arr[i], i, n, k, arr);

        // If there exist such j
        // that satisfies the condition
        if (j != -1) {
            // Number of elements
            // to be removed for this
            // particular case is
            // (j - i + 1)
            ans = min(ans, n - (j - i + 1));
        }
    }

    // Return answer
    return ans;
}

int main() {
    int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}
