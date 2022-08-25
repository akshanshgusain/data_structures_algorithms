//
// Created by Akshansh Gusain on 25/08/22.
//

#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int k) {
    sort(a.begin(), a.end());
    int sum = 0;
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        if(j <= k and a[i] < 0){
          sum += -a[j];
          j++;
        }
        if(a[i] >= 0){
            sum += a[i];
        }
    }
    return sum;
}

int main() {
    vector<int> a = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20};
    int k = 5;
    cout << solve(a, k);
    return 0;
}