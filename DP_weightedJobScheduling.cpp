//
// Created by Akshansh Gusain on 03/06/21.
//
#include<stdc++.h>

using namespace std;

struct Job {
    int startTime, endTime, profit;
};

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

bool comparator(Job A1, Job A2) {
    return (A1.endTime < A2.endTime);
}

int findProfit(Job arr[], int n) {
    sort(arr, arr + n, comparator);

    int dp[n];
    dp[0] = arr[0].profit;

    for (int i = 1; i < n; i++) {

        //find profit including the current job
        int inclProf = arr[i].profit;
        int lastJob = binarySearch(arr, i);
        if(lastJob != -1){
            inclProf += dp[lastJob];
        }
        dp[i] = max(inclProf, dp[i-1]);
    }

    return dp[n-1];
}

int main() {
    Job arr[] = {{3, 10,  20},
                 {1, 2,   50},
                 {6, 19,  100},
                 {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findProfit(arr, n);
    return 0;
}
