//
// Created by Akshansh Gusain on 26/08/22.
//
#include<bits/stdc++.h>

using namespace std;

int findMinAbsDifference(vector<int> &a, vector<int> &b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum = sum + abs(a[i] - b[i]);
    }

    return sum;
}

int main() {
    vector<int> a = {4, 1, 8, 7};
    vector<int> b = {2, 3, 6, 5};
    cout << findMinAbsDifference(a, b);
    return 0;
}