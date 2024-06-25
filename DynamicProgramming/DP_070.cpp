//
// Created by Akshansh Gusain on 01/01/22.
//
#include<stdc++.h>

using namespace std;

int maxSum(vector<int> &ip) {
    int n = ip.size();
    //Stores result for subarray arr[0..i], i.e., maximum possible sum in subarray arr[0..i]
    //such that no three elements are consecutive.
    int T[n];

    // Process the base cases
    T[0] = ip[0];
    T[1] = ip[0] + ip[1];
    T[2] = max(max(ip[0] + ip[2], ip[1] + ip[2]), T[1]);

    for (int i = 3; i < n; i++) {
        T[i] = max(max(T[i - 1], T[i - 2] + ip[i]), ip[i] + ip[i - 1] + T[i - 3]);
    }

    return T[n-1];
}

int main() {
    vector<int> ip = {100, 1000, 100, 1000, 1}; //2101
    cout << maxSum(ip);
    return 0;
}
