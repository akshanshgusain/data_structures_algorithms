//
// Created by Akshansh Gusain on 28/10/21.
//
#include<stdc++.h>

using namespace std;

int findMin(const int arr[], int n) {

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    bool t[n + 1][sum + 1];

    for (int i = 0; i <= n; i++) {
        t[i][0] = true;
    }

    for (int i = 1; i <= sum; i++) {
        t[0][i] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If ith element is included in the subset sum
            if( arr[i-1] > j ){
                t[i][j] = t[i - 1][j];
            }else{
                t[i][j] = t[i-1][j] || t[i - 1][j - arr[i - 1]];
            }
//            t[i][j] = t[i - 1][j];
//
//            if (arr[i - 1] <= j) {
//                t[i][j] = t[i][j] or t[i - 1][j - arr[i - 1]];
//            }
        }
    }

    int mn = INT_MAX;
    for (int j = 0; j <= sum / 2; j++) {
        if (t[n][j]) {
            mn = min(mn, sum - 2 * j);
            cout << mn << " ";
        }
    }
    cout << endl;
    return mn;
}

int main() {
    //int arr[] = {3, 1, 4, 2, 2, 1};
    int arr[] = {1, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between 2 sets is "
         << endl << findMin(arr, n) << endl;
    return 0;
}
