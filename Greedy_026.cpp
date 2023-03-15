//
// Created by Akshansh Gusain on 13/09/22.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    priority_queue<int ,vector<int>, greater<>> ropes;

    for (int i = 0; i < n; i++) {
        cin >> k;
        ropes.push(k);
    }

    int result = 0;
    while (ropes.size() != 1) {
        int f = ropes.top();
        ropes.pop();
        int s = ropes.top();
        ropes.pop();
        result += f + s;
        ropes.push(f + s);
        //cout << f << " ";
    }

    cout << result;
    return 0;
}