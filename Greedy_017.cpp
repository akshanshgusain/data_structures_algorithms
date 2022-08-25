//
// Created by Akshansh Gusain on 25/08/22.
//
#include<bits/stdc++.h>

using namespace std;

int asbMaxDifference(vector<int> &a) {
    sort(a.begin(), a.end());
    vector<int> finalSequence;

    for (int i = 0; i < a.size() / 2; i++) {
        finalSequence.emplace_back(a[i]);
        finalSequence.emplace_back(a[a.size() - 1 - i]);
    }

    // If there are odd elements, push the
    // middle element at the end.
    if (a.size() % 2 != 0) {
        finalSequence.push_back(a[a.size() / 2]);
    }

    // In this loop absolute difference of elements for the final sequence is calculated.
    int maximumSum = 0;

    for (int i = 0; i < a.size() - 1; ++i) {
        maximumSum = maximumSum + abs(finalSequence[i] - finalSequence[i + 1]);
    }

    // absolute difference of last element
    // and 1st element
    maximumSum += abs(finalSequence[a.size() - 1] - finalSequence[0]);

    return maximumSum;
}

int main() {
    vector<int> a = {1, 2, 4, 8};
    cout << asbMaxDifference(a);
    return 0;
}