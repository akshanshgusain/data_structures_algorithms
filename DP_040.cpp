//
// Created by Akshansh Gusain on 22/12/21.
//

#include<stdc++.h>

using namespace std;

int maxChainLen(vector<pair<int, int>> p, int n) {
    int T[n];
    /*1) Sort given pairs in increasing order of first (or smaller) element. Why do not need sorting? Consider the
     * example {{6, 8}, {3, 4}} to understand the need of sorting. If we proceed to second step without sorting, we get
     * output as 1. But the correct output is 2.*/
    //sort based on first element

    sort(p.begin(), p.end());

    int i, j;

    for (i = 0; i < n; i++) {
        T[i] = 1;
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (p[j].second < p[i].first) {
                T[i] = max(T[i], T[j] + 1);
            }
        }
    }

    int ma = INT_MIN;
    for (int i = 0; i < n; i++) {
        ma = max(ma, T[i]);
    }
    return ma;
}

int main() {
    vector<pair<int, int>> arr = {make_pair(5, 24), make_pair(39, 60), make_pair(15, 28), make_pair(27, 40),
                                  make_pair(50, 90)};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxChainLen(arr, 5);
    return 0;
}