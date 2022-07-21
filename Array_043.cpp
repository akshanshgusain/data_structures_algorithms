//
// Created by Akshansh Gusain on 30/07/21.
//
#include<stdc++.h>

using namespace std;

int countSmallerThanMid(vector<int> &row, int mid) {
    int l = 0, h = row.size() - 1;
    while (l <= h) {
        int mi = (l + h) >> 1;

        if (row[mi] <= mid) {
            l = mi + 1;
        } else {
            h = mi - 1;
        }
    }
    return l;
}

int findMedian(vector<vector<int>> &A) {
    int lo = 1, hi = 1e9, n = A.size(), m = A[0].size();

    while (lo <= hi) {

        int mid = (lo + hi) >> 1;
        int count = 0; // number <= mid

        for (int i = 0; i < n; i++) {
            count += countSmallerThanMid(A[i], mid);
        }

        if (count <= (n * m) / 2) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return lo;
}

int main() {
    vector<vector<int>> arr = {{1, 3, 6},
                               {2, 6, 9},
                               {3, 6, 9}};

    cout<<findMedian(arr)<<endl;
    return 0;
}