//
// Created by Akshansh Gusain on 25/06/24.
//
#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1e9;
}

int main() {

    return 0;
}