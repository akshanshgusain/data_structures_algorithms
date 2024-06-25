//
// Created by Akshansh Gusain on 13/01/22.
//
//https://www.youtube.com/watch?v=4YjEHmw1MX0

// Time: O(N), Space: O(N)
#include<stdc++.h>

using namespace std;

int maxProfit(int arr[], int n) {
    int leastSoFar = INT_MAX;
    int maxProfit = 0;
    int profitIfSoldToday = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < leastSoFar) {
            leastSoFar = arr[i];
        }

        profitIfSoldToday = arr[i] - leastSoFar;
        if (profitIfSoldToday > maxProfit) {
            maxProfit = profitIfSoldToday;
        }
    }

    return maxProfit;
}


int main() {
    int stockPrices[] = {1,2,3};
    int n = sizeof stockPrices / sizeof stockPrices[0];

    cout << maxProfit(stockPrices, n);
    return 0;
}

