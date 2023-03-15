//
// Created by Akshansh Gusain on 26/08/22.
//
#include<bits/stdc++.h>

using namespace std;

int distributeChocolates(vector<int> &a, int m) {
    sort(a.begin(), a.end());
    int minDiff = INT_MAX;
    for (int i = 0; i < a.size() - m + 1; i++) {
        cout << "i = " << i << "; a[i+m] " << a[i + m - 1] << " - a[i] " << a[i] << endl;
        minDiff = min(minDiff, a[i + m - 1] - a[i]);
    }

    return minDiff;
}

int main() {
    vector<int> a = {3, 4, 1, 9, 56, 7, 9, 12};
    int m = 5;
    cout << distributeChocolates(a, m);
    return 0;
}