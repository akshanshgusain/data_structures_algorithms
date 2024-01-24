//
// Created by Akshansh Gusain on 23/01/24.
//
#include<bits/stdc++.h>
using namespace std;


/// Counting Sort is a non-comparison-based sorting algorithm

/*
Counting Sort is a sorting algorithm that operates by counting the number of occurrences of each element in the
input array. It assumes that the input consists of integers within a specific range. The algorithm works particularly
well when the range of input values is not significantly larger than the number of elements in the input array.
*/

// Time: O(N+M), where N and M are the size of inputArray[] and countArray[]
// Space: O(N+M), where N and M are the space taken by outputArray[] and countArray[]

vector<int> countSort(vector<int> &ip) {
    int maxi = INT16_MIN;
    for (auto it: ip) {
        maxi = max(maxi, it);
    }
    // This array will be used for storing the occurrences of the elements of the input array
    vector<int> countArray(maxi + 1, 0);

    // Mapping each element of inputArray[] as an index
    // of countArray[] array
    for(int ele : ip){
        countArray[ele] ++;
    }

    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= maxi; i++){
        countArray[i] += countArray[i - 1];
    }

    // Creating outputArray[] from countArray[] array
    vector<int> outputArray(ip.size());

    for (auto it: ip){
        outputArray[countArray[it] - 1] = it;
        countArray[it]--;
    }

    return outputArray;

}

int main() {
    vector<int> ip = {2, 5, 3, 0, 2, 3, 0, 3};
    vector<int> op = countSort(ip);

    for (auto it: op) {
        cout << it << " ";
    }
    return 0;
}