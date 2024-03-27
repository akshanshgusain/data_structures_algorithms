//
// Created by Akshansh Gusain on 26/03/24.
//
#include<bits/stdc++.h>

using namespace std;

//https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/4920125/C%2B%2B-or-0-ms-or-Beats-100-or-O(logn)-or-Step-by-Step-Explanation

// Binary Search


//  We update first_pos to mid because we found the target.
//  Since we're interested in finding the leftmost occurrence, we continue searching in the left subarray
//  To search in the left subarray, we update end to mid - 1 because all elements to the right of mid are greater
//  than or equal to the target.
//  All elements to the left of mid are also less than the target. So, we update start to mid + 1 to search in the right
//  subarray.
//All elements to the right of mid are also greater than the target. So, we update end to mid - 1 to search in the left subarray.

int findFirst(vector<int> &nums, int low, int high, int target) {
    int firstPos = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            firstPos = mid;
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return firstPos;
}

// Binary Search
int findLast(vector<int> &nums, int low, int high, int target) {
    int lastPos = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            lastPos = mid;
            low = mid + 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        };
    }
    return lastPos;
}

// Use Binary Search
int main() {
    vector<int> arr = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int x = 2;
    cout << "First Occurrence of element: " << findFirst(arr, 0, arr.size() - 1, x) << endl;
    cout << "First Occurrence of element: " << findLast(arr, 0, arr.size() - 1, x);
    return 0;
}