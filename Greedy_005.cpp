//
// Created by Akshansh Gusain on 20/08/22.
//
#include<bits/stdc++.h>

using namespace std;

const vector<int> den = {1, 2, 5, 10, 20, 50, 100, 500, 1000};


int findDenominations(int &v) {
    vector<int> ans;
    int cnt;

    for (int i = den.size() - 1; i >= 0; i--) {


        if (den[i] <= v) {
            cnt = v / den[i];
            for (int j = 0; j < cnt; j++) {
                ans.push_back(den[i]);
            }
            v -= cnt * den[i];

        }
    }

    for (auto it: ans) {
        cout << it << " ";
    }
    cout<<endl;
    return ans.size();
}


int main() {
    int v = 124;
    cout << findDenominations(v);
    return 0;
}