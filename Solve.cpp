//
// Created by Akshansh Gusain on 10/03/21.
//
#include<stdc++.h>

using namespace std;

int maxProduct(int index, vector<int> arr, int prod) {
    if (index >= arr.size()) {
        return 1;
    }

    int l = arr[index] * maxProduct(index + 1, arr, prod * arr[index]);
    int r = arr[index];

    if (prod < max(l, r)) {
        prod = max(l, r);
    }
    return prod;
}


int main() {
    vector<int> arr = {6, -3, -10, 0, 2}; // 180  // The subarray is {6, -3, -10}
    vector<int> arr2 = {-1, -3, -10, 0, 60}; // 60  // The subarray is {60}
    vector<int> arr3 = {-2, -40, 0, -2, -3}; // 80  // The subarray is {-2, -40}

    cout << maxProduct(0, arr3, 1);
    return 0;
}
