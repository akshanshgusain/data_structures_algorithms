//
// Created by Akshansh Gusain on 12/07/21.
//
#include<stdc++.h>

using namespace std;

// Time: O(N), Space: O(N)

bool solve(vector<int> arr1, vector<int> arr2, int m, int n) {
    unordered_set<int> s;

    for(auto it: arr1){
        s.insert(it);
    }

    int count = 0;
    for(int i = 0 ; i < n; i++){
        if(s.find(arr2[i]) != s.end()){
            count++;
        }
    }

    return count == n;
}

int main() {
    vector<int> arr1 = {11, 1, 13, 21, 3, 7};
    vector<int> arr2 = {11, 3, 7, 1};
    cout << solve(arr1, arr2, arr1.size(), arr2.size());
    return 0;
}
