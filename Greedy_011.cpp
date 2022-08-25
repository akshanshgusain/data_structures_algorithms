//
// Created by Akshansh Gusain on 23/08/22.
//

#include<bits/stdc++.h>

using namespace std;


int findMinCostOfBreaking(vector<int> &x, vector<int> &y) {
    sort(x.begin(), x.end(), greater<>());
    sort(y.begin(), y.end(), greater<>());

    int horizontalWidth = 1, verticalWidth = 1;
    int n = x.size(), m = y.size();
    int ans = 0;
    int i = 0, j = 0;

    while (i < n and i < m) {
        if (x[i] > y[j]) {
            ans += x[i] * verticalWidth;
            //  increase current horizontal part count by 1
            horizontalWidth++;
            i++;
        } else {
            ans += y[j] * horizontalWidth;
            //  increase current vertical part count by 1
            verticalWidth++;
            j++;
        }
    }

    // check for the remaining
    int total = 0;
    while(i < n){
        total += x[i];
        i++;
    }
    ans += total * verticalWidth;

    total = 0;
    while(j < m){
        total += y[j];
        j++;
    }
    ans += total * horizontalWidth;

    return ans;
}

int main() {
    vector<int> x = {2, 1, 3, 1, 4};
    vector<int> y = {4, 1, 2};
    cout << findMinCostOfBreaking(x, y);
    return 0;
}