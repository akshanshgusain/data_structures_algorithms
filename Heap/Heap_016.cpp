//
// Created by Akshansh Gusain on 02/04/24.
//

#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define all(p) p.begin(), p.end()

using namespace std;

int solve(vector<int> &arr) {

    int n = arr.size();

    priority_queue<int, vector<int>, greater<>> queue; // min queue

    for (auto it: arr) {
        queue.push(it);
    }

    int a = 0, b = 0;

    for (int i = 0; i < n; i++) {
        int top = queue.top();
        queue.pop();

        if (i % 2 == 0) {
            a = a * 10 + top;
        } else {
            b = b * 10 + top;
        }
    }

    return a + b;
}

int32_t main() {

    vector<int> arr = {6, 8, 4, 5, 2, 3}; //604
    cout << "Sum is " << solve(arr);

    return 0;
}
