//
// Created by Akshansh Gusain on 16/03/24.
//

//https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/
// Given an array and a positive integer k, find the first negative integer for each
// window(contiguous subarray) of size
// k. If a window does not contain a negative integer, then print 0 for that window.

#include<stdc++.h>

using namespace std;

void printFirstNegativeInteger(vector<int> &arr, int k) {
    deque<int> Di;
    int n = arr.size();

    //Process first k elements
    int i;
    for (i = 0; i < k; i++) {
        if (arr[i] < 0) {
            Di.push_back(i);
        }
    }

    //process rest of the elements
    for (; i < n; i++) {
        // if Di is not empty then the element at the
        // front of the queue is the first negative integer
        // of the previous window
        if (!Di.empty())
            cout << arr[Di.front()] << " ";

            // else the window does not have a
            // negative integer
        else
            cout << "0" << " ";


        // Remove the elements which are out of this window
        while ((!Di.empty()) && Di.front() < (i - k + 1)){
            Di.pop_front();  // Remove from front of queue
        }


        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
            Di.push_back(i);

    }
    if (!Di.empty())
        cout << arr[Di.front()] << " ";
    else
        cout << "0" << " ";
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    printFirstNegativeInteger(arr, k);
    return 0;
}