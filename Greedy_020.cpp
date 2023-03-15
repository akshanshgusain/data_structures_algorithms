//
// Created by Akshansh Gusain on 26/08/22.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a = {2, 1, 2};
    sort(a.begin(), a.end());
    vector<int> preSum(a.size(), 0);
    int i = 0;
    preSum[0] = a[0];
    for (i = 1; i < a.size(); i++) {
        preSum[i] = preSum[i - 1] + a[i];
    }

    int revSum = a[a.size() - 1], j = a.size() - 1;

    for (i = a.size() - 2; i >= 0; i--) {

        if (revSum > preSum[i]) {
            break;
        }

        revSum += a[i];
    }

    cout << a.size() - 1 - i;
    return 0;
}
