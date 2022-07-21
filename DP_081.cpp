//
// Created by Akshansh Gusain on 06/01/22.
//
//https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/

// Time: O(NlogN), Space: O(N)

#include<stdc++.h>
using namespace std;

struct Job {
    int startTime, endTime, profit;
};

// A utility function that is used for sorting events
// according to finish time
bool comparator(Job A1, Job A2) {
    return (A1.endTime < A2.endTime);
}
// A Binary Search based function to find the latest job
// (before current job) that doesn't conflict with current
// job.  "index" is index of the current job.  This function
// returns -1 if all jobs before index conflict with it.
// The array jobs[] is sorted in increasing order of finish
// time.
int binarySearch(Job jobs[], int index) {
    // Initialize 'lo' and 'hi' for Binary Search
    int lo = 0, hi = index - 1;

    // Perform binary Search iteratively
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (jobs[mid].endTime <= jobs[index].startTime) {
            if (jobs[mid + 1].endTime <= jobs[index].startTime)
                lo = mid + 1;
            else
                return mid;
        } else
            hi = mid - 1;
    }

    return -1;
}

int findMaxProfit(Job arr[], int n) {
    // Sort jobs according to finish time
    sort(arr, arr + n, comparator);

    // T[i] stores the profit for jobs till arr[i] (including arr[i])
    int T[n];
    T[0] = arr[0].profit;

    for(int i =1; i < n; i++){

        // Find profit including the current JOB
        int inclProfit = arr[i].profit;
        int latestJob = binarySearch(arr, i);
        if(latestJob != -1){
            inclProfit += T[latestJob];
        }
        T[i] = max(inclProfit, T[i-1]);
    }
    return T[n-1];
}

int main() {
    Job arr[] = {{3, 10,  20},
                 {1, 2,   50},
                 {6, 19,  100},
                 {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findMaxProfit(arr, n);
    return 0;
}