//
// Created by Akshansh Gusain on 05/02/23.
//
#include<bits/stdc++.h>

using namespace std;

void findMaxSum(vector<int> &ip) {
    int maxTH = 0;
    int maxi = INT_MIN;
    int start = 0, end = 0;
    for (int i = 0; i < ip.size(); i++) {
        maxTH += ip[i];
        if (maxi < maxTH) {
            maxi = maxTH;
            end = i;
        }

        if (maxTH < 0) {
            maxTH = 0;
            start = i+1;
        }
    }
    cout<<"starting with : "<<start<<" ending with : "<<end<<endl;
    cout << maxi;
}


int main() {
    vector<int> ip = {1, 2, 3, -2, 5};
    findMaxSum(ip);
    return 0;
}