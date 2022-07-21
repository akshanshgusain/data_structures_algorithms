//
// Created by Akshansh Gusain on 14/07/21.
//

#include<stdc++.h>

using namespace std;

// Basic Approach
// Time: O(N^2), Space: O(1).
//The amount of water to be stored in every element can be found out by finding the heights of bars on the
// left and right sides. The idea is to compute the amount of water that can be stored in every element of
// the array.
// a = max height on the left and b = max height on the right
// min(a,b) – array[i]

int trapWater(vector<int> arr) {
    int n = arr.size();

    int res = 0;

    for (int i = 1; i < n - 1; i++) {

        int maxL = arr[i];
        for (int j = 0; j < i; j++) {
            maxL = max(maxL, arr[j]);
        }

        int maxR = arr[i];
        for (int j = i + 1; j < n; j++) {
            maxR = max(maxR, arr[j]);
        }

        res += min(maxL, maxR) - arr[i];
    }

    return res;
}

//Efficient
// Time: O(N), Space: O(N)

int trapWater2(vector<int> arr) {
    int n = arr.size();
    int res = 0;
    vector<int> heightLeft(n);
    vector<int> heightRight(n);


    heightLeft[0] = arr[0];
    for (int i = 1; i < n; i++) {
        heightLeft[i] = max(heightLeft[i - 1], arr[i]);
    }

    heightRight[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        heightRight[i] = max(heightRight[i + 1], arr[i]);
    }


    for (int i = 0; i < n; i++) {
        res += min(heightLeft[i], heightRight[i]) - arr[i];
    }

    return res;
}

//Efficient
// Time: O(N), Space: O(1)

int trapWater3(vector<int> arr) {

    int n = arr.size();
    // initialize output
    int result = 0;

    // maximum element on left and right
    int left_max = 0, right_max = 0;

    // indices to traverse the array
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        if (arr[lo] < arr[hi]) {
            if (arr[lo] > left_max)
                // update max in left
                left_max = arr[lo];
            else
                // water on curr element = max - curr
                result += left_max - arr[lo];
            lo++;
        } else {
            if (arr[hi] > right_max)
                // update right maximum
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }

    return result;


}


int main() {
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trapWater2(arr);
    return 0;
}