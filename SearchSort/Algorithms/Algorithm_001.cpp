//
// Created by Akshansh Gusain on 26/03/24.
//
#include<bits/stdc++.h>

using namespace std;

// time: O(logN), space: O(1)
int binarySearchItr(const vector<int> &arr, int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (key > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// time: O(logN), space: O(logN)
int binarySearchRec(const vector<int> &arr, int low, int high, int key) {
    if (high >= low) {
        int mid = (low + (high - low)) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (key > arr[mid]) {
            return binarySearchRec(arr, mid + 1, high, key);
        } else {
            return binarySearchRec(arr, low, mid - 1, key);
        }
    }
    return -1;
}
