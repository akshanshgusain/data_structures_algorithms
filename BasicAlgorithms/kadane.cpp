//
// Created by Akshansh Gusain on 25/06/24.
//
#include<bits/stdc++.h>

using namespace std;

/// Kadane's algorithm is a well-known algorithm for finding the maximum sum subarray in a given one-dimensional array
/// of numbers. It operates in linear time, O(n), and is famous for its efficiency and simplicity.

int kadane(vector<int> &arr) {
    int maxEndingHere = 0, maxSoFar = -1e9;

    for (int i = 0; i < arr.size(); i++) {
        maxEndingHere = maxEndingHere + arr[i];

        if (maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
        }
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
        }
    }

    return maxSoFar;
}

tuple<int, int, int> kadaneWithIndex(vector<int> &nums) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    int start = 0, end = 0;

    for (int i = 0; i < nums.size(); i++) {
        max_ending_here += nums[i];

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            end = i;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
            start = i + 1;  // Update the starting index for the next subarray
        }
    }

    return {max_so_far, start, end};
}


int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums2 = {4, -1, 2, 1, -5, 4, -2, 6, -1};;

    auto [max_sum, start, end] = kadaneWithIndex(nums2);

    cout << "Maximum Subarray Sum is " << max_sum << endl;
    cout << "Start Index: " << start << endl;
    cout << "End Index: " << end << endl;
    return 0;
}