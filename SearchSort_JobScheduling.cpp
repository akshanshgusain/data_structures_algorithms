//
// Created by Akshansh Gusain on 26/02/21.
//
#include<stdc++.h>
using namespace std;
/* Naive Approach*/
//// Function to find the missing element
//int findMissing(int arr[], int left,int right, int diff)
//{
//
//    // Fix left and right boundary
//    // for binary search
//    if (right <= left)
//        return INT_MAX;
//
//    // Find index of middle element
//    int mid = left + (right - left) / 2;
//
//    // Check if the element just after
//    // the middle element is missing
//    if (arr[mid + 1] - arr[mid] != diff)
//        return (arr[mid] + diff);
//
//    // Check if the element just
//    // before mid is missing
//    if (mid > 0
//        && arr[mid] - arr[mid - 1] != diff)
//        return (arr[mid - 1] + diff);
//
//    // Check if the elements till mid
//    // follow the AP, then recur
//    // for right half
//    if (arr[mid] == arr[0] + mid * diff)
//        return findMissing(arr, mid + 1,
//                           right, diff);
//
//    // Else recur for left half
//    return findMissing(arr, left,
//                       mid - 1, diff);
//}
//
//// Function to find the missing
//// element in AP series
//int missingElement(int arr[], int n)
//{
//
//    // Sort the array arr[]
//    sort(arr, arr + n);
//
//    // Calculate Common Difference
//    int diff = (arr[n - 1] - arr[0]) / n;
//
//    // Binary search for the missing
//    return findMissing(arr, 0, n - 1, diff);
//}
//
//int main(){
//    // Given array arr[]
//    int arr[] = { 2, 8, 6, 10 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    // Function Call
//    cout << missingElement(arr, n);
//    return 0;
//}


/* Efficient Approach*/

// Function to get the missing element
int missingElement(int arr[], int n)
{
    // For maximum Element in the array
    int max_ele = arr[0];

    // For minimum Element in the array
    int min_ele = arr[0];

    // For xor of all elements
    int x = 0;

    // Common difference of AP series
    int d;

    // find maximum and minimum element
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_ele)
            max_ele = arr[i];

        if (arr[i] < min_ele)
            min_ele = arr[i];
    }

    // Calculating common difference
    d = (max_ele - min_ele) / n;

    // Calculate the XOR of all elements
    for (int i = 0; i < n; i++) {
        x = x ^ arr[i];
    }

    // Perform XOR with actual AP series
    // resultant x will be the ans
    for (int i = 0; i <= n; i++) {
        x = x ^ (min_ele + (i * d));
    }

    // Return the missing element
    return x;
}

// Driver Code
int main()
{
    // Given array
    int arr[] = { 12, 3, 6, 15, 18 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    int element = missingElement(arr, n);

    // Print the missing element
    cout << element;
}
